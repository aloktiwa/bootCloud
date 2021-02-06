void inorder( node *t )
{
	while ( t != NULL || !isEmpty(stack)) {
		if( t  !== NULL ) {
			push(t);
			t = t->lchild;
		} else {
			t  = pop(stack)
			printf("%d ",t->val);
			t = t->rchild
		}
	}
}
void postorder( node *t )
{
	while ( t != NULL || !isEmpty(stack)) {
		if( t  !== NULL ) {
			push(t);
			t = t->lchild;
		} else {
			t  = pop(stack)
			if( t > 0) {
				push(-t);
				t = t->rchild;
			} else {

				printf("%d ",t->val);
				t = NULL
			}
		}
	}
}
void preorder( node *t )
{
	while ( t != NULL || !isEmpty(stack)) {
		if( t  !== NULL ) {
			push(t);
			printf("%d ",t->val);
			t = t->lchild;
		} else {
			t  = pop(stack)
			t = t->rchild
		}
	}
}
