#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap %d and %d\n", *a, *b);
}

int BiggerThan(int a, int target)
{
	return a>target;
}
int isOdd(int a)
{
	return a&1?1:0;
}

void fastsort(int *array, int start, int end,
				int (*func)(int a, int target))
{
	int pos, target;

	if (start >= end)
		return;

	target = array[start];
	start++;

	while (start < end) {
		while (start < end && !func(array[start], target))
			start++;
		while (start < end && func(array[end], target))
			end--;
		if (start < end) {
			swap(&array[start], &array[end]);
			start++; end--;
		}

		if (start == end) {
			swap(&array[start], &array[0]);
			pos = start;
			break;
		} else {
			swap(&array[end], &array[0]);
			pos = end;
			break;
		}
	}

	printf("pos:%d,a[pos]:%d\n", pos, array[pos]);
	fastsort(array, start, pos-1, func);
	fastsort(array, pos+1, end, func);
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
	int array[] = {4,9,1,2,3,8,6,7};
	int len = sizeof(array)/sizeof(int);
	fastsort(array, 0, len-1, BiggerThan); 
	print_array(array, len);
	return -1;
}
