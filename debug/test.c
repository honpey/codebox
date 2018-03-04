#include <stdio.h>
#include <stdlib.h>

int func(int a) {
	int i = 1;
	int z = 0;
	for (i = 0; i < 10; i++) {
		int j = 1;
		for (j = 0; j < 100; j++) {
			z++;
		}
	}
	return z + a;
}
int main() {
	while(1) {
		func(100);
		sleep(1);
	}
}
