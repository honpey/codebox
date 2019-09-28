#include <stdio.h>
#include <unistd.h>
int globalA = 0;
int globalB = 0;

int funcb() {
	globalB++;
	sleep(3);
	printf("hello %d\n", globalB);
}

int funca() {
	globalA++;
	funcb();
}

struct node {
	int a;
	int b;
	struct node *next;
};

struct node *root;

void showNode(struct node *root) {
	while (root != NULL) {
		printf("a:%d b:%d\n", root->a, root->b);
		root = root->next;
	}
}

void showArray(int array[]) {
	for (int i = 0; i < 10; i++) {
		printf("a[%d]=%d\n", i, array[i]);
	}
}

void testGDB() {
	printf("testGDB call function\n");
}

int main()
{
	int i;
	struct node nodeA;
	struct node nodeB;
	nodeA.a = 1;
	nodeA.b = 11;
	nodeA.next = &nodeB;

	nodeB.a = 2;
	nodeB.b = 22;
	nodeB.next = NULL;

	root = &nodeA;
	showNode(root);

	while(1) {
//		sleep(10);
	funca();
	}
	return 0;
}
