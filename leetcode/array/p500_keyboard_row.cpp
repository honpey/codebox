#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void output(vector<string> &nums)
{
	vector<string>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<endl;
	}
}

vector<string> findWords(vector<string>& words)
{
	vector<string> res;
	int i, row;
	unordered_set<char> row1 {'q','w','e','r','t','y','u','i','o','p'};
	unordered_set<char> row2 {'a','s','d','f','g','h','j','k','l'};
	unordered_set<char> row3 {'z','x','c','v','b','n','m'};

	vector<unordered_set<char>> keys;
	keys.push_back(row1); keys.push_back(row2); keys.push_back(row3);
	
	for (string& str : words) {
		
		for (i = 0; i < 3; i++)
			if (keys[i].count((char)tolower(str[0])) == 1)
				break;
		if (i >= 3)
			continue;
		for (char &cur: str) {
			if (keys[i].count((char)tolower(cur)) == 0)
				goto fail;
		}

		res.push_back(str);
fail:	
		continue;
	}
	return res;
}

int main()
{
	vector<string> res;
	vector<string> src;
	src.push_back(string("Hello"));
	src.push_back(string("Alaska"));
	src.push_back(string("Dad"));
	src.push_back(string("Peace"));
	res = findWords(src);
	output(res);
	return 0;
}
