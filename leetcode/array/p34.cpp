#include <iostream>
#include <vector>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}


vector<int> searchRange(vector<int>& nums, int target)
{
	int i;
	int size = nums.size();
	int mid, start, end;
	vector<int> res;
	start = 0; end = size-1;
	while (start <= end) {
		mid = (start + end)/2;
		if (nums[mid] < target) {
			start = mid+1;	
		} else if (nums[mid] > target) {
			end = mid-1;
		} else {
			start = mid;
			while (start-1>=0 && nums[start-1] == target)
				start--;
			end = mid;
			while (end+1<=size-1 && nums[end+1] == target)
				end++;
			res.push_back(start);
			res.push_back(end);
			return res;
			 
		}
			
	}
	res.push_back(-1);
	res.push_back(-1);
	return res;
}

int main()
{
	int a[] = {5,7,7,8,8,10};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	res = searchRange(iv, 8);
	output(res);
	return 0;
}
