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

int hIndex(vector<int>& citations)
{
	if (citations.size() < 0)
		return 0;
	int i;
	sort(citations.begin(), citations.end());
	for (i = citations.size() -1; i>=0; i--) {
		
	}
	return 0;
}

int main()
{
	int a[] = {3,0,6,1,5};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<hIndex(iv)<<endl;
	return 0;
}
