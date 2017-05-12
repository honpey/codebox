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

int findDuplicate1(vector<int>& nums) { /* fail at 2,2,3,4 */
    int n=nums.size()-1;
    int low=1, high=n;
    int mid;
    while (low < high) {
        mid = (low + high)/2;
		cout<<"mid:"<<mid<<endl;
        int count=0;
        for (int num:nums) {
            if (num <= mid) count++;
        }
        if(count>mid)
			high=mid;
        else
			low=mid+1; 
    }
    return low;
}
/* 二分法是有问题的 */


int findDuplicate(vector<int>& nums)
{
	int i;
	int start =0, end=nums.size()-1;
	int mid, precount = 0, poscount = 0;
	if (nums.size() <= 0)
		return -1;
	while (start < end) {
		mid = (start + end)/2;
		precount = 0; poscount = 0;
		for (i = 0; i < nums.size(); i++) {
			if (nums[i] < nums[mid]) {
				precount++;
			}
			
		}
	}
	return 1; 
}

int main()
{
	int a[] = {2,2,3,4};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findDuplicate1(iv)<<endl;
	return 0;
}
