#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define LEN 5
void output(vector<int> &matrix)
{
	vector<int>::iterator iter;
	for(iter=matrix.begin(); iter!=matrix.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}
void outputD(vector<vector<int>> &matrix)
{
	int i, j;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < LEN; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void rotate(vector<vector<int>>& matrix)
{
	
	for (int i = 0, j = matrix.size()-1; i < j; i++, j--)
        {  
            for (int k = i, d = j; k < j; k++, d--)
            {  
                int t = matrix[i][k];
                matrix[i][k] = matrix[d][i];
                matrix[d][i] = matrix[j][d];
                matrix[j][d] = matrix[k][j];
                matrix[k][j] = t;
            }  
        }  
}

void rotate2(vector<vector<int>> &matrix)
{
	int i,j;
	int loop, upBd, temp;
	loop = matrix.size()/2;

	for (i = 0; i < loop; i++) {

		upBd =  matrix.size() - 1 -i; /* [i, upBd] is the target retangle */
		for (j = i; j < upBd; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[upBd-j+i][i];
			matrix[upBd-j+i][i] = matrix[upBd][upBd-j+i];
			matrix[upBd][upBd-j+i] = matrix[j][upBd];
			matrix[j][upBd] = temp;
		}
		
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
