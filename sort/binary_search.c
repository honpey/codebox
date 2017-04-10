#include <stdio.h>
#include <stdlib.h>

int BS(int array[], int len, int target)
{
	int start, end, middle;

	if (len <= 0)
		return -1;
	
	start = 0; end = len - 1;
	if (target < array[start] || target > array[end])
		goto not_found;
		
	while (start <= end) {
		middle = (start + end)/2;
		if (array[middle] == target) {
			printf("Found target:%d\n", target);
			return 0;
		}
		if (target < array[middle])
			end = middle - 1;
		else if (target > array[middle])
			start = middle + 1;
	}
not_found:
	printf("Not Found target:%d\n", target);
	return -1;
	
}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(array)/sizeof(int);

	BS(array, len, 6);
	BS(array, len, -1);
	BS(array, len, 5);
	BS(array, len, 10);
	BS(array, len, 8);
	BS(array, len, 1);
	
}
