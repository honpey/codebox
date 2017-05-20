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

int findMaxLength(vector<int>& nums)
{
	int i, max = 0;
	int no1=0, no0=0, pos;
	unordered_map<int,int> hmap;
	for (i = 0; i < nums.size(); i++) {
		nums[i] ? no1++ : no0++;
		if (no1-no0 == 0)
			max = i+1;
		else if (hmap[no1-no0] == 0)
			hmap[no1-no0] = i+1;
		else if (i - hmap[no1-no0] + 1 > max)
			max = i - hmap[no1-no0] + 1;
		
	}
	return max;

}

int main()
{
	int a[] = {1,1,0,1,0,1,0,0,0,0,1,1,1,1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
//	cout<<removeDuplicates(iv)<<endl;
	cout<<findMaxLength(iv)<<endl;;
	return 0;
}
