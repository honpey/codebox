#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

bool containsNearbyDumplicate(vector<int>& nums, int k)
{
	int i;
	unordered_map<int, int> hmap;
	if (k<=0)
		return false;
	for (i = 0; i < nums.size(); i++) {
		if (hmap[nums[i]] != 0) /* nums[i] = nums[j] */
			if (i+1-hmap[nums[i]] <= k)
				goto Found;
		hmap[nums[i]] = i+1;			
		
	}
	return false;
Found:
	return true;
	
	
}

int main()
{
	int a[] = {-1,-1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<containsNearbyDumplicate(iv,1)<<endl;
	return 0;
}
