#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(vector<int> a)
{
	int i;
	for (i = 0; i < a.size(); i++) {
		cout<<a[i]<<" ";
	}	
	cout<<endl;
}
vector<int> findDis(vector<int> &nums) {
	vector<int> res;	
	int i, curval, temp;
	for (i = 0; i < nums.size(); i++) {
		curval = nums[i];
		if (nums[curval-1] != curval) {
			temp = nums[curval-1];
			nums[curval-1] = nums[i];
			nums[i] = temp;

			i--;
		} 
	}
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] != (i+1))
			res.push_back(i+1);
	}
	return res;
}
int main()
{
	int a[] = {4,3,2,7,8,2,3,1};
	vector<int> iv(a,a+sizeof(a)/sizeof(int));
	vector<int> res;
	res=findDis(iv);
	output(res);
}
