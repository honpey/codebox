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

vector<int> findAnagrams(string s, string p)
{
	int i, j;
	bool is;
	vector<int> res;

	/* 把set换成数组，超时问题就解决了！数组真是好东西,当hash表用真是绝了！ */
	if (s.size () <= 0 || s.size() < p.size())
		return res;
	for (i = 0; i <= s.size() - p.size(); i++) {
		int hmap[256] = {0};
		is = true;
		/* 每进行一个下标之前先*/
		for (j = 0; j < p.size(); j++) {
			hmap[p[j]]++;
		}
		for (j = 0; j < p.size(); j++) {
			if (hmap[s[i+j]]-- == 0) {/**/
				is = false;
			}
		}
		if (is) 
			res.push_back(i);

	}
	
	return res;
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	res = findAnagrams(string("abab"), string("ab"));
	output(res);
	return 0;
}
