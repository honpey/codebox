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

char findTheDifference(string s, string t)
{
	int hmap[26] = {0};
	for (char &c : t)
		hmap[c-'a']++;
	for (char &c : s)
		hmap[c-'a']--;
	for (int i = 0; i < 26; i++)
		if (hmap[i] != 0)
			return 'a'+i;
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findTheDifference(string("abcd"),string("abcde"))<<endl;
	return 0;
}
