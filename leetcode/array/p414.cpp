#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int thirdMax(vector<int> &nums)
{
	int size = nums.size();
	int i;
	if (size <= 0)
		return -1;
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	size = nums.size();
	if (size <= 3)
		return nums[size-1];
	return nums[size-3];
}
int main()
{
	int a[] = {3,2,2,2,2,2,2,2,1};
	vector<int> ia(a, a+sizeof(a)/sizeof(int));
	cout<<"Count:"<<thirdMax(ia)<<endl;
	
}
