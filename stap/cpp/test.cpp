#include <iostream>
using namespace std;
class A {
public:
	A(){};
	~A(){};
	void setName(string a);
	string getName();
	string name;
};

void A::setName(string aaaNB) {
	name = aaaNB;
}
string A::getName() {
	return name;
}

int main()
{
	A *a = new A();
	while (1) {
		a->setName("xiaohong");
		cout<<a->getName()<<endl;
		int i = 0;
		while (i++ < 0xfffffff);
	}
}
