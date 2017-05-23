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

int singleNumber(vector<int>& nums)
{
	int i;
	int sum = 0;
	for (i = 0; i < nums.size(); i++)
		sum ^= nums[i];
	return sum;
}

int main()
{
	int a[] = {1,2,2,9,8,7,1,7,8,-1,-2,9,-1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<singleNumber(iv)<<endl;
	return 0;
}
