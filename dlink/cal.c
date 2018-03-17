#include <stdio.h>
int max(int a, int b) {
	return (a>b)?a:b;
}
int min(int a, int b) {
	return (a<b)?a:b;
}
int which(int a, int b, int op) {
	if (op == 1) {
		return max(a, b);
	} else if (op == 0) {
		return min(a, b);
	}
	return 0;
}
void sayhello() {
	printf("hello libso\n");
}
void sayhello2() {
	printf("hello libso\n");
}
void sayhell3() {
	printf("hello libso\n");
}

void sayhello4() {
//	sayhelloYa();
}
