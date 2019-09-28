#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/fcntl.h>

int main()
{
	char *addr;
	int pos = 0;
	int i = 0;
	int fd = 0;
	printf("pid: %d\n", getpid());
	fd = open("./testFile", O_RDWR);
	if (fd < 0) {
		printf("wrong file\n");
		return -1;
	}
next:
	addr = (char *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FILE, fd, 0);
	if (addr == NULL) {
		printf("Fail one time\n");
		goto next;
	}
	if (addr == 0xffffffffffffffff) {
		printf("BAd address\n");
		goto next;
	}
	printf("%p\n", addr);
	addr[i%4000]='k'+(i%10);
	if (i++ < 1000) {
		sleep(2);
		pos++;
		goto next;
	}
	munmap(addr, 4096);
	close(fd);
}
