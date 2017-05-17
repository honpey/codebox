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

void output2(vector<vector<int>> &nums) {
    int vsize, hsize;
    int i,j;

    vsize = nums.size();
    for (j = 0; j < vsize; j++) {
        hsize = nums[j].size();
        for (i = 0; i < hsize; i++) {
            cout<<nums[j][i]<<" ";
        }
        cout<<endl;
    }   
}


int removeDuplicates(vector<int>& nums)
{
	unordered_map<int,int> hmap;
	vector<int>::iterator iter;
	iter = unique(nums.begin(),nums.end());
	return iter-nums.begin();
}

/* 观察数据特征 */
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> res(n, vector<int>(n,0));
	int i,j,layer;
	int count = 0;
	int direct, inner_loop;
	enum {RIGHT=0, DOWN, LEFT, UP};

	for (layer = 0; layer < n/2; layer++) {
		i = layer, j = layer; /* start_point */	
		direct = RIGHT;
		inner_loop = 4*(n-2*layer)-4;
	//	cout<<"inner_loop("<<layer<<"):"<<inner_loop<<endl;
		while (inner_loop--) {
	//		cout<<i<<" "<<j<<endl;
			res[i][j] = ++count;
			switch (direct) {
				case RIGHT:
					j++;
					if (j > n-layer-1) {i++;direct=DOWN;j--;}	
					break;
				case DOWN:
					i++;
					if (i > n-layer-1) {j--;direct=LEFT;i--;}
					break;
				case LEFT:
					j--;
					if (j < layer) {i--;direct=UP;j++;}
					break;	
				case UP:
					i--;
					break;
				default:
					break;
			}
		}
	}
	if (n&0x1)
		res[n/2][n/2] = ++count;
	return res;
}
int main()
{
	vector<vector<int>> res;
	res = generateMatrix(0);
	output2(res);
	return 0;
}
