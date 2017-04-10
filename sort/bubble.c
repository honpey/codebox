#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int bubble_sort(int *a, int len)
{
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = len; j > 0; j++) {
			
			
		}
	}
}
int main()
{
	int a[] = {1,2,7,4,3,8};
	int len = sizeof(a)/sizeof(int);
	printf("len:%d\n", len);
	printf("sizeof(a):%d\n", sizeof(a));
	printf("sizeof(int):%d\n", sizeof(int));
	printf("hello world\n");
}
