#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unistd.h>

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

/* 看网上攻略，从环入手分析 */
/*
 * 比如下面的数组：3 3 1 2 4
 * 首先，最好的办法就是各就各位，对于这种1-n类型的数组，让它们
 * 各就各位就是最好的办法了，但是现在题目要求不能够调整元素的位置
 * 只能远远地用环的方法处理了：
 *
 * 0 1 2 3 4 --- 共有5个元素，但是里面的值是1,2,3,4
 * 3 3 1 2 4
 * 
 * 0->3 (pos:2)
 * 2->1 (pos:0)
 * 0->3 (pos:2) 已经达到一个环了，那么0,2这个位置相当于是安全的了
 * .......
 * a[1]=3 (pos:2)
 * a[2]=1 (pos:0)
 * a[0]=3 (pos:2)
 * a[2]=1 (pos:0)
 * a[0]=3 (pos:2) 是一个β类型的环，但是怎么找到这个出事
 * ......   
 * a[2]=1 (pos:0)
 * a[0]=3 (pos:2)
 * a[2]=1 (pos:0)
 * a[0]=3 
 * ......
 * a[3]=2 (pos:1)
 * a[1]=3 (pos:2)
 * a[2]=1 (pos:0)
 * a[0]=3 (pos:2)
 *
 * 上面的分析都是不对的，关键点：如何利用好a[0]这个位置！！！！
 * 
 */

int findDuplicate(vector<int>& nums)
{
	int fast = 0, slow = 0;
	if (nums.size() <= 0)
		return -1;
	do {
		fast = nums[nums[fast]];
		slow = nums[slow];
	} while (fast != slow);

	fast = 0;
	do {
		if (nums[fast] == nums[slow])
			break;
		fast = nums[fast];
		slow = nums[slow];
	} while(1);
	return nums[fast];
}

int main()
{
	int a[] = {1,1};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	cout<<findDuplicate(iv)<<endl;
	return 0;
}
