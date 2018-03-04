#include <stdio.h>
#include <stdlib.h>

void func()
{
	int i = 0;
	while (i++ < 40000000);
}

void funb()
{
	int i = 0;
	while (i++ < 20000000);
	func();
}

void funa()
{
	int i = 0;
	while (i++ < 10000000);
	funb();
}
int main()
{
	printf("%d\n", getpid());
	while (1)
		funa();
	printf("hello world");
}
