#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

void output(vector<bool> &nums)
{
	vector<bool>::iterator iter;
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

void setZeroes(vector<vector<int>> &matrix) {

	if (matrix.size() <= 0 || matrix[0].size() <= 0)
		return ;
	int i,j;
	set<int> rset; set<int> cset;
	set<int>::iterator iter;
	for (i = 0; i < matrix.size(); i++) {
		for (j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				rset.insert(i);
				cset.insert(j);
			}
		}
	}

	for (iter = rset.begin(); iter != rset.end(); iter++) {
		for (j = 0; j < matrix[0].size(); j++)
			matrix[*iter][j] = 0;
	}
	for (iter = cset.begin(); iter != cset.end(); iter++) {
		for (i = 0; i < matrix.size(); i++)
			matrix[i][*iter] = 0;
	}
}

int main()
{
	return 0;
}
