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

int uniquePaths(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	if (m <= 0)
		return 0;
	int n = obstacleGrid[0].size();
	vector<vector<int>> matrix(m, vector<int>(n));
	int i, j;
	int cand1, cand2;
	if (m <= 0 || n <= 0)
		return 0;
	if (obstacleGrid[m-1][n-1] == 1)
		return 0;
	matrix[0][0] = obstacleGrid[0][0]==1?0:1;
	for (i = 1; i < m; i++)
		matrix[i][0] = obstacleGrid[i-1][0]==1?0:matrix[i-1][0];
	for (j = 1; j < n; j++)
		matrix[0][j] = obstacleGrid[0][j-1]==1?0:matrix[0][j-1];
	for (i = 1; i < m; i++) {
		for(j = 1; j < n; j++) {
			cand1 = obstacleGrid[i][j-1]==1?0:matrix[i][j-1];
			cand2 = obstacleGrid[i-1][j]==1?0:matrix[i-1][j];
			matrix[i][j] = cand1+cand2;
		}
	}
	return matrix[m-1][n-1];

}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
//	cout<<uniquePaths(3,3)<<endl;
	return 0;
}
