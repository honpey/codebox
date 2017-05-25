#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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

bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;
	if (s.size() == 0)
		return true;
	int freq[255] = {0};
	int i;
	for (i = 0; i < s.size(); i++)
		freq[s[i]]++;
	for (i = 0; i < t.size(); i++)
		freq[t[i]]--;
	for (i = 0; i < 255; i++)
		if (freq[i] != 0)
			return false;
	return true;
	
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<removeDuplicates(iv)<<endl;
	return 0;
}
