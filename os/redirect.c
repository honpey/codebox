#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("./test", O_CREAT|O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd, 1);
	printf("hello world\n");
	close(fd);
}
