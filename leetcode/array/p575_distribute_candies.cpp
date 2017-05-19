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

int distributeCandies(vector<int>& candies)
{
	set<int> iset;
	for (int k : candies)
		iset.insert(k);
	return (iset.size() >= candies.size()/2)?
				candies.size()/2:iset.size();
}

int main()
{
	int a[] = {1,1,2,3};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<distributeCandies(iv)<<endl;
	return 0;
}
