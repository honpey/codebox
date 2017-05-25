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

/* 埃拉托斯特尼筛法 */
int countPrimes(int n)
{
	int count = 0;
	int i, j;
	if (n <= 1)
		return 0;
	vector<bool> sto(n, false);
	sto[0] = true; sto[1] = true;
	for (i = 0; i < sqrt(n); i++) {
		if (!sto[i]) {/* we need to */
			for (j = 2; j*i < n; j++) /* 2 not 1 */
				sto[j*i] = true;
		}
	}
	for (i = 0; i < n; i++)
		if (!sto[i])
			count++;
		
	return count;
}

int main()
{
	cout<<countPrimes(5)<<endl;
	return 0;
}
