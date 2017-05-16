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
}

/* k被采用的数字数目; n是sum */
void _combination(vector<vector<int>>& res, int curpos, int curk, int cursum,
						vector<int>& temp, int k, int n)
{
	if (curpos > 10)
		return;
	if (curk == k)  {
		if (cursum == n)
			res.push_back(temp);
		return;
	}
	temp.push_back(curpos);
	_combination(res, curpos+1, curk+1/* # of numbers */, cursum+curpos, temp, k, n);
	temp.pop_back();
	_combination(res, curpos+1, curk, cursum, temp, k, n);
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> res;
	vector<int> temp;

	_combination(res, 1, 0, 0, temp, k, n);
	return res;

}

int main()
{
	vector<vector<int>> res;
	res = combinationSum3(3,15);
	output2(res);
	return 0;
}
