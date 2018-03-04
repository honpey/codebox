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
	ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0); /*  看下子进程是否能够访问 */
	printf("ptr:%p\n", ptr);
	pid = fork();
	if (pid > 0) { /* parent thread */
		printf("I'm parent, my son is %d, mmap success\n", pid);
		for (i = 0; i < 1; i++) {
			ptr[1] = 'A';
			ptr[2] = 'L'; 
			ptr[3] = 'I';
			printf("parent write done\n");
			printf("ptr[1]=%c\n", ptr[1]);
			printf("ptr[2]=%c\n", ptr[2]);
		}
		sleep(10);

	} else if (pid == 0) { /* child thread */
		sleep(2);
		printf("ptr[1]=%c\n", ptr[1]);
		printf("ptr[2]=%c\n", ptr[2]);
		printf("child read done\n");
	} else { /* fault condition */

	}


	close(fd);

}
