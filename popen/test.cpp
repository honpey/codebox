#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
//	printf("hello world\n");
//	printf("%d\n", getpid());
	cout<<getpid()<<endl;
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE];
	string result;
	FILE *fp = popen("./hi", "r");
	result.clear();
	while (NULL != fgets(buffer, BUFFER_SIZE, fp)) {
		result.append(buffer);
	}
	std::cout<<result<<std::endl;
	pclose(fp);
}
