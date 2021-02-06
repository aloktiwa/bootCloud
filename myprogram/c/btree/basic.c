#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}btree;

btree * instert(struct node *root,int val)
{
	btree *temp;
	if(root == NULL) {
		temp = (btree *)malloc(sizeof(btree));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else {
		if( val < root->data )
			root->left = instert(root->left,val);
		else
			root->right = instert(root->right,val);
	}

	return root;
}

int hight(btree *p)
{
	int x ,y;
	if(p == NULL) return 0;

	x = hight(p->left);
	y = hight(p->right);
	return (x > y ? x + 1:y+1);
}


btree * insucc(btree *p)
{
	while(p && p->left != NULL)
		p=p->left;
	return p;
}


btree *inPre(btree *p)
{
	while(p && p->right != NULL)
		p = p->right;
	return p;
}



void inoprint(btree *p)
{
	if(p != NULL)
	{
		inoprint(p->left);
		printf(" -> %d ",p->data);
		inoprint(p->right);
	}

}
void postprint(btree *p)
{
	if(p != NULL)
	{
		postprint(p->left);
		postprint(p->right);
		printf(" -> %d ",p->data);
	}

}
btree *delete(btree *p,int key)
{
	btree *q;

	if(p == NULL) return p;

	if( key < p->data)
		p->left = delete(p->left,key);
	else if ( key > p->data)
		p->right = delete(p->right,key);
	else {
		// search found case
		if(p->left == NULL && p->right == NULL) {
			free(p);
			p = NULL;
			return p;
		} else if ( p->left == NULL && p->right != NULL) {
			q = p->right;
			free(p);
			return q;
		} else if ( p->right == NULL ) {
			q = p->left;
			free(p);
			return q;
		} {
			if(hight(p->left) > hight(p->right))
			{
				q = inPre(p->left);
				p->data = q->data;
				p->left = delete(p->left,key);
			}
			else {
				q = insucc(p->right);
				p->data = q->data;
				p->right = delete(p->right,key);
			}
		}
	}
}

btree * searchnode(btree *root,int key)
{
	btree *p = root;
	while(p != NULL) {
		if(p->data == key) {
			printf("search found %u \n",&p);
			return p;
		}
		else if( key < p->data ) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return NULL;
}
int main(){
	btree * root = instert(NULL,45);
	instert(root,56);
	instert(root,34);
	instert(root,16);
	instert(root,30);
	instert(root,70);
	instert(root,78);
	printf("node %s <%d> \n",searchnode(root,30)?"found":"not found",78);
	printf(" \n");
	postprint(root);
	printf(" \t");
	inoprint(root);
	delete(root,30);
	printf(" \n");
	postprint(root);
	printf(" \t");
	inoprint(root);
	printf(" \n");
	printf("node %s <%d> \n",searchnode(root,30)?"found":"not found",78);
	printf(" \n");
}
