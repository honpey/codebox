#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main() {
    void * handler = dlopen("./liba.so", RTLD_LAZY);
    int (*add) (int, int);
    int (*minus) (int, int);
    add = dlsym(handler, "add");
    minus = dlsym(handler, "minus");
    printf("%d\n", add(11, 23));
    printf("%d\n", minus(11, 24));
}
