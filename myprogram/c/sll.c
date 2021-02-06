#include<stdio.h>
#include<stdlib.h>
#include <mcheck.h>

typedef struct list
{
	int data;
	struct list *next;
}P;
struct list *first = NULL;
P * mergefun(P *l1, P* l2)
{
	P *temp,*l12;
	int len1=0,len2=0;
	temp = l1;
	while(temp) {
		len1++;
		temp=temp->next;
	}	
	temp = l2;
	while(temp) {
		len2++;
		temp=temp->next;
	}
	while(l1 && l2)
	{
		if(l1->data < l2->data) {
			if(l12 == NULL) {
				l12 = l1;
				l12->next = NULL;
			} else {
				l12->next = l1;
				l12=l12->next;
			}
			l1=l1->next;
		} else {
			if(l12 == NULL) {
				l12 = l2;
				l12->next = NULL;
			} else {
				l12->next = l2;
				l12=l12->next;
			}
			l2 = l2->next;
		}
	}

	while(l1)  {
		l12->next = l1; l1=l1->next;
		l12=l12->next;
	}
	while(l2)  {
		l12->next = l2; l2=l2->next;
		l12=l12->next;
	}
	return l12;
}

P *mergesort(P *l1)
{
	int len,i=0;
	P *temp,*a,*b;
	temp = l1;
	while(temp) {
		len++;
		temp=temp->next;
	}	
	if (len <= 1) 
		return l1;
	temp = l1;
	while(i < len/2) { i++;
		temp = temp->next;
	}
	b = temp->next;
	a = l1;
	temp->next = NULL;

	if (len == 0 || len == 1) 
		return l1;
	else {
		mergesort(a);
		mergesort(b);
		return( mergefun(a,b));
	}


}
P * ssort(P *head)
{
	P * temp = head,*temp1;
	int t1=0;
	while(temp) { 
		temp1=temp->next;
		while(temp1) {
			if(temp1->data < temp->data) {
				t1 = temp->data;
				temp->data = temp1->data;
				temp1->data = t1;
			}
			temp1= temp1->next;
		}
		temp = temp->next;
	}
	return head;
}
int create_sll(int a)
{
	if(first == NULL)
	{
		first = (struct list *)malloc(sizeof(struct list));
		first->next = NULL;
		first->data = a;
	}
	else
	{
		struct list *temp;
		temp = first;
		while(temp && temp->next) { temp=temp->next;}
		
		struct list *temp1 = (struct list*) malloc(sizeof(struct list));
		temp1->next = NULL;
		temp1->data = a;
		temp->next = temp1;
	}
}

void res3(P *q, P *r) {
	if(r) {
		res3(r,r->next);
		r->next = q;
	}
	else {
		first = q;		
	}
}
struct list * rev_sll(P *list)
{

	if (list == NULL) return NULL;
			
	if (list->next == NULL)
	{
		first = list;
		return list;
	}
	P *t = rev_sll(list->next);
	list->next->next = list;
	list->next = NULL;
	return t;
}
int print_sll()
{
	int i=12;
	struct list *temp = first;
	printf("\n");
	while(temp && --i)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\t end of list \n");
}
int isLoop()
{
	P* t1, *t2;
	int i=0;

	do {
		i++;
		t1 = t1->next;
		t2 = t2->next;
		t2 = t2 ? t2->next : NULL;
	}while( t1 && t2 && (t1 != t2));

	return ((t1 == t2) ? i : 0);
}
int isLoop2()
{
	int i=0;
	P *t1,*t2;
	t1=t2 = first;
	
	while(t1 && t2 && t2->next) {
		i++;
		t1 = t1->next; t2 = t2->next->next;
		if(t1 == t2) return i;
	}
	return 0;
}
makeloop()
{
	P *temp,*temp2;
	temp = temp2 = first;

	temp2=temp2->next->next->next;
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = temp2;
}
int revprint_sll(P *f)
{
	if(f == NULL) return;
	revprint_sll(f->next);
	printf("%d ",f->data);
}
int main()
{
	int ret;
	mtrace();
	create_sll(10);
	create_sll(31);
	create_sll(110);
	create_sll(50);
	create_sll(60);
	create_sll(90);
	create_sll(21);
	create_sll(70);
	create_sll(80);
	create_sll(41);
	create_sll(100);

	print_sll();
	ssort(first);
	print_sll();
	// MAKE LOOP
//	makeloop();

	if(ret = isLoop2()) printf("there is loop at %d",ret);
	print_sll();
#if 0
	revprint_sll(first);
	rev_sll(first);
	print_sll();
	res3(NULL,first);
	print_sll();
#endif

	muntrace();
}
