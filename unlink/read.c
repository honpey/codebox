#include <stdio.h>
#include <fcntl.h>

int main()
{
	int i;
	int fd;
	fd = open("./testFile", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("fail to open testFile\n");
		return -1;
	}
	char buffer[4096];
	for (i = 0; i < 4096; i++) {
		buffer[i] = 'a' + i%26;
	}
	write(fd, buffer, sizeof(buffer));
	sleep(30);
	write(fd, buffer, sizeof(buffer));
	return 1;
}
