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

int search(vector<int>& nums, int target)
{
	int i, pos=-1;
	vector<int>::iterator iter;
	if (nums.size() == 0)
	return -1;
	for (i = 0; i < nums.size() - 1; i++) {
		if (nums[i] > nums[i+1]) {
			pos = i;
			break;
		}
	}
	/* split two part [0,pos][pos+1,size] */
	if (pos==-1) {
		iter = lower_bound(nums.begin(),nums.end(),target);
		if (*iter == target)
			return iter-nums.begin();
		return -1;
		
	}
	iter = lower_bound(nums.begin(),nums.begin()+pos+1,target);
	if (*iter == target)
		return iter-nums.begin();
	iter = lower_bound(nums.begin()+pos+1,nums.end(),target);
	if (*iter == target)
		return iter-nums.begin();
	return -1;
}

int main()
{
	int a[] = {1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<search(iv, 0)<<endl;
	return 0;
}
