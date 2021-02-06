#include <stdio.h>
#include <stdlib.h>


typedef struct list{
	int data;
	struct list *next;
}Stl;

Stl *top,*ptop;

void sprint()
{	Stl *temp = top;
	printf("<< \n");
	while(temp) {
		printf("%d \t",temp->data);
		temp =temp->next;
	}

	printf(" >>\n");
}
void spush(int n)
{
	if(top == NULL)
	{
		printf("first node \n");
		top = (Stl *)malloc(sizeof(Stl));
		top->data = n;
		top->next = NULL;
		return ;
	}

	Stl *temp = (Stl *)malloc(sizeof(Stl));
	temp->data = n;
	temp->next = top;
	top = temp;
}

int spop()
{
	int ret=-999;
	if(top == NULL)
	{
		perror("stack is empty \n");
		return ret;
	}
	Stl *temp = top;
	ret = temp->data;
	
	top = top->next;	
	free(temp);
	return ret;
}


int main()
{
	int i;
	printf("%d \n",5*5*5-2);
	for(i=1;i<=5;i++) {
		spush(i*100);
	}
	sprint();
	for(i=1;i<=9;i++) {
		printf("%d \t",spop());
	}
	sprint();
}
