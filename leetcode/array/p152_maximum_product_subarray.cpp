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

int maxProduct(vector<int>& nums)
{
	int i;
	int nofneg = 0;
	int sum = 1;
	int firstnegPos = -1, lastnegPos = 0;
	int firneg = 0, lasneg = 0;
	int max = -1;;
	bool enter = false;

	if (nums.size() == 1)
		return nums[0];

	for (i = 0; i < nums.size(); i++) {
		if (nums[i] <= 0) {
			if (firstnegPos <= 0)
				firstnegPos = i; /* record the first */
			lastnegPos = i;
			if (nums[i] < 0)
				nofneg++;
		}
	}

	if ((nofneg & 0x1) == 0 && nofneg != 0) { /**/
		for (auto &n : nums) {
			sum *= n;
		}
		return sum;
	}
	sum = 1; enter = false;
	for (i = 0; i < firstnegPos; i++) {
		enter = true;
		sum *= nums[i];
	}
	if (enter && sum > max)
		max = sum;

	sum = 1; enter = false;
	cout<<firstnegPos<<" ";
	cout<<nums.size()<<endl;
	for (i = firstnegPos + 1; i < nums.size(); i++) {
		enter = true;
		sum *= nums[i];
	}
	if (enter && sum > max)
		max = sum;

	sum = 1; enter = false;
	for (i = 0; i < lastnegPos; i++) {
		enter = true;
		sum *= nums[i];
	}
	if (enter && sum > max)
		max = sum;

	sum = 1; enter = false;
	for (i = lastnegPos+1; i < nums.size(); i++) {
		enter = true;
		sum *= nums[i];
	}

	if (enter && sum > max)
		max = sum;

	return max;
}

int maxProduct1(vector<int> &nums)
{
	int i;
	int frontP = 1, backP = 1;
	int maxval = nums[0];
	for (i = 0; i < nums.size(); i++) {
		frontP = frontP * nums[i];
		backP = backP * nums[nums.size()-1-i];
		maxval = max(maxval, max(frontP, backP));
		if (frontP == 0) frontP = 1;
		if (backP == 0) backP = 1;
	}
	return maxval;
}

int main()
{
//	int a[] = {2,3,-2,4};
//	int a[] = {0,2};
	int a[] = {-2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<maxProduct(iv)<<endl;
	return 0;
}
