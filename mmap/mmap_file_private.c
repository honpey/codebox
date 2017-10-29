#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char *ptr;

	fd = open("./testFile", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("open hi fail!\n");
		return -1;
	}
	ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_FILE, fd, 0);
	printf(".%x\n", ptr);
	ptr[0] = 'K';	
	munmap(ptr, 4096);
	close(fd);
}
