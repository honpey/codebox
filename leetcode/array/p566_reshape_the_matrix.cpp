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

vector<vector<int>> matrixReshape(vector<vector<int>> &nums,
												int r, int c)
{
	int i, j;
	int hsize = nums.size();
	int vsize;
	int count = 0;
	int res_i, res_j;

	if (hsize == 0)
		return nums;

	vsize = nums[0].size();
	if (hsize * vsize != r * c) {
		return nums;
	}
	vector<vector<int>> res(r, vector<int>(c));

	for (i = 0; i < hsize; i++) {
		for (j = 0; j < vsize; j++) {
			res_i = count / c;
			res_j = count % c;
			res[res_i][res_j] = nums[i][j];
			count++;
		}
	}
	return res;
}
int main()
{
	int i, j;
	vector<vector<int>> vv;
	vector<vector<int>> vvres;
	vector<int> res;
	int count = 1;
	for (i = 0; i < 2; i++) {
		vector<int> temp;
		for (j = 0; j < 4; j++) {
			count++;
			temp.push_back(count);
		}
		vv.push_back(temp);
	}
	output2(vv);
	cout<<"--------------"<<endl;
//	int a[] = {-1, 0, 1, 1, 55};
//	vector<int> iv(a, a+sizeof(a)/sizeof(int));
//	int res= threeSum(iv, 3);
	vvres = matrixReshape(vv, 4, 3);
	output2(vvres);
	
	return 0;
}
