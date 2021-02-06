#include <stdio.h>


struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct list {
	int a;
	int b;
	char name[20];
};
int main()
{
	struct node * array[4];
	struct list ll = { 10, 100, "alok"};
	struct node s1 = { .data=10, .lchild = NULL, .rchild = NULL};
	struct node s2 = { 20,NULL,NULL};
	array[0] = &s1;
	array[1] = &s2;
	printf("%d, %d\n",(array[0]->data), (array[1]->data));
}

