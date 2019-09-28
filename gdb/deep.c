#include <stdio.h>
int funca() {
//    printf("a\n");
    funcb();
}

int funcb() {
 //   printf("b\n");
    funcc();
}

int funcc() {
  //  printf("c\n");
    funcd();
}

int funcd() {
   // printf("d\n");
    int i = 0;
    while (i++ < 1000000000);
    sleep(1000);
}

int main()
{
    printf("%d\n", getpid());
    while (1)
    funca();
}
