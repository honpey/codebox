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

void merge(vector<int>& nums1, int m, vector<int> &nums2, int n)
{
	int i,j;
	for (j = 0; j < nums2.size(); j++) {
		for (i = m-1+j; i>=0; i--) {
	//		cout<<"i:"<<i<<" j:"<<j<<endl;
			if (nums1[i] > nums2[j])
				nums1[i+1] = nums1[i];
			else
				break;
		}
		i++;
		/* i is the insert pos*/
		nums1[i] = nums2[j];
	}
}

int main()
{
	int a[] = {};
	int b[] = {1,2,3,4,5,6};
	vector<int> iva(a, a+sizeof(a)/sizeof(int));
	iva.resize(10);
	vector<int> ivb(b, b+sizeof(b)/sizeof(int));
	merge(iva, 0, ivb, sizeof(b)/sizeof(int));
	output(iva);
	return 0;
}
