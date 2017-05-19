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

int leastBricks(vector<vector<int>>& wall)
{
	unordered_map<int,int> hmap;
	int i,j,cursum;
	int max = 0;
	for (i = 0; i < wall.size(); i++) {
		cursum = 0;
		for (j = 0; j < wall[i].size()-1; j++) {
			cursum += wall[i][j];
			hmap[cursum]++;
		}
	}
	for (auto iter : hmap) {
		if (iter.second > max)
			max = iter.second;
	}
	return wall.size() - max;
}
int main()
{
	vector<vector<int>> wall;
	int a[] = {9,1};
	vector<int> ia(a, a+sizeof(a)/sizeof(int));
	int b[] = {6,3,1};
	vector<int> ib(b, b+sizeof(b)/sizeof(int));
	int c[] = {2,4,1,3};
	vector<int> ic(c, c+sizeof(c)/sizeof(int));
	wall.push_back(ia);
	wall.push_back(ib);
	wall.push_back(ic);
	cout<<leastBricks(wall)<<endl;
	return 0;
}
