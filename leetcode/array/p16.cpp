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

int threeSum(vector<int>& nums, int target)
{
	int i, j, k;
	int expect;
	int diff, min_diff = 0x0fffffff;
	vector<int>::iterator iter;
	unordered_map<int,int> hmap;

	sort(nums.begin(), nums.end());
	/*hashmap to check if it is i & j*/
	for (i = 0; i < nums.size(); i++) {
		hmap[nums[i]] = i;
	}

	/* How to skip i and j */
	for (i = 0; i < nums.size(); i++) {
		for (j = i+1; j < nums.size(); j++) {
			expect = target - nums[i] - nums[j];
			auto aiter = hmap.find(expect);
			/* We really do NOT find such an element */
			/* try to found the target */

			if (aiter != hmap.end() && aiter->second > j) {
				return target;
			} else /*if (aiter == hmap.end() || aiter->) BUG fix*/ {
				if (nums.begin() + j + 1 < nums.end()) {
					iter = lower_bound(nums.begin() + j + 1,
								nums.end(), expect);
					if (iter == nums.end())
			//			diff = expect - nums[nums.size()-1];
						diff = nums[nums.size()-1] - expect; /*bugfix*/
					else
						diff = *iter - expect;
					if (abs(diff) < abs(min_diff)) {
						min_diff = diff;
						cout<<min_diff<<endl;
					}

					if(iter != nums.begin()+j+1) { /* we should check the begin() part as well */
						diff = *(iter-1) - expect;
						if (abs(diff) < abs(min_diff)) {
							min_diff = diff;
						}
					}

				}
			} // else if
		}
	}
	return target + min_diff; /* fix bug*/
}

int main()
{
//	int a[] = {1,1,1,0};
	int a[] = {-1, 0, 1, 1, 55};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	int res= threeSum(iv, 3);
	cout<<"res:"<<res<<endl;
	
	return 0;
}
