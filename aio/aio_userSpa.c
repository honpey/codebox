#include <stdio.h>
#include <string.h>
#include <aio.h>
#include <fcntl.h>
#include <errno.h>

#define BSZ 4096
#define NBUF 8

enum rwop {
	UNUSED = 0,
	READ_PENDING = 1,
	WRITE_PENDING = 2
};

struct buf {
	enum rwop op;
	int last;
	struct aiocb aiocb;
	unsigned char data[BSZ];
};

struct buf bufs[NBUF];

int main(int argc, char *argv[])
{
	int ifd, ofd, i, j, n, err, numop;
	struct stat sbuf;
	struct aiocb *aiolist[NBUF];
	off_t off=0;

	printf("SIGEV_NODE:%d\n", SIGEV_NONE);
	if (argc != 3) {
		printf("usage: rot13 infile outfile");
		return -1;
	}
	if ((ifd = open(argv[1], O_RDONLY)) < 0) {
		printf("cant't open %s", argv[1]);
		return -1;
	}
	if ((ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0) {
		printf("Cant't create %s", argv[2]);
		return -1;
	}
	if (fstat(ifd, &sbuf) < 0) {
		printf("fstat failed");
		return -1;
	}

	/* initialize the buffers */
	for (i = 0; i < NBUF; i++) {
		bufs[i].op = UNUSED;
		bufs[i].aiocb.aio_buf = bufs[i].data;
		bufs[i].aiocb.aio_sigevent.sigev_notify = SIGEV_NONE;
		aiolist[i] = NULL;
	}

	numop = 0;
	printf("sbuf.st_size:%d\n", sbuf.st_size);
	for (;;) {
		for (i = 0; i < 1; i++) {
			switch (bufs[i].op) {
				case UNUSED:
					/*
					 * Read from the input file if more data
					 * remains unread
					 */
					if (off < sbuf.st_size) {
						bufs[i].op = 1;
						bufs[i].aiocb.aio_fildes = ifd;
						bufs[i].aiocb.aio_offset = off;
						off += BSZ;
						if (off >= sbuf.st_size)
							bufs[i].last = 1;
						bufs[i].aiocb.aio_nbytes = BSZ;
						if (aio_read(&bufs[i].aiocb) < 0)
							printf("aio_read failed");
						printf("Start aio\n");
						aiolist[i] = &bufs[i].aiocb;
						numop++;
					}
				break;
				case READ_PENDING:
					if ((err = aio_error(&bufs[i].aiocb)) == EINPROGRESS) {
						printf("Pending\n");
						continue;
					}
					if (err != 0) {
						if (err == -1)	printf("aio_error failed");
						else printf("read failed");
					}

					if ((n = aio_return(&bufs[i].aiocb)) < 0) /* A read is complete; translate the buffer and write it */
						printf("aio_return failed");
					if (n != BSZ && !bufs[i].last)
						printf("short read (%d/%d)", n, BSZ);
					for (j = 0; j < n; j++)
						bufs[i].data[j] = bufs[i].data[j];
					bufs[i].op = WRITE_PENDING;
					bufs[i].aiocb.aio_fildes = ofd;
					bufs[i].aiocb.aio_nbytes = n;
					if (aio_write(&bufs[i].aiocb) < 0)
						printf("aio_write failed");
					/* retain out spot in aiolist */
					break;
				case WRITE_PENDING:
					if ((err = aio_error(&bufs[i].aiocb)) ==  EINPROGRESS)
						continue;
					if (err != 0) {
						if (err == -1)
							printf("aio_error failed");
						else
							printf("write failed");
					}
					/*
					 * A write is complete; mark the buffer as unused.
					 */
					if ((n = aio_return(&bufs[i].aiocb)) < 0)
						printf("aio_return failed");
					if (n != bufs[i].aiocb.aio_nbytes)
						printf("short write (%d/%d)", n, BSZ);
					aiolist[i] = NULL;
					bufs[i].op = UNUSED;
					numop--;
					break;
			printf("switch ..\n");

			} //switch 
		} // small for

		if (numop == 0) {
			if (off >= sbuf.st_size)
				break;
		} else {
			if (aio_suspend(aiolist, NBUF, NULL) < 0)
				printf("aio_suspend failed");
		}

	} // big for

		bufs[0].aiocb.aio_fildes = ofd;
		if (aio_fsync(O_SYNC, &bufs[0].aiocb) <0)
			printf("aio_fsync failed");
		exit(0);
	return 0;
}
