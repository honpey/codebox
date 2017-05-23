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

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
	vector<int> res;
	int i;
	unordered_map<int,int> hmap;

	for (i = 0; i < nums1.size(); i++)
		hmap[nums1[i]]++;
	for (i = 0; i < nums2.size(); i++)
		if (hmap[nums2[i]]-- > 0)
			res.push_back(nums2[i]);
	
	return res;
}

int main()
{
	int a[] = {1,2,2,1};
	vector<int> ia(a, a+sizeof(a)/sizeof(int));
	int b[] = {2,2,1,1,1,1,1};
	vector<int> ib(b, b+sizeof(b)/sizeof(int));
	vector<int> res;
	res = intersect(ia, ib);
	output(res);
	return 0;
}
