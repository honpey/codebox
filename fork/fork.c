#include <stdio.h>

int main() {
    int pid = fork();
    if (pid > 0) {
        printf("parent: %d\n", getpid());
    } else {
        printf("child: %d\n", getpid());
    }
    while(1);
}
