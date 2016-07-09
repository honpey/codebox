#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int i;
	printf("%d\n", getsid());
	setsid();
	printf("%d\n", getsid());
	printf("hello world\n");
}
