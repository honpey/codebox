#include <iostream>

using namespace std;

class Closure
{
public:
	Closure() {}
	virtual bool Run() {
		std::cout<<"base"<<std::endl;
	}
}
class Closure2 : class Closure {
public：
	Closure2(int a, int b) {A=a; B=b;}
	virtual bool Run(int a, int b) {
	int A;
	int B;
}

int main()
{
	Closure 
}
