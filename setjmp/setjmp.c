#include <setjmp.h>
#include <stdio.h>

jmp_buf jmpbuffer;
funcB()
{
	longjmp(jmpbuffer, 0x0);
	printf("funcB\n");
}
void funcA()
{
	funcB();
	printf("funcA\n");
}
int main()
{
	int ret;
	if ((ret = setjmp(jmpbuffer)) != 0) {
		printf("error:%d\n", ret);
		sleep(2);
	}

	funcA();
}
