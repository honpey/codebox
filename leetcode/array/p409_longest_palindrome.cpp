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

int longestPalindrome(string s)
{
	int hmap[256] = {0};
	int i, count = 0;
	int isodd = false;
	for (char &c : s)
		hmap[c]++;
	for (i = 0; i < 255; i++) {
		count += hmap[i]&(~0x1);	
		if (hmap[i] & 0x1)
			isodd = true;
	}
	return count + (isodd?1:0);
}

int main()
{
	cout<<longestPalindrome(string("ccccdd"))<<endl;
	return 0;
}
