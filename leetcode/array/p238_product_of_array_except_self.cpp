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

vector<int> productExceptSelf(vector<int>& nums)
{
	int i;
	vector<int> res(nums.size());
	vector<int> pre(nums.size());
	vector<int> pos(nums.size());
	
	pre[0] = 1;
	pos[nums.size()-1] = 1;
	for (i = 1; i < nums.size(); i++) {
		pre[i] = pre[i-1]*nums[i-1];
		pos[nums.size()-1-i] = pos[nums.size()-i]*nums[nums.size()-i];
	}
	for (i = 0; i < nums.size(); i++) {
		res[i] = pre[i] * pos[i];
	}
	return res;

	
}

/*
vector<int> productExceptSelf2(vector<int>& nums)
{
	int i;
	vector<int> res(nums.size());
	
	res[0] = 1;
	for (i = 1; i < nums.size(); i++) {
		res[i] = res[i-1]*nums[i-1];
	}
	for (i = nums.size()-2; i >= 0; i--) {
		res[i] = res[i+1]*nums[i+1];
	}
	return res;
}
*/
int main()
{
	int a[] = {1,2,3,4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	output(iv);
	res = productExceptSelf(iv);
	output(res);
	return 0;
}
