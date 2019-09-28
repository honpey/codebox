#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <list>
#include <string>
#include <unordered_set>

using namespace std;

int search(vector<int>& nums, int target);
void output(vector<int>&nums);
int bsearch(vector<int> &nums, int target);

int main()
{
	int a[] = {1,2,8,4,5,7,6,3,9,10};
	int b[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> ibb(b, b+sizeof(b)/sizeof(int));
	unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
	string str("hello_world");
	string str1(str.c_str()+1, str.c_str()+2);
	cout<<str<<endl;
	cout<<str1<<endl;
//	cout<str1<<endl;
	cout<<sqrt(4)<<endl;
	cout<<sqrt(5)<<endl;
	return 0;

}
int search(vector<int>& nums, int target)
{
	vector<int>::iterator iter;
	iter = lower_bound(nums.begin(),nums.end(),target);
	return iter-nums.begin();
}

void output(vector<int>&nums) {
	int i;
	vector<int>::iterator iter;
	for (iter = nums.begin(); iter != nums.end(); iter++)
		cout<<*iter<<" ";
	cout<<endl;
}

int bsearch(vector<int> &nums, int target)
{
	int i, size;
	int start = 0, end = nums.size()-1;
	int mid;
	while (start <= end) {
		mid = (start + end)/2;
		if (target == nums[mid])
			return mid;
		else if (target < nums[mid]) {
			end = mid-1;
		} else 
			start = mid+1;
	}
	return -1;
}

int search(vector<int>& nums, int target);
void output(vector<int>&nums);
int bsearch(vector<int> &nums, int target);
