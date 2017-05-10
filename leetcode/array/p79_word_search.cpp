#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter;
	}
	cout<<endl;
}

bool exist(vector<vector<char>>& board, string word)
{
	int vsize = board.size();
	if (vsize == 0)
		return false;
	if (word.size() <= 0)
		return true;
	int hsize = board[0].size();
	int i, j;
	/*
	 * we designe a pair, whose coordinate is <x,y> in board, and
	 * th element in word
	 */
	stack<pair<int,int>> cdstack; /* coordinate stack */
	stack<int> postack; /* pos in word */

	for (i = 0; i < vsize; i++) {
		for (j = 0; j < hsize; j++) {
			if (board[i][j] == word[0]) {
				cdstack.push(make_pair(i,j));
				postack.push(0);
			}
		}
	}
	vector<pair<int,int>> path(word.size());
//	unordered<pair<int,int>,int> hmap;
//	set<pair<int,int>> iset;
	/* 解决方案，使用ｓｅｔ判断是否重复！！！*/
	/*  怎么让路径不重复，做到合理地剪枝呢? */
restart:
	while (!cdstack.empty()) {
		pair<int, int> cd = cdstack.top();
		int pos = postack.top();

		cdstack.pop(); postack.pop();
		path[pos] = cd;

		for (i = 0; i < pos; i++) {
			if (path[i].first == cd.first &&
				path[i].second == cd.second)
			goto restart;
		}

		if ((pos == word.size() - 1)) {/* To avoid check every search, we check in the last check */
			return true;
		}
		if (cd.first -1 >= 0 && board[cd.first-1][cd.second] == word[pos+1]) {
			cdstack.push(make_pair(cd.first-1, cd.second)); postack.push(pos+1); 
		}
		if (cd.second + 1 < board[0].size() && board[cd.first][cd.second+1] == word[pos+1]) {
			cdstack.push(make_pair(cd.first, cd.second+1)); postack.push(pos+1);
		}
		if (cd.first + 1 < board.size() && board[cd.first+1][cd.second] == word[pos+1]) {
			cdstack.push(make_pair(cd.first+1, cd.second)); postack.push(pos+1);
		}
		if (cd.second - 1 >= 0 && board[cd.first][cd.second -1] == word[pos+1]) {
			cdstack.push(make_pair(cd.first, cd.second-1)); postack.push(pos+1);
		}
	} 
	return false;
}

int main()
{
	char a[] = {'A','B','C','E'};
	char b[] = {'S','F','C','S'};
	char c[] = {'A','D','E','E'};
	vector<char> iva(a,a+sizeof(a)/sizeof(char));
	vector<char> ivb(b,b+sizeof(b)/sizeof(char));
	vector<char> ivc(c,c+sizeof(c)/sizeof(char));
	vector<vector<char>> board;

	board.push_back(iva);
	board.push_back(ivb);
	board.push_back(ivc);

///	string str1("ASFBA");
//	string str2("SFCEC");
	string str3("FCCBF");

//	cout<<exist(board, str1)<<endl;
//	cout<<exist(board, str2)<<endl;
	cout<<exist(board, str3)<<endl;

	return 0;
}
