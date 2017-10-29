#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main()
{
	int i;
	char *addr;
	i = 0;
	unsigned long mask = 1 << 2;
	int pid = getpid();
//	sched_setaffinity(pid, sizeof(unsigned long), &mask);
	printf("pid: %d\n", getpid());
//	sleep(20);
next:
	printf("%d\n", i);
	addr = malloc(4096*64);
	if (addr == NULL) {
		printf("Fail one time\n");
		goto next;
	}
	printf("%p\n", addr);
	for (int j = 0; j < 64; j++) {
		addr[j*4096] =12;
	}
	addr[0]=12;
	if (i++ < 1000) {
		sleep(2);
		goto next;
	}

}
