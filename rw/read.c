#include <stdio.h>
#include <fcntl.h>

int main()
{
	int i;
	int fd;
	printf("pid: %d\n", getpid());
	sleep(15);
	fd = open("./testFile1", O_RDONLY, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("fail to open testFile\n");
		return -1;
	}
	char buffer[4096];
	for (i = 0; i < 3; i++) {
		read(fd, buffer, 4096);
		printf("hello reading one page\n");
		sleep(10);
	}
	return 1;
}
