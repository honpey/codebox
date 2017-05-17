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

int findMin(vector<int>& nums)
{
	int i;
	for (i = 0; i < nums.size()-1; i++) {
		if (nums[i] > nums[i+1])
			return nums[i+1];
	}
	return nums[0];
}

int main()
{
	int a[] = {0,1,2,4,5,6,7};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findMin(iv)<<endl;
	return 0;
}
