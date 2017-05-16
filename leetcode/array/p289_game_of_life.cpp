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

void output2(vector<vector<int>> &rset)
{
    int vsize, hsize;
    int i, j;

    vsize = rset.size();
    for (j = 0; j < vsize; j++) {
        hsize = rset[j].size();
        for(i = 0; i < hsize; i++) {
            cout<<rset[j][i]<<" ";
        }
        cout<<endl;
    }   

}

int liveNeigh(vector<vector<int>> &board, int i, int j)
{
	int noLiveNei = 0;
	
	if (i-1 >= 0 && j-1 >= 0 && *(short *)&board[i-1][j-1] == 1)
		noLiveNei++;
	if (i-1 >= 0 && *(short *)&board[i-1][j] == 1)
		noLiveNei++;
	if (i-1 >= 0 && j+1 < board[0].size() && *(short *)&board[i-1][j+1] == 1)
		noLiveNei++;
	if (j-1 >= 0 && *(short *)&board[i][j-1] == 1)
		noLiveNei++;
	if (j+1 < board[0].size() && *(short *)&board[i][j+1] == 1)
		noLiveNei++;
	if (i+1 < board.size() && j-1 >= 0 && *(short *)&board[i+1][j-1] == 1)
		noLiveNei++;
	if (i+1 < board.size() && *(short *)&board[i+1][j] == 1)
		noLiveNei++;
	if (i+1 < board.size() && j+1 < board[0].size() && *(short *)&board[i+1][j+1])
		noLiveNei++;
	return noLiveNei;
		
}

void gameOfLife(vector<vector<int>>& board)
{
	int vsize = board.size();
	int i, j;
	short *cur, *next;
	int noLiveNei;

	if (vsize <= 0)
		return ;

	for (i = 0; i < vsize; i++) {
		for (j = 0; j < board[0].size(); j++) {
			noLiveNei = liveNeigh(board, i, j);
			cout<<"<"<<i<<","<<j<<">:"<<noLiveNei<<endl;
			if (noLiveNei < 2 && *((short *)&board[i][j]) == 1)
				*((short *)&board[i][j] + 1) = 0;
			else if ((noLiveNei == 2 || noLiveNei == 3) && *((short *)&board[i][j]) == 1) 
				*((short *)&board[i][j] + 1) = 1;
			else if (noLiveNei > 3 && *((short *)&board[i][j]) == 1)
				*((short *)&board[i][j] + 1) = 0;
			else if (*((short *)&board[i][j]) == 0 && noLiveNei == 3)
				*((short *)&board[i][j] + 1) = 1;
		
		}
	}
	for (i = 0; i < vsize; i++)
		for (j = 0; j < board[0].size(); j++) {
			*((short *)&board[i][j]) = *((short *)&board[i][j]+1);
			*((short *)&board[i][j]+1) = 0;
		}

}

int main()
{
	vector<vector<int>> board;
	int a[] = {1,0,1,0};
	vector<int> ia(a, a+sizeof(a)/sizeof(int));
	int b[] = {0,0,1,0};
	vector<int> ib(b, b+sizeof(b)/sizeof(int));
	int c[] = {1,1,0,0};
	vector<int> ic(c, c+sizeof(c)/sizeof(int));

	board.push_back(ia);
	board.push_back(ib);
	board.push_back(ic);
	output2(board);
	cout<<"---------"<<endl;
	gameOfLife(board);
	output2(board);
	return 0;
}
