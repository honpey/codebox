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

/* 真的是easy难度的me？*/
/* 咋感觉还要用到动态规划呢 */
int maxProfit(vector<int>& prices)
{
	int i;
	int sum = 0;
	if (prices.size() <= 0)
		return 0;
	for (i = 0; i < prices.size()-1; i++)	
		if (prices[i+1] > prices[i])
			sum+=prices[i+1]-prices[i];
		
	return sum;
}

int main()
{
	int a[] = {1,2,3,10,2,9};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<maxProfit(iv)<<endl;
	return 0;
}
