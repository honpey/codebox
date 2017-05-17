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

/* 由于数组都是有序的，能不能通过快慢指针呢 */
int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.size() <= 0)
		return 0;
	if (s > accumulate(nums.begin(), nums.end(),0))
		return 0;
	int min = nums.size();	
	int cursum = nums[0];
	int fast = 0, slow = 0;
	while (fast < nums.size()) {
		if (cursum >= s && (fast-slow+1) <= min) {
			min = (fast-slow+1);
		}
		if (cursum < s) {
			fast++; 
			if (fast < nums.size())
				cursum += nums[fast];
		} else if (cursum >= s) {
			cursum -= nums[slow]; 
			if (slow < fast)
				slow++;
		}
	}
	return min;
}

int main()
{
	int a[] = {2,3,1,2,4,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	output(iv);
	cout<<minSubArrayLen(100, iv)<<endl;
	return 0;
}
