#include <iostream>
#include <boost/scoped_ptr.hpp>

using boost::scoped_ptr;
using namespace std;

int main()
{

    cout << "Hello World!" << endl;

    scoped_ptr<string> sp(new string("book"));

    scoped_ptr<string> sp2(new string("school"));

    cout<<*sp<<endl;

    cout<<sp->size()<<endl;

    sp.reset(new string("the second"));

    cout<<*sp<<endl;

    sp.swap(sp2);

    cout<<"sp's value :"<<*sp<<endl;

    cout<<"sp2's value :"<<*sp2<<endl;

    return 0;
}


