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

int majorityEle(vector<int>& nums)
{
	unordered_map<int,int> hmap;
	int i;
	for (i = 0; i <nums.size(); i++) {
		hmap[nums[i]]++;
	}
	for (auto it = hmap.begin(); it != hmap.end(); it++) {
		if (it->second >= (nums.size()/2)) {
			return it->first;
		}
	}
	return -1;
	
	
}

int main()
{
	int a[] = {-1,-1,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<majorityEle(iv)<<endl;
	return 0;
}
