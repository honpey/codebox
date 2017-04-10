#include <stdio.h>
#include <stdlib.h>

int partition(int pArr[],int low,int high)
{
	int pivot = pArr[low];

	while (low < high) {
		while(low < high && pArr[high] >= pivot) high--;
	 		pArr[low] = pArr[high];
	 	while(low < high && pArr[low] <= pivot) low++;
			pArr[high] = pArr[low];
	}
	pArr[low] = pivot;
	return low;
}
void Quick_sort(int pArr[],int low,int high)
{
	int keyPos = 0;
 	if (low < high)
	{
		keyPos = partition(pArr,low,high);
		Quick_sort(pArr,low,keyPos-1);
		Quick_sort(pArr,keyPos+1,high);
 	}
}
int main(int argc,char**argv)
{
//	int arr[] = {49,38,65,97,76,13,27,49};
	int arr[] = {4,9,1,2,3,8,6,7,4,4,4,4,5};
	int len = sizeof(arr)/sizeof(int);
	int i;

	Quick_sort(arr, 0, len-1);

	for(i = 0; i < len; i++)
	{
 		 printf("%2d ",arr[i]);
 	}
 	return 0;
}
