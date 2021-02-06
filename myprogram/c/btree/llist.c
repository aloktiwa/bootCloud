

NODE * reverse(NODE *q,NODE*p)
{
	if(q) {
		reverse(q,q->next);
		q->next = p;
	} else 
		first = p;
}

int main()
{
	reverse(first,NULL);

}
