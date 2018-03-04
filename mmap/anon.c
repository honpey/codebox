#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char *ptr;
	ptr = mmap(NULL, 4096*4, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0); /*  看下子进程是否能够访问 */
//	sleep(4);
	ptr[0] = 1;
	ptr[4096] = 1;
	ptr[4096*2] = 1;
	ptr[4096*3] = 1;
	sleep(2);
	munmap(ptr, 4096*2);
	ptr[4096*2] = 2;
	ptr[4096*3] =2;
	printf("anonymous down\n");
	/*
	pid = fork();
	if (pid > 0) { //parent
		printf("father is waiting\n");
	} else if (pid == 0) { //child
		ptr[0] = 2;
		ptr[4096] = 2;
	}
	*/

	while(1);

}
