#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class RandomizedSet {
public:
	RandomizedSet() {
	}
	bool insert(int val) {

		if (hmap.find(val) != hmap.end())
			return false;

		nums.push_back(val);
		hmap[val] = nums.size()-1;
		return true;
	}
	bool remove(int val) {

		if (hmap.find(val) == hmap.end())
			return false;
		int last = nums.back();
		nums[hmap[val]] = last;
		hmap[last] = hmap[val]; /* */
		nums.pop_back();
		hmap.erase(val);
		return true;
		
	}
	int getRandom() {
		return nums[rand() % nums.size()];
	}
	
private:
	unordered_map<int,int> hmap; /* use hash map to search [val, pos in array] */
	vector<int> nums;
};
int main()
{
	RandomizedSet *rs = new RandomizedSet();
	cout<<rs->insert(1)<<endl;
	cout<<rs->insert(2)<<endl;
	cout<<rs->insert(3)<<endl;
	cout<<rs->remove(2)<<endl;
	cout<<rs->remove(1)<<endl;
	cout<<rs->remove(3)<<endl;
	cout<<rs->remove(3)<<endl;
	cout<<rs->remove(3)<<endl;
	cout<<rs->remove(3)<<endl;
	cout<<rs->remove(3)<<endl;
	cout<<rs->remove(3)<<endl;


	
	return 0;
}
