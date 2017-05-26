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

int findLHS(vector<int>& nums)
{
	int i, max = 0;
	unordered_map<int,int> hmap;
	if (nums.size() == 0)
		return 0;
	for (i = 0; i < nums.size(); i++)
		hmap[nums[i]]++;
	for (i = 0; i < nums.size(); i++) {
		if (!hmap[nums[i]-1])
			continue;
		int cursum = hmap[nums[i]] + hmap[nums[i]-1];
		if (cursum > max)
			max = cursum;
	}

	return max;
}

int main()
{
	int a[] = {1,1,1,1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findLHS(iv)<<endl;
	return 0;
}
