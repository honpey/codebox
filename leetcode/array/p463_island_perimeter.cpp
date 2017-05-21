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

bool is_layer(vector<vector<int>> &grid, int x, int y)
{
	if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()
			|| grid[x][y] == 0)
		return true;
	return false;
}
int islandPerimeter(vector<vector<int>> &grid)
{
	int dirX[] = {0, 1, 0, -1};
	int dirY[] = {-1,0, 1, 0 };
	int i, j, k;
	int perimeter = 0;
	for (i = 0; i < grid.size(); i++) {
		for (j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				for (k = 0; k < 4; k++) {
					if (is_layer(grid, i+dirX[k], j+dirY[k]))
						perimeter++;
				}
			}
			
		}
	}
	return perimeter;
}

int main()
{
	int a[] = {1,0,-1,0,-2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<vector<int>> vset;
//	vset = fourSum2(iv, 0);
	output2(vset);
	return 0;
}
