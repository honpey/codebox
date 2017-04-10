#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int isOdd(int a)
{
	return a&1?1:0;
}

void change(int *array, int len, int (*func)(int a))
{
	int start, end;
	
	if (len <= 0)
		return;

	start = 0, end = len-1;
	while (start < end) {
		while (start < end && func(array[start]))
			start++;
		while (start < end && !func(array[end]))
			end--;
		if (start < end)
			swap(&array[start], &array[end]);
	}

	
}
void print_array(int *a, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(array)/sizeof(int);
	change(array, len, isOdd);
	print_array(array, len);


}
