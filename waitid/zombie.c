#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int pid = 0;
    pid = fork();
    if (pid == 0) {
        printf("child: %d\n", getpid());
        int fd = open("./file2G", O_RDWR, NULL);
        if (fd < 0) {
            printf("fail to open %d\n", fd);
            exit(0);
        }
        exit(0);
    }
    printf("parent: %d\n", getpid());
    while(1);
	printf("hello wrold\n");
}
