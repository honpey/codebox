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

int getnext(unsigned int n) {
	int sum = 0;
	while (n) {
		sum += (n%10)*(n%10);
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) {
	unordered_map<int,int> hmap;
	int next = n;
	do {
		if (hmap[next] != 0)
			return false;
		if (next == 1)
			return true;
		cout<<next<<endl;
		hmap[next]++;
		next = getnext(next);
	} while(true);
	
	return false;
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<isHappy(91)<<endl;
	return 0;
}
