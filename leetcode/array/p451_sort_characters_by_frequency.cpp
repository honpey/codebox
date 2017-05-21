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

string frequencySort(string s)
{
	int i, k;
	int size = s.size();
	int ascii[255] = {0};
	string res;
	vector<list<char>> iarray(size+1);

	for (char& pos:s) {
		ascii[pos]++;
	}

	for (i = 0; i < 255; i++) {
		if (ascii[i])
			iarray[ascii[i]].push_back(i);
	}

	for (i = size; i > 0; i--) {
		for (char &cur : iarray[i])
			res.insert(res.end(), i, cur);	
	}
	return res;
}
int main()
{
	cout<<frequencySort(string("eeeee"))<<endl;
	return 0;
}
