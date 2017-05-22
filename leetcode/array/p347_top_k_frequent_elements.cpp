#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

vector<int> topKfrequent(vector<int>& nums, int k)
{
	int size = nums.size();
	deque<int> hmap[size+1];
	vector<int> res;
	int i, cur, curcount = 0;

	sort(nums.begin(), nums.end());
	cur = nums[0]; curcount = 0;
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] == cur) {
			curcount++;
		} else {
			hmap[curcount].push_back(cur);
			cur = nums[i]; curcount = 1;
		}
	}
	hmap[curcount].push_back(cur);

	for (i = size; i >= 0 && k > 0; i--) {
		while (!hmap[i].empty() && k-- > 0) {
			res.push_back(hmap[i].front());
			hmap[i].pop_front();
			hmap[i].size();
		}
	}
		
	return res;
}

int main()
{
	int a[] = {1,1,1,2,2,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	res = topKfrequent(iv, 4);
	output(res);
	return 0;
}
