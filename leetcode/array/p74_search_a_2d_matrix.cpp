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

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int row;

	if (matrix.size() <= 0)
		return false;
	if (matrix[0].size() <= 0)
		return false;
	row = getRow(matrix, target);
	cout<<"row:"<<row<<endl;
	if (row < 0)
		return false;
	return binary_search(matrix[row].begin(),
					matrix[row].end(), target);
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
	matrix1.push_back(id);
	cout<<searchMatrix(matrix1, 2)<<endl;
	return 0;
	int i, j;
	for (i = 0; i < matrix.size(); i++) {
		for (j = 0; j < matrix[0].size(); j++) {
			
			cout<<searchMatrix(matrix, matrix[i][j]+1)<<endl;
		}
	}

	
	return 0;
}
