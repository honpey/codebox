#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define LEN 5
void output(vector<int> &matrix)
{
	vector<int>::iterator iter;
	for(iter=matrix.begin(); iter!=matrix.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}
void outputD(vector<vector<int>> &matrix)
{
	int i, j;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void nextPermutation(vector<int>& nums)
{
	int i,j;
	int size = nums.size();
	int temp;
	int pre,pos;
	pre = size-2;
	pos = size-1;
	for (;pre>=0 && pos>=0; pre--,pos--) {
		if (nums[pre] < nums[pos]) {/* we got the first ascending pair:pre*/
			break;
		}
	}
	if (pre < 0) {
		reverse(nums.begin(), nums.end());
		return;
	}
	for (i = size-1; i >= 0; i--) {
		if (nums[i] > nums[pre]) {
			break;
		}
	}
	temp = nums[i];
	nums[i] = nums[pre];
	nums[pre] = temp; /* swap */
	sort(nums.begin()+pre+1, nums.end());
	return;
}

int main()
{
	int i, j;
	int count = 0;;
	int a[] = {1,2,3,4,5,6}; /* (1,3,2)-->(2,1,3) */
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	output(iv);
	nextPermutation(iv);
	output(iv);
	return 0;
}
