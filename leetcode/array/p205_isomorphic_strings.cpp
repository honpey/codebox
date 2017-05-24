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
/* aba bab */
bool isIsomorphic(string s, string t)
{
	unordered_map<int, int> hmaps;
	unordered_map<int, int> hmapt;
	int i;
	if (s.size() == 0 && t.size() == 0)
		return true;
	if (s.size() != t.size())
		return false;
	for (i = 0; i < s.size(); i++) {
		if (hmaps[s[i]] != hmapt[t[i]])
			return false;
		hmaps[s[i]]=i+1; hmapt[t[i]]=i+1;
	}
	return true;
}

int main()
{
	return 0;
}
