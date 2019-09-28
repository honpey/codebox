#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main()
{
    char *addr[10];
	int pos = 0;
	int i = 0;
	printf("pid: %d\n", getpid());
next:
	printf("%d pos(%d)\n", i, pos);
	//0x7f0b0f7d2000
	addr[pos] = (char *)mmap(NULL, 4096*10, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//	addr[pos] = (int *)mmap(0x7f0b0f7d2000, 4096*20, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//	addr[pos] = malloc(4096);
	if (addr[pos] == NULL) {
		printf("Fail one time\n");
		goto next;
	}
	printf("%p\n", addr[pos]);
	addr[pos][0]=12;
	addr[pos][4096]=12;
	addr[pos][4096*2]=12;
	addr[pos][4096*3]=12;
	addr[pos][4096*4]=12;
	addr[pos][4096*5]=12;
	addr[pos][4096*6]=12;
	addr[pos][4096*7]=12;
	addr[pos][1000]=13;
    /*
	if (i++ < 1000) {
		sleep(2);
		pos++;
		if (pos == 5) {
			printf("munmap begin\n");
			munmap(addr[0], 4096);
			munmap(addr[1], 4096);
			munmap(addr[2], 4096);
			munmap(addr[3], 4096);
			munmap(addr[4], 4096);
			printf("munmap end\n");
			pos = 0;
		}
		goto next;
	}
    */

}
