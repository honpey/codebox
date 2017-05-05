#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

void outputS(vector<string> &nums)
{
	vector<string>::iterator iter;
	for (iter = nums.begin(); iter != nums.end(); iter++) {
		cout<<*iter<<endl;
	}
}

int removeDuplicates(vector<int>& nums)
{
	unordered_map<int,int> hmap;
	vector<int>::iterator iter;
	iter = unique(nums.begin(),nums.end());
	return iter-nums.begin();
}

vector<string> summaryRanges(vector<int> &nums) {
	int pre, pos, pre_next;
	vector<string> res;
	pre = pos = 0;
	string temp;
	for (pre=pos=0; pre<nums.size();) {
		if (pre == nums.size() - 1) {
			temp.clear();
			if (pre==pos)
				temp.append(to_string(nums[pre]));
			else {
				temp.append(to_string(nums[pos]));
				temp.append("->");
				temp.append(to_string(nums[pre]));
			}
			res.push_back(temp);
			break;
		}
		if (nums[pre+1] != nums[pre]+1) {
			temp.clear();
			if (pre == pos)
				temp.append(to_string(nums[pre]));	
			else {
				temp.append(to_string(nums[pos]));
				temp.append("->");
				temp.append(to_string(nums[pre]));
			}
			res.push_back(temp);
			pos = pre+1;
		}
		pre++;
	}
	return res;
}
int main()
{
	int a[] = {};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<string> res;
	res = summaryRanges(iv);
	outputS(res);
	return 0;
}
