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

vector<int> findDuplicates(vector<int>& nums)
{
	vector<int> visited(nums.size(), 0);
	vector<int> res;
	int i;
	int spos, cpos;

	for (i = 0; i < nums.size(); i++) {
		if (visited[i] == 1)
			continue;
		cout<<"start:"<<i<<endl;
		spos = cpos = i;
		while (!visited[nums[cpos]-1]) {
			visited[nums[cpos]-1] = 1;
			cpos = nums[cpos]-1;
		}
		cout<<"cur:"<<cpos<<endl;
		if (nums[cpos]-1 != spos)
			res.push_back(nums[nums[cpos]-1]);
	}
	return res;
}

vector<int> findDuplicates1(vector<int>& nums)
{
	vector<int> res;
	int i;
	if (nums.size() <= 1)
		return res;

	for (i = 0; i < nums.size(); i++) {
		int next = abs(nums[i])-1;
		if (nums[next] < 0)
			res.push_back(next+1);
		else
			nums[next] = -nums[next];
	}
	return res;
}

vector<int> findDuplicates2(vector<int>& nums)
{
	vector<int> res;
	int i, next;
	if (nums.size() <= 1)
		return res;
	for (i = 0; i < nums.size(); i++) {
		next = abs(nums[i])-1;
		if (nums[next] < 0) 
			res.push_back(next+1);
		else
			nums[next] = -nums[next];
	 
	}
	return res;
}

int main()
{
	int a[] = {4,3,2,7,8,2,3,1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	res = findDuplicates2(iv);
	output(res);
	return 0;
}
