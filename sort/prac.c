// To execute C, please define "int main()"
  int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,16};
  int len = sizeof(a)/sizeof(int);
  int i;
  
    printf("-1 VS %d\n", binary_search(a, len, 0));
    printf("9 VS %d\n", binary_search(a, len, 10));
    printf("10 VS %d\n", binary_search(a, len, 11));
    printf("14 VS %d\n", binary_search(a, len, 16));
    printf("-1 VS %d\n", binary_search(a, len, -1));
    printf("-1 VS %d\n", binary_search(a, len, 18));
  printf("End\n");

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void bubble_sort(int *a, int len)
{
  int i, j;
  int orderd = 1;
  
  if (len <= 0 || !a)
    return;
  for (i = len-1; i>= 0; i--) {
    orderd = 1;
    for (j = 0; j < i; j++) {
      if (a[j] > a[j+1]) {
        swap(&a[j], &a[j+1]);
        orderd = 0;
      }
    }
    if (orderd)
      return;
     
  }
  
}
int binary_search(int *a, int len, int target)
{
    int start, end, middle;
    if (!a || len <= 0)
        return;
    start = 0; end = len-1;
    
    if (target < a[0] || target > a[end])
        return -1;
    
    while (start <= end) {
        middle = (start+end)/2;
        if (a[middle] == target) {
            return middle;
        } else if (a[middle] < target) {
            start = middle + 1;
        } else
            end = middle - 1;
    }
    return -1;
  
}

