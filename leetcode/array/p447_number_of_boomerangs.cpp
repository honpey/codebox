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


int numberOfBoomerangs(vector<pair<int,int>> &points)
{
	unordered_map<int, vector<pair<int,int>>> hmap;
	int i,j;
	int dis;
	int count=0;

	for (i = 0; i < points.size(); i++) {
		for (j = i+1; j < points.size(); j++) {
			dis = (points[i].first - points[j].first)*(points[i].first - points[j].first) +
					(points[j].second - points[i].second)*(points[j].second - points[i].second);
			hmap[dis].push_back(make_pair(i,j));
		}
	}

	/*  把循环的范围缩小啦 ！*/
	for (auto it = hmap.begin(); it != hmap.end(); it++) {
//		sort(it->second.begin(), it->second.end(), [](pair<int,int> a, pair<int,int> b){if (a.first<b.first) return true; return false;});
		for (i = 0; i < it->second.size() ; i++) {
			for (j = i+1; j < it->second.size(); j++) {
				if (it->second[i].first == it->second[j].first || it->second[i].second == it->second[j].first ||
					it->second[i].first == it->second[j].second || it->second[i].second == it->second[j].second)
					count += 2;
			}
		}
	}
	return count;
}

/* 从标准答案中学来的，总有一种解法是让你大跌眼镜的! 就这么几行！*/
/* 这里面好像蕴含这一个非常重要的公式：该距离只有一个元素时，是没有题目中要求的数组对的
 当第三个元素加进来时，此时的数组对就变成了2了，i固定，(j,k)和(k,j), 然后当再加一个数组进来时，那么新增加的数组对是：
 (j,m),(k,m),(m,j)(m,k) 也就是说分别与前面的两队有了搭配！并且还要交换顺序，我晕。。。。这就是Cn2就是这么算出来的吧 ...
 好了，这个题告一段落，一个Easy的题竟困住我了.....*/
int numberOfBoomeranges1(vector<pair<int,int>> &points)
{
	int booms = 0;
	for (auto &p : points) {
		unordered_map<double, int> ctr(points.size());
		for (auto &q : points)
			booms += 2 * ctr[hypot(p.first - q.first, p.second - q.second)]++;
	}
	return booms;
}
int main()
{
	vector<pair<int,int>> points;
	points.push_back(make_pair(0,0));
	points.push_back(make_pair(1,0));
	points.push_back(make_pair(-1,0));
	points.push_back(make_pair(0,1));
	points.push_back(make_pair(0,-1));
	cout<<numberOfBoomeranges1(points)<<endl;
	return 0;
}
