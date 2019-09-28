#include <stdio.h>
#include <stdlib.h>

int fund() {
    while(1) {
        sleep(100);
    }
}

int func() {
    fund();
}
int funb() {
    func();
}
int funa() {
    funb();
}
int main() {
    printf("%d\n", getpid());
    funa();
}
