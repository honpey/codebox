#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

void output(vector<bool> &nums)
{
	vector<bool>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

void output2(vector<vector<int>> &nums) {
	int vsize, hsize;
	int i,j;

	vsize = nums.size();
	for (j = 0; j < vsize; j++) {
		hsize = nums[j].size();
		for (i = 0; i < hsize; i++) {
			cout<<nums[j][i]<<" ";
		}
		cout<<endl;
	}
}
void _subsets(vector<int> &nums, vector<vector<int>> &res,
				vector<int> &has, int curpos)
{
	int i;
	if (curpos >= nums.size()) {
		vector<int> temp;
		for (i = 0; i < nums.size(); i++) {
			if (has[i])
				temp.push_back(nums[i]);
		}
		res.push_back(temp);
		return;
	}
	//cout<<curpos<<endl;
	has[curpos]=0;
	_subsets(nums,res,has,curpos+1);
	has[curpos]=1;
	_subsets(nums,res,has,curpos+1);
	
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> has(nums.size(), 0);

	_subsets(nums,res,has,0);
	return res;
}

int main()
{
	
	int a[] = {1,2,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<vector<int>> vset;
	vset = subsets(iv);
	output2(vset);
	return 0;
}
