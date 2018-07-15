#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <stdio.h>

int funcc(int a) {
//    sleep(1000);
    int ret = 0;
    while(ret++<1000000);
    ret = getpid();
    printf("%d\n", ret);
    return ret;
}
int funcb(int b) {
    funcc(b);
}
int funca(int a) {
    funcb(a);
}
int add(int a,int b)
{
        int i, j;
        i = a+b;
        j = funca(a);
        return i*j;
}
int print(int i, ...)
{
        int j,a,b;
        a = 23; // 0x17 = 23
        b = 39; // 0x27 = 39
        j = add(a,b);
        return j;
}
void main(void)
{
//        print(2,3);
        printf("hello world: %d\n", print(2,3));
        return 0;
}
