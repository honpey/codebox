#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <aio.h>
#include <errno.h>

struct honpey_buf {
	struct aiocb acb;
 	unsigned char buf[4096];
};
int hon_aio_read(struct honpey_buf *hb, int fd)
{
	int ret;
	size_t n;
	memset(hb, 0, sizeof(struct honpey_buf));
	printf("sizeof(honpey_buf):%d\n", sizeof(struct honpey_buf));
	hb->acb.aio_fildes = fd;
	hb->acb.aio_offset = 0;
	hb->acb.aio_buf = hb->buf;
	hb->acb.aio_nbytes = 4096;

	ret = aio_read(&hb->acb);
	if (ret < 0) {
		printf("aio_read wrong\n");
		return -1;
	}

retry:
	ret = aio_error(&hb->acb);
	if (ret == EINPROGRESS) {
		goto retry;
	}
	n = aio_return(&hb->acb);
	if (n < 0) {
		printf("failt to \n");
		return -1;
	}
	printf("------\n");
	printf("%s\n", hb->buf);
	printf("___________\n");
	return 0;
}

int main(int argc, char *argv[])
{
	int i;
	int fd;
	struct honpey_buf hb;
	int ret;
	for (i = 0; i < argc; i++) {
		printf("%d:%s\n", i, argv[i]);
	}
	fd = open("./test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("fail to open file\n");
		return -1;
	}
	ret = hon_aio_read(&hb, fd);


}
