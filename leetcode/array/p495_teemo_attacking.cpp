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

int	findPoisonedDuration(vector<int>& timeSeries, int duration)
{
	int i, interval;
	int curdua = duration;
	if (timeSeries.size() == 0 || duration <= 0)
		return 0;
	int end = timeSeries[0] + duration;
	for (i = 1; i < timeSeries.size(); i++) {
		if (timeSeries[i] >= end) {
			curdua += duration;
			end = timeSeries[i]+duration;
		}
		else {
			
			interval = (timeSeries[i]+duration-end)>0?
						(timeSeries[i]+duration-end):0;
			curdua += interval;
			end += interval;
		}
	}
	return curdua;
}

int main()
{
	int a[] = {1,2};
	int duration = 2;
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findPoisonedDuration(iv, duration)<<endl;
	return 0;
}
