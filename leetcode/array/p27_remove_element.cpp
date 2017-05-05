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

int removeElement(vector<int> & nums, int val)
{
	int pre, pos;
	for (pre=pos=0; pre < nums.size(); pre++) {
		if (nums[pre] != val) {
			nums[pos++] = nums[pre];
		}
	}
	nums.erase(nums.begin()+pos, nums.end());
	return nums.size();
	
}

int main()
{
	int a[] = {3,2,2,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<removeElement(iv, 3)<<endl;
	return 0;
}
