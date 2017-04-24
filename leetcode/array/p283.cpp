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
void moveZeros(vector<int> &nums)
{
	int i, pos = 0;

	for (i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[pos++] = nums[i];
		}
	}

	for (; pos < nums.size(); pos++) {
		nums[pos] = 0;
	}
	
	output(nums);
}

int main()
{
	int a[] = {0,1,0,3,12};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	moveZeros(iv);
	return 0;
}
