#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

void output2(vector<vector<int>> &rset)
{
	int vsize, hsize;
	int i, j;

	vsize = rset.size();
	for (j = 0; j < vsize; j++) {
		hsize = rset[j].size();
		for(i = 0; i < hsize; i++) {
			cout<<rset[j][i]<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> rset;
	vector<int> res;
	set<vector<int>> iset;
	set<vector<int>>::iterator isetiter;
	int i, j, k;
	int target;
	unordered_map<int,int> hmap;
	for (i = 0; i < nums.size(); i++)
		hmap[nums[i]] = i;
/*
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(),nums.end()), nums.end());
	output(nums);
*/

	for (i = 0; i < nums.size(); i++) {
		for (j = i+1; j < nums.size(); j++) {
			target = 0 - nums[i] - nums[j];
			auto val = hmap.find(target);
			if (val != hmap.end() &&
					val->second > j) { /**/
				res.clear();
				res.push_back(nums[i]);
				res.push_back(nums[j]);
				res.push_back(val->first);
				sort(res.begin(),res.end());
				iset.insert(res);
			} 
		}
	}
	for (isetiter = iset.begin(); 
				isetiter != iset.end(); isetiter++)
	{
		rset.push_back(*isetiter);
	}
	
	return rset;
	
}

int main()
{
	int a[] = {-1, 0, 1, 2, -1, -4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<vector<int>> rset;
	rset = threeSum(iv);
	output2(rset);
	
	return 0;
}
