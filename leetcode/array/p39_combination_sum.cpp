#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <list>

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
	cout<<"Total "<<vsize<<" entries:"<<endl;
	for (j = 0; j < vsize; j++) {
		hsize = nums[j].size();
		for (i = 0; i < hsize; i++) {
			cout<<nums[j][i]<<" ";
		}
		cout<<endl;
	}
}

void _combinationSum(vector<int>& nums, int target, 
			int curpos, int curvalue, vector<int> &temp,
			set<vector<int>> &vsets)
{
	int i,j;

	if (curvalue == target) { /* means i*/
//		sort(temp.begin(), temp.end());
//		output(temp);
		vsets.insert(temp);
		
		return;
	}
	if (curpos >= nums.size())
		return;
	if (curvalue > target)
		return; 
	int preloop=0, postloop=0;
	for (i = 0; i <= target/nums[curpos]; i++) {
		if (nums[curpos] == 3/* && i <= 4*/) {
/*			cout<<"Pre3:"<<curvalue<<" "<<i*nums[curpos]<<endl;
			*/
//			output(temp);
		}
		_combinationSum(nums, target, 
				curpos+1, curvalue + i*nums[curpos], temp, vsets);
		temp.push_back(nums[curpos]);
	}
	for (i = 0; i <= target/nums[curpos]; i++) {
		temp.pop_back();
	}
	if (curpos == 2)
		output(temp);
		//cout<<"----------------"<<endl;
}

vector<vector<int>> combinationSum(vector<int>& nums, int target)
{
	set<vector<int>> vsets;
	set<vector<int>>::iterator iset;
	vector<vector<int>> vecs;
	vector<int> temp;
	int i;

	_combinationSum(nums,target,0,0,temp,vsets);
	for (iset = vsets.begin(); iset != vsets.end(); iset++) {
		vecs.push_back(*iset);
	}

	return vecs;
}
int main()
{
	int a[] = {7,3,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<vector<int>> vset;
	vset = combinationSum(iv, 18);
	output2(vset);
	return 0;
}
