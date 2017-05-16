#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int subarraySum2(vector<int>&nums, int w)
{
	int i,j,k;
	int sum = 0;
	int count = 0;
	if (nums.size() == 0)
		return 0;
	for (i = 0; i < nums.size(); i++) {
		for (j = i; j < nums.size(); j++) {
			sum = 0;
			for (k = i; k <= j; k++) {
				sum += nums[k];
			}
			if (sum == w)
				count++;
		}
		
	}
	return count;
}

int	subarraySum(vector<int>& nums, int k)
{
	if (nums.size() <= 0)
		return 0;
	int i, fast=0, slow=0;
	int cursum, count=0;
	int min = nums[0], base;

	//sort(nums.begin(), nums.end());
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] < min)
			min = nums[i];
	}

	base = -1*min;
	for (i = 0; i < nums.size(); i++) {
		nums[i] += base;
	}
	output(nums);

	cursum = nums[0];

	while (true) {
		if (fast == nums.size() || slow == nums.size()) {
			while (slow < fast-1) {
				cursum -= nums[slow];
				if ((cursum -(fast-slow+1)*base) == k)
					count ++;
				slow++;
			}
			break;
		}
//		cout<<"<"<<slow<<","<<fast<<">"<<" "<<cursum-(fast-slow+1)*base<<endl;
		if ((cursum - (fast-slow+1)*base) == k)
		if ((cursum - (fast-slow+1)*base) == k) {
			if (++fast < nums.size())
				cursum += nums[fast];
			count++;
		} else if ((cursum - (fast-slow+1)*base) > k) {
			if (++slow < nums.size())
				cursum -= nums[slow-1];
		} else { /* cursum < k */
			if (++fast < nums.size())
				cursum += nums[fast];
		}

	}
	return count;
}

/*
 * subarraySum3竟然神奇地过了，就这么短短的几行代码
 * 答案来自这篇超像钓鱼网站的帖子：
 * http://www.bubuko.com/infodetail-2047495.html
 *
 */

int subarraySum3(vector<int> &nums, int k) {
	int sum = 0;
	int n = nums.size();
	map<int,int> m;
	int res = 0;

	for (int i = 0; i < n; i++) {
		m[sum]++;
		sum += nums[i];
		res += m[sum-k];
	}
	return res;
}

int subarraySum4(vector<int> &nums, int k) {
	int sum = 0;
	int n = nums.size();
	map<int, int> imap;
	int i;
	int res = 0;

	for (i = 0; i < n; i++) {
		imap[sum]++;
		sum += nums[i];
		res += imap[k-sum];
	}
	return res;
}

int main()
{
//	int a[] = {28,54,7,-70,22,65,-6};
//	int a[] = {-9,-7,1,16};
	int a[] = {1,1,1,4,2};
	
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	output(iv);
	cout<<subarraySum3(iv, 8)<<endl;
	return 0;
}
