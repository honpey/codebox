#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char *ptr;
	ptr = mmap(NULL, 4096*4, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0); /*  看下子进程是否能够访问 */
	sleep(4);
	ptr[0] = 1;
	ptr[4096] = 1;
	ptr[4096*2] = 1;
	ptr[4096*3] = 1;
	printf("anonymous down\n");

	while(1);

}
