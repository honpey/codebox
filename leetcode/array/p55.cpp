#include <iostream>
#include <vector>

using namespace std;

void output(vector<bool> &nums)
{
	vector<bool>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}
static int _canJump(vector<int>& nums, int curp) {
	int size = nums.size();
	int i, can;
	if (curp == size-1)
		return true;
	if (curp > size-1)
		return false;
	if (nums[curp] == 0 && curp == size-1)
		return true;

	for (i = 1; i <= nums[curp]; i++) {
		can = _canJump(nums, curp+i);				
		if (can)
			return true;
	}
	return false;

	
}

bool canJump1(vector<int>& nums)
{
	if (nums.size() == 1 && nums[0] == 0)
		return true;
	return _canJump(nums, 0);
}

bool canJump(vector<int>& nums)
{
	int i,j,curpos;
	vector<bool> fuzhu(nums.size(), false);

	if (nums.size() == 0)
		return false;
	if (nums.size() == 1)
		return true;

	fuzhu[nums.size()-1] = true;
	/* backward to get the value */
	for (i = nums.size()-1; i>=0; i--) {  /* i:curpos */
//		for (j = 1; j <= nums[i]; j++) {
		for (j = nums[i]; j>=1; j--) {
			curpos = i+j;
			if (curpos <= nums.size()-1 && fuzhu[curpos] == true) {
				fuzhu[i] = true; /* which means there is a path from nums[i]*/
				break;
			}
		}
	}
	return fuzhu[0];

}

bool canJump2(vector<int>& nums)
{
	int i,j;
	int glofar = 0;
	int curfar = 0;
	for (i = 0; i < nums.size(); i++) {
		if (i > glofar)
			return false;

		curfar = nums[i] + i;
			
		if (curfar > glofar)
			glofar = curfar;
		if (glofar >= nums.size() - 1)
			return true;
	}
	return false;
}

int main()
{
	int a[] = {1,1,1,0};
//	int a[] = {4,0,4,2,2,0,1,3,3,0,3};
//	int a[] = {3,2,1,0,4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<canJump2(iv)<<endl;
	return 0;
}
