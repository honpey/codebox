#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void output(vector<string> &nums)
{
	vector<string>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

vector<string> findRepeatedDnaSequences(string s)
{
	
	vector<string> res;
	unordered_map<string, int> hmap;
	unordered_map<string, int>::iterator iter;
	int i;

	if (s.size() <= 9)
		return res;

	for (i = 0; i < s.size() - 10 + 1; i++) {
		string temp(s.c_str()+i, s.c_str()+i+10);
		hmap[temp]++;
	}
	for (iter = hmap.begin(); iter != hmap.end(); iter++)
		if (iter->second >= 2)
			res.push_back(iter->first);
	return res;
}

int main()
{
	vector<string> res;
	//res = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	res = findRepeatedDnaSequences("");
	output(res);
	return 0;
}
