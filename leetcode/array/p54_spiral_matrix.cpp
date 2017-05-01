#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

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

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
	vector<int> res;
	int i,j;
	int vsize = matrix.size();
	int hsize;
	int start_x, start_y, end_x, end_y; /* x:row y:colomn */
	int cur_x, cur_y;
	int count = 0;
	int direction = RIGHT;

	if (vsize == 0)
		return res;

	hsize = matrix[0].size();
	start_x = start_y = 0;
	end_x = vsize-1; end_y = hsize-1;
	cur_x = cur_y = 0;

	while (start_x <= end_x && start_y <= end_y) {

		count++;
		switch (direction) {
			case RIGHT:
//				if (cur_y > end_y && start_y == end_y)
//					goto done;
				if (cur_y > end_y) {
					direction = DOWN; cur_y = end_y; cur_x++;
					continue;
				}
//				cout<<"RIGHT:"<<matrix[cur_x][cur_y]<<endl;
				res.push_back(matrix[cur_x][cur_y]); cur_y++;
				break;
			case DOWN:
//				if (cur_x > end_x && start_x == end_x)
//					goto done;
				if (cur_x > end_x) {
					direction = LEFT; cur_x = end_x; cur_y--;
					continue;
				}
//				cout<<"DOWN:"<<matrix[cur_x][cur_y]<<endl;
				res.push_back(matrix[cur_x][cur_y]); cur_x++;
				break;
			case LEFT: /* 向左的前提是 cur_x != start_x */
//				if (cur_y < start_y && start_y == end_y)
//					goto done;
				if (cur_x == start_x && start_x == end_x)
					goto done;
				if (cur_y < start_y) {
					direction = UP; cur_y = start_y; cur_x--;
					continue;
				}
//				cout<<"LEFT:"<<matrix[cur_x][cur_y]<<endl;
				res.push_back(matrix[cur_x][cur_y]); cur_y--;
				break;
			case UP: /* 向上的前提是 cur_y != start_y */
//				if (cur_x <= start_x && start_x == end_x)
//					goto done;
				if (cur_y == start_y && start_y == end_y)
					goto done;
				if (cur_x <= start_x) {
					direction = RIGHT;
					start_x++; start_y++;
					end_x--; end_y--;
					cur_x = start_x; cur_y = start_y;
					continue;
				}
//				cout<<"UP:"<<matrix[cur_x][cur_y]<<endl;
				res.push_back(matrix[cur_x][cur_y]); cur_x--;
				break;
		}
		
	}
done:
	return res;
}
int main()
{
//	int a[] = {1,1,1,0};
	int i, j;
	vector<vector<int>> vv;
	vector<int> res;
	int count = 0;
	for (i = 0; i < 4; i++) {
		vector<int> temp;
		for (j = 0; j < 1; j++) {
			count++;
			temp.push_back(count);
		}
		vv.push_back(temp);
	}
	output2(vv);
	cout<<"--------------"<<endl;
//	int a[] = {-1, 0, 1, 1, 55};
//	vector<int> iv(a, a+sizeof(a)/sizeof(int));
//	int res= threeSum(iv, 3);
	res = spiralOrder(vv);
	output(res);
	
	return 0;
}
