#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int findPeakElement(vector<int>& nums)
{
	int i;
	if (nums.size() == 1)
		return 0;
	if (nums[0] > nums[1])
		return 0;
	if (nums[nums.size()-1] > nums[nums.size()-2])
		return nums.size()-1;
	for (i = 1; i < nums.size()-1; i++) {
		if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
			return i;
	}
}

int main()
{
	int a[] = {1,2,3,1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findPeakElement(iv)<<endl;
	return 0;
}
