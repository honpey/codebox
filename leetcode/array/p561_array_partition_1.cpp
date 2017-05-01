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

int arrayPairSum(vector<int>& nums)
{
	int size;
	int sum = 0, i;
	size= nums.size();
	if (size < 0)
		return 0;

	sort(nums.begin(), nums.end());
	for (i = 0; i < size; i+=2) {
		sum += nums[i];
	}
	return sum;
	
}

int main()
{
	int a[] = {1,4,3,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<arrayPairSum(iv)<<endl;
	return 0;
}
