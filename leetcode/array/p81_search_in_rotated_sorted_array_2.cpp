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

int removeDuplicates(vector<int>& nums)
{
	unordered_map<int,int> hmap;
	vector<int>::iterator iter;
	iter = unique(nums.begin(),nums.end());
	return iter-nums.begin();
}

int binary_search(vector<int>&nums, int s, int e, int target)
{
	int mid;
	while (s<=e) {
		mid = (s+e)/2;
		if (nums[mid] == target)
			return mid; 
		else if (nums[mid] > target)
			e = mid - 1;
		else
			s = mid + 1;
	}
	return -1;
}

bool search(vector<int>& nums, int target)
{
	int i = 0;
	if (nums.size() <= 0)
		return false;
	for (i = 0 ; i < nums.size()-1; i++) {
		if (nums[i+1] < nums[i])
			break; /* i is the privot */
	}
	if (binary_search(nums, 0, i, target) >= 0)
		return true;
	else if (binary_search(nums, i+1, nums.size()-1, target) >= 0)
		return true;
	return false;
}

int main()
{
	int a[] = {4,5,6,7,8,8,8,8,0,0,0,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<search(iv, 9)<<endl;
	return 0;
}
