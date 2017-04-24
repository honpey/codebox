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

void rotate(vector<int> & nums, int k)
{
	int n = nums.size();
	k = k % (nums.size());

	reverse(nums.begin(), nums.begin()+n-k);
	reverse(nums.begin()+n-k, nums.end());
	reverse(nums.begin(), nums.end());
	output(nums);
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
//	int a[] = {1,2,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	rotate(iv, 3);
//	cout<<missingNumber(iv)<<endl;
	return 0;
}
