#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char *ptr;

	printf("alloc vm");
	ptr = malloc(4096*1024*100);

	for (i = 0; i < 1000*100; i++) {
		ptr[i*4096] = 1;
		if (!(i%2000)) {
			printf("%d\n", i);
		}
	}
	while(1);
}
