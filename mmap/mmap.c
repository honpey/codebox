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
	ptr = mmap(NULL, 40960000, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0); /*  看下子进程是否能够访问 */
	printf("ptr:%p\n", ptr);
	pid = fork();
	if (pid > 0) { /* parent thread */
		printf("I'm parent(%d), my son is %d, mmap success\n", getpid(), pid);
		for (i = 0; i < 40960000/4096; i++) {
            char *curptr = ptr + i*4096;
			curptr[1] = 'A';
			curptr[2] = 'L'; 
			curptr[3] = 'I';
			printf("parent write done :%d %d\n", i, i*4096);
			printf("ptr[1]=%c\n", curptr[1]);
			printf("ptr[2]=%c\n", curptr[2]);
		}
        sleep(10000);
		sleep(10);

	} else if (pid == 0) { /* child thread */
		sleep(2);
		printf("ptr[1]=%c\n", ptr[1]);
		printf("ptr[2]=%c\n", ptr[2]);
		printf("child(%d) read done\n", getpid());
        sleep(100000);
	} else { /* fault condition */

	}


	close(fd);

}
