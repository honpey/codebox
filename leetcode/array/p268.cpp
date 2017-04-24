#include <iostream>
#include <vector>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int missingNumber(vector<int>& nums)
{
	int i;
	int size = nums.size();
	int sum = (1+size)*size/2;
	for (i = 0; i < size; i++) {
		sum = sum - nums[i];
	}
	return sum;
}

int main()
{
	int a[] = {0,1,3,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<missingNumber(iv)<<endl;
	return 0;
}
