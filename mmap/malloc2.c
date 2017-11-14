#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char *ptr;

	printf("alloc vm\n");
	int ii = 1024*100;
next:
	if (ii-- < 0)
		goto out;
	else {
//		if (ii % 10000 == 2)
	//	printf("ii: %d\n", ii);
	//	printf("On: %d\n", 100 - ii * 100 / 1024*100);
	}
	ptr = malloc(4096);
	
	ptr[0] = 1;
	goto next;
out:
	printf("write done\n");
	while(1);
}
