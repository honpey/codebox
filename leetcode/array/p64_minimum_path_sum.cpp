#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

void output2(vector<vector<int>> &rset)
{
	int vsize, hsize;
	int i, j;

	vsize = rset.size();
	for (j = 0; j < vsize; j++) {
		hsize = rset[j].size();
		for(i = 0; i < hsize; i++) {
			cout<<rset[j][i]<<" ";
		}
		cout<<endl;
	}
}

int getRow(vector<vector<int>> &matrix, int target)
{
	int i;
	int vsize = matrix.size();
	vector<int> res(vsize);
	vector<int>::iterator iter;

	if (target < matrix[0][0] ||
			target > matrix[vsize-1][matrix[0].size()-1])
		return -1;
	for (i = 0; i < vsize; i++) {
		res[i] = matrix[i][0];
	}
	
	output(res);
	iter = lower_bound(res.begin(), res.end(), target); 
	if (iter == res.end() || *iter > target )
		return iter - 1 - res.begin();
	else
		return iter - res.begin();
}

int searchMatrix(vector<vector<int>>& grid)
{
	int i, j, temp;
	vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
	res[0][0] = grid[0][0];
	for (i = 1; i < grid.size(); i++)
		res[i][0] = res[i-1][0] + grid[i][0];
	for (j = 1; j < grid[0].size(); j++)
		res[0][j] = res[0][j-1] + grid[0][j];
	for (i = 1; i < grid.size(); i++) {
		for (j = 1; j < grid[0].size(); j++) {
			temp = res[i-1][j] > res[i][j-1] ? res[i][j-1] : res[i-1][j];
			res[i][j] = temp + grid[i][j];
		}
	}
	return res[grid.size()-1][grid[0].size()-1];
}

int main()
{
	vector<vector<int>> matrix;
	vector<vector<int>> matrix1;
	int a[] = {1,3,5,7};
	vector<int> ia(a, a+sizeof(a)/sizeof(int));
	int b[] = {10,11,16,20};
	vector<int> ib(b, b+sizeof(b)/sizeof(int));
	int c[] = {23,30,34,50};
	vector<int> ic(c, c+sizeof(c)/sizeof(int));
	int d[] = {1,3};
	vector<int> id(d, d+sizeof(d)/sizeof(int));
	matrix.push_back(ia);
	matrix.push_back(ib);
	matrix.push_back(ic);
	vector<vector<int>> res;
	cout<<searchMatrix(matrix)<<endl;
	matrix1.push_back(id);

	
	return 0;
}
