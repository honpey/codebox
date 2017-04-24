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

bool containsDuplicate(vector<int> & nums)
{
	int i;
	unordered_map<int,int> hmap;
	for (i = 0; i<nums.size(); i++) {
		if (hmap[nums[i]] != 0)
			return true;
		hmap[nums[i]] = 1;
	}
	return false;
	
}

int main()
{
	int a[] = {0,1,3,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
//	cout<<missingNumber(iv)<<endl;
	return 0;
}
