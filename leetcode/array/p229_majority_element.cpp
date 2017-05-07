#include <iostream>
#include <vector>

using namespace std;

void output(vector<int> &nums)
{
	vector<int>::iterator iter;
	for(iter=nums.begin(); iter!=nums.end(); iter++) {
		cout<<*iter<<" ";
	}
	cout<<endl;
}

vector<int> majorityElement(vector<int> &nums) {
	vector<int> res;
	int m = 0, n = 0, cm = 0, cn = 0;
	for (auto &a : nums) {
    	if (a == m) ++cm;
    	else if (a == n) ++cn;
    	else if (cm == 0) m = a, cm = 1; /* m has been updated */
    	else if (cn == 0) n = a, cn = 1; /* n has been updated */
   		else --cm, --cn;
		cout<<"m:"<<m<<" n:"<<n<<endl;
		
	}
	cm = cn = 0;
	for (auto &a : nums) {
		if (a == m) ++cm;
		else if (a == n) ++cn;
	}
	if (cm > nums.size() / 3)
		res.push_back(m);
	if (cn > nums.size() / 3)
		res.push_back(n);
	return res;
}

vector<int> majorityElement1(vector<int> &nums)
{
	vector<int> res;
	int stacka = 0, stackb = 0;
	int noa = 0, nob = 0;
	for (auto &i : nums) {
		if (i == stacka) {noa++;}
		else if (i == stackb) {nob++;}
		else if (noa == 0) {stacka = i; noa++;}
		else if (nob == 0) {stackb = i; nob++;}
		else {noa--;nob--;}
//		cout<<"a:"<<stacka<<" b:"<<stackb<<endl;
	}
	noa = 0; nob = 0;
	for (auto &i : nums) {
		if (i == stacka) noa++;
		else if (i == stackb) nob++;
	}

	if (noa > nums.size()/3)
		res.push_back(stacka);	
	if (nob > nums.size()/3)
		res.push_back(stackb);
	return res;
}

int main()
{
//	int a[] = {7,7,7,5,4,6,8,10};
//	int a[] = {4,2,1,1};
	int a[] = {8,8,7,7,7};
	vector<int> iv(a, a+sizeof(a)/sizeof(int));
	vector<int> res;
	res = majorityElement1(iv);
	output(res);
	return 0;
}
