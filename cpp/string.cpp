#include <iostream>

using namespace std;

namespace bb{
class A {
public:
    A(int a) {count=a;};
    ~A();
    int getSize();
private:
    int count;
};

int A::getSize() {
    return count;
}
}

int main()
{
//    A *pA = make_unique<A>(12);
    bb::A *pA = make_unique<bb::A>(12);
    cout<<pA->getSize()<<endl;
    string str;
    if (str.empty()) {
        std::cout<<"hello world:"<<str<<std::endl;
    }
    if (str == "") {
        std::cout<<"hello world:"<<str<<std::endl;
    }
}
