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

int uniquePaths(int m, int n)
{
	int matrix[m][n];
	int i, j;
	if (m <= 0 || n <= 0)
		return 0;
	for (i = 0; i < m; i++)
		matrix[i][0] = 1;
	for (j = 0; j < n; j++)
		matrix[0][j] = 1;
	for (i = 1; i < m; i++) {
		for(j = 1; j < n; j++) {
			matrix[i][j] = matrix[i][j-1] + matrix[i-1][j];
		}
	}
	return a[m-1][n-1];

}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<uniquePaths(2,3)<<endl;
	return 0;
}
