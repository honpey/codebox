#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int,int> hmap;
	vector<int> res;
	int i;

	for (i = 0; i < nums.size(); i++) {
		hmap[nums[i]] = i;
	}
	for (i = 0; i < nums.size(); i++) {
		auto it = hmap.find(target-nums[i]);
		if (it != hmap.end() && i != it->second) {
			res.push_back(i);
			res.push_back(it->second);
			return res;
		}
	}
	return res;
}

int main()
{
	int a[] = {3,2,4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	res = twoSum(iv, 6);
	output(res);
	return 0;
}