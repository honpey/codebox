#include <iostream>
#include <vector>

using namespace std;

/*
	https://leetcode.com/problems/max-consecutive-ones/#/description
*/

int findMaxConOnes(vector<int>& nums)
{
	int len = nums.size();
	int i, curConsecutive = 0, max=-1;

	for (i = 0; i < len; i++) {
		if (nums[i] == 1) {
			curConsecutive ++;
		} else {
			if (curConsecutive > max)
				max = curConsecutive;
			curConsecutive = 0;
		}
		if (i == (len-1) && curConsecutive > max)
			max = curConsecutive;
		
	}
	return max;
}

int main()
{
	int a[] = {1,1,0,1,1,1};
	vector<int> iv(a,a+sizeof(a)/sizeof(int));
	cout<<findMaxConOnes(iv)<<endl;

	return 0;
}
