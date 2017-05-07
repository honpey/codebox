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

struct Interval {
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s, int e):start(s),end(e){}
};

void output2(vector<Interval> &nums)
{
	vector<Interval>::iterator iter;
	Interval curInter;
	for (iter = nums.begin(); iter != nums.end(); iter++) {
		curInter = *iter;
		cout<<"["<<curInter.start<<","<<curInter.end<<"]"<<endl;
	}
}

/* 如何自定义比较函数？*/
/* C++ 牛叉语法:*/
/* 如何返回空的数组 */

vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> res;
	int i;

	if (intervals.size() == 0)
		return vector<Interval>{};

	sort(intervals.begin(), intervals.end(),
		[](Interval a, Interval b) {return a.start < b.start;});
	res.push_back(intervals[0]);
	for (i = 1; i < intervals.size(); i++) {
		if (intervals[i].start > res.back().end) {
			res.push_back(intervals[i]);
		} else if (intervals[i].start >= res.back().start &&
				intervals[i].end > res.back().end) {
//			cout<<"i:"<<i<<endl;
			res.back().end = intervals[i].end;
		} 
	}
	return res;
}

int main()
{
	int a[] = {1,2,2};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<Interval> vecs;
	vector<Interval> res;
	Interval inter1(1,4);
	Interval inter2(1,5);
//	Interval inter3(8,10);
//	Interval inter4(15,18);
	vecs.push_back(inter1);
	vecs.push_back(inter2);
//	vecs.push_back(inter3);
//	vecs.push_back(inter4);
	output2(vecs);
	cout<<"------------"<<endl;
	res = merge(vecs);
	output2(res);
	return 0;
}
