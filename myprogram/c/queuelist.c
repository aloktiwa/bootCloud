#include <stdio.h>
#include <stdlib.h>
typedef struct Qnode {
	int data;
	struct Qnode *next;
}QN;

typedef struct Queue{
	QN *rear,*front;
}Qc;

void qprint(Qc *q)
{
	QN * temp = q->front;
	printf(" \n>>");
	while(temp) {
		printf("%d \t",temp->data);
		temp = temp->next;
	}
	printf(" >>\n");
}
QN * createN(int n)
{
	QN * temp = (QN *) malloc(sizeof(QN));
	temp->data = n;
	temp->next = NULL;
}
Qc *createQ(int n)
{
	Qc *temp = (Qc *)malloc(sizeof(Qc));
	temp->rear=temp->front = createN(n);
}

void enQ(Qc *qc,int n)
{
	QN *qn = createN(n);
	if(qc->rear == NULL) {
		printf("Queue is empty create new \n");
		qc->rear=qc->front = qn;
		return;
	}
	qc->rear->next = qn;
	qc->rear = qn;
}

int deQ(Qc *q)
{
	int data = -999;
	if(q->front == NULL) {
		perror("queue is empty nothing for qequeue\n");
		return data;
	}
	
	data = q->front->data;
	QN *qn = q->front;
	q->front = q->front->next;
	free(qn);
	return data;
}

int main()
{
	Qc * q = (Qc *)malloc(sizeof(Qc));//createQ(100);
	enQ(q,200);
	enQ(q,300);
	enQ(q,400);
	enQ(q,500);
	enQ(q,600);
	qprint(q);
	printf("%d \n",deQ(q));
	printf("%d \n",deQ(q));
	qprint(q);
	printf("%d \n",deQ(q));
	printf("%d \n",deQ(q));
	qprint(q);
	printf("%d \n",deQ(q));
	printf("%d \n",deQ(q));
	printf("%d \n",deQ(q));
}
