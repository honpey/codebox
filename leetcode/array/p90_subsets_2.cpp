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
	cout<<vsize<<endl;
}
void _subsetWithDup(vector<int>& hasno, int pos,
							set<vector<int>>& iset, vector<int>& nums)
{
	if (pos >= hasno.size()) {
		vector<int> temp;
		int i;
		for (i = 0; i < hasno.size(); i++) {
			if (hasno[i])
				temp.push_back(nums[i]);
		}
		sort(temp.begin(), temp.end());
		iset.insert(temp);
		return;
	}
	hasno[pos] = 1;
	_subsetWithDup(hasno, pos+1, iset, nums);
	hasno[pos] = 0;
	_subsetWithDup(hasno, pos+1, iset, nums);
}

vector<vector<int>> subsetWithDup(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> has(nums.size());
	set<vector<int>> iset;
	_subsetWithDup(has, 0, iset, nums);
	set<vector<int>>::iterator iter;
	for (iter = iset.begin(); iter != iset.end(); iter++) {
		res.push_back(*iter);
	}
	return res;
}

int main()
{
	int a[] = {1,9,8,3,-1,0};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));

	vector<vector<int>> res;
	res = subsetWithDup(iv);
	output2(res);
	
	return 0;
}
