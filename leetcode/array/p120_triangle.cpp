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

void _minimumTotal(vector<vector<int>> &triangle,
					int v, int h, int &min, int cursum)
{
	if (v == triangle.size()) {
		if (cursum < min)
			min = cursum;
		return;
	}
	if (h < 0 || h >= triangle[v].size())
		return;
	_minimumTotal(triangle, v+1, h, min, cursum+triangle[v][h]);
	_minimumTotal(triangle, v+1, h+1, min, cursum+triangle[v][h]);
}

int minimumTotal(vector<vector<int>> &triangle)
{
	int vsize = triangle.size();
	int i;
	int min = 0;
	for (i = 0; i < vsize; i++) {
		min += triangle[i][0];
	}
	_minimumTotal(triangle, 1, 0, min, triangle[0][0]);
	_minimumTotal(triangle, 1, 1, min, triangle[0][0]);
	return min;
}
int minimumTotal2(vector<vector<int>> &triangle)
{
	int vsize = triangle.size();
	int maxhsize = vsize;
	vector<int> prerow(vsize, triangle[0][0]);
	vector<int> posrow(vsize);
	int i, j, k, minval;

	prerow[0] = triangle[0][0];
	for (i = 1; i < vsize; i++) {
		for (j = 0; j < i+1; j++) {
			if (j == 0)
				posrow[j] = prerow[j]+triangle[i][j];
			else if (j == i)
				posrow[j] = prerow[j-1]+triangle[i][j];
			else
				posrow[j] = min(prerow[j-1]+triangle[i][j],
							prerow[j]+triangle[i][j]);
		}
		for (k = 0; k < vsize; k++)
			prerow[k] = posrow[k];
	}
	minval = prerow[0];

	for (i = 0; i < vsize; i++) {
		if (prerow[i] < minval)
			minval = prerow[i];
	}

	return minval;
}

int minimumTotal3(vector<vector<int>> &triangle)
{
	vector<int> mini = triangle[triangle.size()-1];

	for (int i = triangle.size() -2; i >= 0; --i)
		for (int j = 0; j < triangle[i].size(); ++j)
			mini[j] = triangle[i][j] + min(mini[j], mini[j+1]);
	return mini[0];
}
int main()
{
	int l1[] = {2};
	int l2[] = {3,4};
	int l3[] = {6,5,7};
	int l4[] = {4,1,8,3};

	vector<int> iv1(l1, l1+sizeof(l1)/sizeof(int));
	vector<int> iv2(l2, l2+sizeof(l2)/sizeof(int));
	vector<int> iv3(l3, l3+sizeof(l3)/sizeof(int));
	vector<int> iv4(l4, l4+sizeof(l4)/sizeof(int));

	vector<vector<int>> tri;
	tri.push_back(iv1);
	tri.push_back(iv2);
	tri.push_back(iv3);
	tri.push_back(iv4);
	int res= minimumTotal3(tri);
	cout<<"res:"<<res<<endl;
	
	return 0;
}
