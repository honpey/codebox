#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
					vector<int>&D)
{
	int i,j;
	int count = 0;
	unordered_map<int,list<pair<int,int>>> hmap;
	unordered_map<int,list<pair<int,int>>>::iterator iter;
	
	for (i = 0; i < C.size(); i++)
		for (j = 0; j < D.size(); j++) {
			hmap[C[i]+D[j]].push_back(make_pair(i,j));
			cout<<C[i]+D[j]<<endl;

		}

	for (i = 0; i < A.size(); i++) 
		for (j = 0; j < B.size(); j++) {
			iter = hmap.find(0-A[i]-B[j]);
			if (iter != hmap.end())
				count += iter->second.size();
		}
	
	return count;
}

int main()
{
	int a[] = {1,2};
	vector<int> ia(a, a+sizeof(a)/sizeof(int));
	int b[] = {-2,-1};
	vector<int> ib(b, b+sizeof(b)/sizeof(int));
	int c[] = {-1,2};
	vector<int> ic(c, c+sizeof(c)/sizeof(int));
	int d[] = {0,2};
	vector<int> id(d, d+sizeof(d)/sizeof(int));
	cout<<fourSumCount(ia, ib, ic, id)<<endl;
	return 0;
}
