#include <stdio.h>

typedef struct btree {
	int data;
	char name[10];
	struct btree *lc;
	struct btree *rc;
}BTREE;
BTREE * makenode(int data)
{
	char buff[20];
	BTREE * temp = (BTREE * ) malloc(sizeof(BTREE));
	temp->data = data;
	sprintf(buff,"node%d",data);
	strncpy(temp->name,buff,9);
	temp->lc = NULL;
	temp->rc = NULL;
	return temp;
}
BTREE *root;
int insert(int key)
{
	BTREE *t = root;
	BTREE *r,*p;
	if(root == NULL) {
		p = makenode(key);
	}
	while(t != NULL) {
		r = t
		if(root->lc)
	}
}
BTREE * maketree(int pre[],int inorder[])
{
	int p,i;
	BTREE * node = makenode(pre[0]);
	root = node;
	for(p=1;p<10;p++) {
		
	}


	return node;
}
int count2(BTREE *bt ) 
{
	if(bt) {
		return ( count (bt->lc) + count(bt->rc) + 1);
	}
	return 0;
}
int height(BTREE *bt)
{
	int x =0,y=0;
	if( bt == NULL ) return 0;

	x = height(bt->lc);
	y = height(bt->rc);
	if(x > y)
		return x + 1;
	else
		return y + 1;
}
int leafcount(BTREE *bt)
{
	int x,y;
	if( bt != NULL ) 
	{
		x = count(bt->lc);
		y = count(bt->rc);
		if( bt->lc == NULL && bt->rc == NULL) // this will count leaf node only
			return ( x + y + 1);
		else	
			return x + y;
	}

	return 0;
}
v
int count(BTREE *bt)
{
	int x,y;
	if( bt != NULL ) 
	{
		x = count(bt->lc);
		y = count(bt->rc);
		return ( x + y + bt->data); /* sum of all node */
		// return ( x + y + 1);
	}

	return 0;
}
void printInTree(BTREE *temp)
{
	if(temp == NULL ) return ;

	printInTree(temp->lc);
	printf("%d ",temp->data);
	printInTree(temp->rc);

}
int main()
{
	int preOd[10] = { 4,7,9,6,3,2,5,8,1,};
	int inOd[10] = {7,6,9,3,4,5,8,2,1};
	printInTree( maketree(preOd,inOd));
}
