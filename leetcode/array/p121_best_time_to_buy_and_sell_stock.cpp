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

int maxProfit(vector<int>& nums)
{
	int i, j;
	int size = nums.size();
	int max = 0;
	for (i = 0; i < size; i++) {
		for (j = i+1; j < size; j++) {
			if (nums[j] - nums[i] > max)
				max = nums[j] - nums[i];
		}
	}
	return max;
	
}

int main()
{
	int a[] = {1,4,3,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<maxProfit(iv)<<endl;
	return 0;
}
