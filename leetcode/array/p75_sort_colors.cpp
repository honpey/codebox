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

void sortColors(vector<int>& nums)
{
	int i;	
	int count0=0, count1=0, count2=0;
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) count0++;
		else if (nums[i] == 1) count1++;
		else if (nums[i] == 2) count2++;
	}
	for (i = 0; i < count0; i++)
		nums[i] = 0;
	for (; i < count0+count1; i++)
		nums[i] = 1;
	for (; i < count0+count1+count2; i++)
		nums[i] = 2;
}

int main()
{
	int a[] = {0,1,2,0,0,0,0,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	output(iv);
	sortColors(iv);
	output(iv);
	return 0;
}
