#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char buffer[4096];
	char *ptr;

	fd = open("./hi", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("open hi fail!\n");
		return -1;
	}
	for (i = 0; i < 4096; i++) {
		if (i % 26 == 25)
			buffer[i] = '\n';
		else
			buffer[i] = 'a' + i%26;
	}
/*
	write(fd, buffer, sizeof(buffer));
	write(fd, buffer, sizeof(buffer));
	write(fd, buffer, sizeof(buffer));
*/
	pid = fork();
	if (pid > 0) { /* parent thread */
		printf(" mmap test\n");
		ptr = mmap(NULL, 4096 * 3, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
		if (ptr == MAP_FAILED) {
			perror("mmap wrror");
			close(fd);
			return -1;
		}
//		sleep(10);
		printf("I'm parent, my son is %d, mmap success\n", pid);
		printf("To test If write will enter when mmap\n");
		printf("Start writting\n");
		for (i = 0; i < 1; i++) {
			ptr[1] = 'A';
			ptr[2] = 'B';
			ptr[4096+1] = 'C';
			ptr[4096+2] = 'C';
			ptr[4096 * 2+1] = 'C';
			ptr[4096 * 2+2] = 'C';
			if (i%1000 == 999)
				sleep(10);
			printf("* ");

		}
		printf("End writting\n");

	} else if (pid == 0) { /* child thread */
		/*
		sleep(5);
		printf("I'm child, ready to Write\n");
		for (i = 0; i < 4096; i++) {
			if (i % 3 == 0)
				lseek(fd, 0, SEEK_SET);
			if (i % 3 == 1)
				lseek(fd, 4096, SEEK_SET);
			if (i % 3 == 2) 
				lseek(fd, 4096 * 2, SEEK_SET);
			write(fd, buffer, sizeof(buffer));
		}
*/
	} else { /* fault condition */

	}


	close(fd);

}
