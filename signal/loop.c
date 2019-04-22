#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("%d\n", getpid());
    while(1) {
        sleep(1);
        printf("fs\n");
    }
}
