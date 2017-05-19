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
	int fast, slow;
	if (!nums.size())
		return 0;
	int cur = nums[0], no = 0;
	fast = 0; slow = 0;
	while (fast < nums.size()) {
		if (nums[fast] == cur) {
			no++;
		} else {
			cur = nums[fast]; no=1;
		}
		if (no <= 2)
			nums[slow++] = nums[fast++];
		else
			fast++;
	}
	return slow;
}

int main()
{
	int a[] = {1,1,1,2,2,2,2,2,2,2,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<removeDuplicates(iv)<<endl;
	return 0;
}
