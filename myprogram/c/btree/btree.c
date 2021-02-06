#include <stdio.h>
struct Node {
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root = NULL;

void insert(int key) {
	struct Node *t = root;
	struct Node *r,*p;
	if (root == NULL) {
		root = (struct Node *) malloc(sizeof(struct Node));
		root->data = key;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	while(t != NULL) {
		r=t;
		if(key < t->data)
			t=t->lchild;
		else if (key > t->data)
			t=t->rchild;
		else
			return;
	}
	p  = (struct Node *) malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = NULL;
	p->rchild = NULL;
	if(r->data > key) {
		r->lchild = p;
	}
	else {
		r->rchild = p;
	}

}

void preorder(struct Node *p) {
	if(p) {
		printf("%d \t",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(struct Node *p)
{
	if(p) {
		inorder(p->lchild);
		printf("%d \t",p->data);
		inorder(p->rchild);
	}
}

int search(int key){
	struct Node *t = root;
	
	while(t) {
		if(t->data == key) {
			printf("search found %d \n",key);
			return 1;
		}
		else if (t->data > key) {
			t=t->lchild;
		}
		else {
			t=t->rchild;
		}
	}
	return 0;
}
struct Node *Rinsert(struct Node *p,int key) {
	if(p == NULL) {
		// create p node
		struct Node *t;
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		if(root == NULL) root =t;
		return t;
	}

	if(key < p->data) {
			p->lchild = Rinsert(p->lchild,key);
	}
	else {
		p->rchild = Rinsert(p->rchild,key);
	}

	return p;
}

struct Node *succesor(int key)
{
	while( p && p->rchild != NUL)
		p = p->rchild;
	return p;
}

int htree(struct Node *p)
{
	int l,r;
	if(p == NULL) return 0;
	l=htree(p->lchild);
	r=htree(p->rchild);

	return l > r ? l+1:r+1;

}
int main() {
	int i;
//	insert(36);
	int A[] = {36,25, 19, 27, 9, 15, 20, 45, 30, 55,10};
	for(i=0;i<11;i++)
		Rinsert(root,A[i]);

	printf("l hight of tree %d\n",htree(root->lchild));
	printf("2 hight of tree %d\n",htree(root->rchild));
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	search(10)? printf(" "):printf("not found %d\n",100);
	search(15);
// 
}
