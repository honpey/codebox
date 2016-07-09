#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("testFile", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("Wrong\n");
		return -1;
	}
	close(fd);
}
