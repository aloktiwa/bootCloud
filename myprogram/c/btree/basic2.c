#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
	int data;
	struct Node *lchild;
	struct Node *rchild;
}BNODE;
BNODE *root;

BNODE * insertR(BNODE *p,int key)
{
	BNODE *t = NULL;

	if(p == NULL) {
		t= (BNODE *)malloc(sizeof(BNODE));
		t->data =key;
		t->lchild = NULL;
		t->rchild = NULL;
		return t;
	}

	if(key < p->data) {
		p->lchild = insertR(p->lchild,key);
	} else if(key > p->data) {
		p->rchild = insertR(p->rchild,key);
	}
	return p;
}

int HightT(BNODE *p)
{
	int x,y;
	if(p == NULL) return 0;
	x= HightT(p->lchild);
	y= HightT(p->rchild);
	return (x>y?x:y);
}
BNODE *InSucc(BNODE *p)
{
	while(p && p->lchild != NULL)
		p=p->lchild;

	return p;
}
BNODE *InPre(BNODE *p)
{
	while(p && p->rchild != NULL)
		p=p->rchild;

	return p;
}

BNODE *Delete(BNODE *p,int key)
{
	BNODE *q;
	if(p == NULL) return ;

	if(p->lchild == NULL && p->rchild == NULL) {
		if(p == root);
			root = NULL;
		free(p);
		return NULL;
	}
	if(key < p->data) {
		p->lchild = Delete(p->lchild,key);
	} else if(key > p->data) {
		p->rchild = Delete(p->rchild,key);
	}else {
		if(HightT(p->lchild) > HightT(p->rchild)) {
			// delet from left child
			q= InPre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild,q->data);
		} else {
			q = InSucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild,q->data);
		}
	}

	return p;
}

int main()
{
	//create a tree here
}
