#include <stdio.h>
#include <fcntl.h>

int funca() {

	int i;
	int fd;
	printf("pid: %d\n", getpid());
	fd = open("./testFileW", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("fail to open testFile\n");
		return -1;
	}
	char buffer[4096];
	for (i = 0; i < 4096; i++) {
		buffer[i] = 'a' + i%26;
	}
//	while (1) {
		write(fd, buffer, sizeof(buffer));
		fsync(fd);
//		sleep(10);
//	}
    close(fd);
    printf("write done\n");
    sleep(1000000);
}
int funb() {
    funca();
}

int func()
{
    funb();
}
int main()
{
    func();	
	return 1;
}
