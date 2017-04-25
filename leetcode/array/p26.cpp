#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int removeDuplicates(vector<int>& nums)
{
	unordered_map<int,int> hmap;
	vector<int>::iterator iter;
	iter = unique(nums.begin(),nums.end());
	return iter-nums.begin();
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<removeDuplicates(iv)<<endl;
	return 0;
}
