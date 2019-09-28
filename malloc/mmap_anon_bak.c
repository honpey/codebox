#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main()
{
	int *addr[10];
	int pos = 0;
	int i = 0;
	printf("pid: %d\n", getpid());
next:
	printf("%d pos(%d)\n", i, pos);
	//0x7f0b0f7d2000
//	addr = (int *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	addr[pos] = (int *)mmap(0x7f0b0f7d2000, 4096*20, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (addr[pos] == NULL) {
		printf("Fail one time\n");
		goto next;
	}
	printf("%p\n", addr[pos]);
	addr[pos][0]=12;
	addr[pos][1000]=13;
	if (i++ < 1000) {
		sleep(2);
		pos++;
		if (pos == 5) {
			printf("free begin\n");
//			free(addr[0]);
//			free(addr[1]);
//			free(addr[2]);
//			free(addr[3]);
			printf("free end\n");
			pos = 0;
		}
		goto next;
	}

}
