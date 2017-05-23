#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

void output(vector<string> &nums)
{
	vector<string>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<endl;
	}
	cout<<endl;
}
/*
 * 少考虑一种情况：adda (dog cat cat fish)
 * 即便你没有指向，但是你不能指向别人
 * 并且是否合法的判断有点混乱！ 
*/

bool wordPattern(string pattern, string str)
{
	istringstream iss(str);
	string curstr;
	vector<string> strarray;
	int i;
	while (iss >> curstr) {
		strarray.push_back(curstr);
	}
	if (strarray.size() <= 0 || pattern.size() <= 0 || pattern.size() != strarray.size())
		return false;
	unordered_map<string, char> hmap1;
	for (i = 0; i < pattern.size(); i++) {
		if (hmap1.find(strarray[i]) != hmap1.end() && hmap1[strarray[i]] != pattern[i])
			return false;
		hmap1[strarray[i]] = pattern[i];
	}
	unordered_map<char, string> hmap2;
	for (i = 0; i < pattern.size(); i++) {
		if (hmap2.find(pattern[i]) != hmap2.end() && hmap2[pattern[i]] != strarray[i])
			return false;
		hmap2[pattern[i]] = strarray[i];
	}
	return true;
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<wordPattern(string("adda"), string("dog cat cat fish"))<<endl;
	return 0;
}
