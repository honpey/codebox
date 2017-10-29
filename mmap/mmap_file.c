#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	int i, fd, pid;
	char buffer[4096];
	char *ptr;

	fd = open("./hi", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("open hi fail!\n");
		return -1;
	}
	for (i = 0; i < 4096; i++) {
		if (i % 26 == 25)
			buffer[i] = '\n';
		else
			buffer[i] = 'a' + i%26;
	}
next:
	ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_FILE, fd, 0); /*  看下子进程是否能够访问 */
	printf(".%x\n", ptr);
	ptr[0] = 'K';	
	goto next;


	close(fd);

}
