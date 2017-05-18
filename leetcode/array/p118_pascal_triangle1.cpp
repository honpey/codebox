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

void output2(vector<vector<int>> &nums) {
	int vsize, hsize;
	int i,j;

	vsize = nums.size();
	for (j = 0; j < vsize; j++) {
		hsize = nums[j].size();
		for (i = 0; i < hsize; i++) {
			cout<<nums[j][i]<<" ";
		}
		cout<<endl;
	}
	cout<<vsize<<endl;
}

vector<vector<int>> generate(int numRows)
{
	int i, j;
	vector<vector<int>> res;
	for (i = 0; i < numRows; i++) {
		vector<int> temp(i+1); /* i+1 elements */
		temp[0] = 1; temp[i] = 1;
		for (j = 1; j <= i-1; j++) {
			temp[j] = res[i-1][j-1]+res[i-1][j];
		}
		res.push_back(temp);
	}
	return res;
}

int main()
{
	vector<vector<int>> res;
	res = generate(5);
	output2(res);
	return 0;
}
