#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string str = "We think in generatlities, but we live in details.";
	std::string str2 = str.substr(3,5);
	std::size_t pos = str.find("live");
	std::string str3 = str.substr(pos);
	cout<<str2<<"|-|"<<str3<<endl;
	cout<<"hello world"<<endl;
}
