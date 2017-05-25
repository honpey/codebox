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

/*
 * 从A C G 入手!
 * A -- 0 0000
 * C -- 2 0010
 * G -- 6 0110
 * 妙！ 每10为字符串的组合即为一个数字 
 * A --> 00
 * c --> 01
 * G --> 10
 * T --> 11
 * 每次向右移动一位字符，相当于字符串对应的init值左移两位
 * 太妙了！发现数组本身的规律!
 */
vector<string> findRepeatedDnaSequences(string s)
{
	char hashMap[1048576] = {0};
	vector<string> ans;
	int len = s.size(), hashNum = 0;
	if (len < 11) return ans;
	for (int i = 0; i < 9; ++i)
		hashNum = hashNum << 2 | (s[i] - 'A' + 1)%5;
}

int main()
{
	vector<string> res;
	//res = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	res = findRepeatedDnaSequences("");
	output(res);
	return 0;
}
