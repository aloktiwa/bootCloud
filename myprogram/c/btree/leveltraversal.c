void levelorder( Node * t ) 
{
	queue bqueue = INIT_QUEUE;

	print("%d ",t->val);
	enqueue(t);
	while( !isQempty())
	{
		p = dequeue();
		if(p->lchild) {
		print("%d ",p->lchild->val);
		enqueue(p->lchild);
		}
		if(p->rchild ) {
			printf("%d ",p->rchild->val);
			enqueue(p->rchild);
		}
	}
}
