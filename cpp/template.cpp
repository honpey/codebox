#include <iostream>

using namespace std;

template<class T>
T min1(T x, T y)
{
	return (x<y)?x:y;
}
int main()
{
	int n1=2, n2=10;
	double d1=1.5, d2=5.6;
	cout<<"letter"<<min1(n1,n2)<<std::endl;
	cout<<"letter"<<min1(d1,d2)<<endl;

}
