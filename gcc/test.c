#include <stdio.h>

static inline int retValue() {
    return 1011;
}
int func(int a, int b) {
    return (a-b)?:retValue();
}
int main()
{
    printf("%d\n", func(11, 11));
    return 1;
}
