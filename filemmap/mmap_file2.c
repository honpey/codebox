#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//#include "csapp.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void mmapcopy(int fd, int size)
{
	char *bufp;
	//void * start_addr = 0;
	//start_addr = (void *)0x80000;
//	bufp = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	bufp = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
	if (bufp == (void *)-1)
		fprintf(stderr, "mmap: %s\n", strerror(errno));
	
	memcpy(bufp, "Linuxdd", 7);
	
	write(1, bufp, size);
	munmap(bufp, size);
	return;
}
int main(int argc, char **argv)
{
	struct stat stat;
	if (argc != 2)
		{
			printf("error.\n");
			exit(0);
		}
		//int fd = atoi(*argv[1]);
	//mmap()
	int fd = open(argv[1], O_RDWR, 0);  // O_RDWR 才能被讀寫。
	if (fd < 0)
		fprintf(stderr, "open: %s\n", strerror(errno));  // 使用異常檢查是個好習慣， 他可以幫助程序員迅速定位出錯的地方！
	fstat(fd, &stat);
	mmapcopy(fd, stat.st_size);
	//while(1);
	close(fd);
	exit(0);
}
