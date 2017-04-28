#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define LEN 5
void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}
void outputD(vector<vector<int>> &nums)
{
	int i, j;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			cout<<nums[i][j]<<" ";
		}
		cout<<endl;
	}
}

void rotate(vector<vector<int>>& nums)
{
	
	for (int i = 0, j = nums.size()-1; i < j; i++, j--)  
        {  
            for (int k = i, d = j; k < j; k++, d--)  
            {  
                int t = nums[i][k];  
                nums[i][k] = nums[d][i];  
                nums[d][i] = nums[j][d];  
                nums[j][d] = nums[k][j];  
                nums[k][j] = t;  
            }  
        }  
}

void rotate2(vector<vector<int>> &nums)
{
	int i,j;
	int loop, upBd, temp;
	loop = nums.size()/2;

	for (i = 0; i < loop; i++) {

		upBd =  nums.size() - 1 -i; /* [i, upBd] is the target retangle */
		for (j = i; j < upBd-1; j++) {
			temp = nums[i][j];
			nums[i][j] = nums[upBd-j][i];
			nums[upBd-j-i][i] = nums[upBd][upBd-j-i];
			nums[upBd][upBd-j-i] = nums[j][upBd];
		}
		return;
		
	}
}

int main()
{
	int i, j;
	int count = 0;;
	vector<vector<int>> iv(LEN);
	for (i = 0; i < LEN; i++)
		iv[i].resize(LEN);
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			iv[i][j] = count++;
		}
	}
	outputD(iv);
	cout<<"---------"<<endl;
	rotate2(iv);
	outputD(iv);
	return 0;
}
