#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int findPairs2(vector<int>& nums, int k)
{
	int i;
	int res;

	if (k < 0)
		return 0;
	unordered_map<int,int> m;
	for (i = 0; i < nums.size(); i++) {
		++m[nums[i]];
	}
	res = 0;
	if (k != 0) {
		for (auto it = m.begin(); it != m.end(); it++) {
			if (m.find(it->first+k) != m.end())
				++res;
		}
	} else {
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second > 1) {
				++res;
			}
		}
	}
	return res;
}

int main()
{
//	int a[] = {3,1,4,1,5};
	int count;
	int a[] = {1,3,1,5,4};
//	int len = sizeof(a)/sizeof(int);
	vector<int> iv(a,a+sizeof(a)/sizeof(int));
//	findPairs(iv,2);
//	findPairs(iv,1);
	count = findPairs2(iv,0);
	cout<<"Count:"<<count<<endl;
}
