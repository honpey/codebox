#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter;
	}
	cout<<endl;
}

vector<int> plusOne(vector<int>& digits)
{
	if (!digits.size())
		return vector<int>{};
	vector<int> res;
	int i;
	int carry = 1, caled;
	for (i = digits.size()-1; i >= 0; i--) {
		caled = (digits[i] + carry)%10;
		carry = (digits[i] + carry)/10;
		res.push_back(caled);
	}
	if (carry)
		res.push_back(1);
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	int a[] = {9,9,9,9};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;

	output(iv);
	res = plusOne(iv);
	output(res);
	return 0;
}
