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

vector<int> getRow(int rowIndex)
{
	vector<int> res(rowIndex+1);
	int row;
	int i;
	for (row = 0; row <= rowIndex; row++) {
		res[0] = 1;
		res[row] = 1;
		for (i = row-1; i > 0; i--) {
			res[i] = res[i] + res[i-1];
		}
	}
	
	return res;
}

int main()
{
	vector<int> res;
	res = getRow(0);
	output(res);
	return 0;
}
