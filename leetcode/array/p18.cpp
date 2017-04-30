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
	cout<<vsize<<endl;
}

vector<vector<int>> fourSum2(vector<int>& nums, int target)
{
	vector<vector<int>> vectorset;
	vector<int> res;
	set<vector<int>> vset;
	set<vector<int>>::iterator iset;

	unordered_map<int, list<pair<int,int>>> hmap; /* a list record all the pair */
	unordered_map<int, list<pair<int,int>>>::iterator liter;

	set<int> tempS;
	int i, j, k;
	int size = nums.size();
	int left;

	for (i = 0; i < size; i++) {
		for (j = i+1; j < size; j++) {
			pair<int,int> hi(i,j);
			hmap[nums[i]+nums[j]].push_back(hi);
		}
	}
	
	for (i = 0; i < size; i++) {
		for (j = i+1; j < size; j++) {

			liter = hmap.find(target-nums[i]-nums[j]);
			if (liter != hmap.end()) { /* Found such elements */

				list<pair<int,int>>& l = liter->second; /* Yan */

				for (auto piter = l.begin(); piter != l.end(); piter++) {
					tempS.clear();
					tempS.insert(i);tempS.insert(j);
					tempS.insert(piter->first);tempS.insert(piter->second);
					if (tempS.size() == 4) { /* Got it*/
						res.clear();
						res.push_back(nums[i]); res.push_back(nums[j]);
						res.push_back(nums[piter->first]);res.push_back(nums[piter->second]);
						sort(res.begin(), res.end());
						vset.insert(res);
					}
				}
			}
		}
	}

	for (iset = vset.begin(); 
			iset != vset.end(); iset++) {
		vectorset.push_back(*iset);	
	}
	return vectorset;
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> vectorset;
	vector<int> res;
	set<vector<int>> vset;
	set<vector<int>>::iterator iset;
	unordered_map<int, int> hmap;
	int i, j, k;
	int size = nums.size();
	int left;

	for (i = 0; i < size; i++)
		hmap[nums[i]] = i;
	
	for (i = 0; i < size; i++) {
		for (j = i+1; j < size; j++) {
			for (k = j+1; k < size; k++) {
				left = target - nums[i] - nums[j] - nums[k];	
				auto iter = hmap.find(left);
				if (iter != hmap.end() && iter->second > k) {
					res.clear();
					res.push_back(nums[i]);
					res.push_back(nums[j]);
					res.push_back(nums[k]);
					res.push_back(left);
					sort(res.begin(), res.end());
					vset.insert(res);
				}

			}
		}
	}

	for (iset = vset.begin(); 
			iset != vset.end(); iset++) {
		vectorset.push_back(*iset);	
	}
	return vectorset;
}
int main()
{
	int a[] = {1,0,-1,0,-2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<vector<int>> vset;
	vset = fourSum2(iv, 0);
	output2(vset);
	return 0;
}
