#include <iostream>
#include <vector>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int searchInsert(vector<int>& nums, int target)
{
	int i;
	int size = nums.size();
	if (size==0)
		return 0;

	if (target < nums[0])
		return 0;
	if (target > nums[size-1])
		return size;

	for (i = 0; i < size; i++) {
		if (target == nums[i])	
			return i;
		if (i < size-1) {
			if (target < nums[i+1])
				return i+1;
		}
	}
	return -1;
}

int main()
{
	int a[] = {1,3,5,6};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<searchInsert(iv, 5)<<endl;
	cout<<searchInsert(iv, 2)<<endl;
	cout<<searchInsert(iv, 7)<<endl;
	cout<<searchInsert(iv, 0)<<endl;
	return 0;
}
