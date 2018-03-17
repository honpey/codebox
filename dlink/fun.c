#include <stdio.h>

int main() {
	printf("hello world\n");
	//sayhell04();
	int i = 0;
	while (i++ < 10000000);
	i = 3;
	while (i-- > 0) {sleep(1);printf("%d", i);}
	sayhello();
}
