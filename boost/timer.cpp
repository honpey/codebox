#include <boost/timer.hpp>
#include <iostream>
using namespace boost;
using namespace std;

int main()
{
	timer t;
	cout<< "max timespan:"
		<<t.elapsed_max()/3600<<"h"<<endl;
	cout<<"min timespen:"
		<<t.elapsed_min()<<"s"<<endl;
	cout<<"now time elpsed:"
		<<t.elapsed()<<"s"<<endl;
}
