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

int maxSubArray(vector<int> & nums)
{
	int max, i, gmax;
	int cur;
	max = gmax = nums[0];
	for (i = 1; i < nums.size(); i++) {
		cur = nums[i] + max;
		if (nums[i] + max > nums[i])
			max = nums[i]+max;
		else
			max = nums[i];
		if (max > gmax)
			gmax = max;
	}
	return gmax;
	
}

int main()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<maxSubArray(iv)<<endl;
	return 0;
}
