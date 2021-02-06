#include <stdio.h>

void swap1( char *x, char *y)
{
	*x = *x + * y;
	*y = *x - *y;
	*x = *x - *y;
}

void swap( int  *x, int *y)
{
	int i;
	i = *x;
	*x = *y;
	*y = i;
}
int pivotQ(int A[],int l,int h){
	int pivot = A[l];
	int temp;

	int i=l,j=h;
	do {
		do { i++ ;} while(A[i] <= pivot);
		do { j-- ;} while(A[j] > pivot);
		if(i < j)  {
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i < j);

	swap(&A[l],&A[j]);
	return j;
}
void sortA(int A[],int l,int h)
{
	int j;
	if(l < h)
	{
		j = pivotQ(A,l,h);
		sortA(A,l,j);
		sortA(A,j+1,h);
	}
}

int  mergeM(char A[],int l,int mid,int h)
{
	int i=l,j=mid+1,k=l;
	int B[100];
	while(i<=mid && j <=h ) {
		if(A[i]< A[j])
			B[k++] = A[i++];
		else 
			B[k++] = A[j++];
	}
	
	while(i <= mid) {
		B[k++] = A[i++];
	}
	while(j<=h) {
		B[k++] = A[j++];
	}
	for(i=l;i<=h;i++)
		A[i] = B[i];

}
void sortM(char A[],int l,int h)
{
	int mid;
	if(l< h) {
		mid = (l+h ) / 2;
		sortM(A,l,mid);
		sortM(A,mid+1,h);
		mergeM(A,l,mid,h);
	}
}

void matchPrint(int nuts[],int bolts[]){
	int i=0;
	for(i=0;i<8;i++)
		printf("[%c , %c] ",nuts[i],bolts[i]);

	printf("\n");
}
int main()
{
	int i;
	int nuts[] =  {'@','#','%','$','&','*','?','^'};
	int bolts[] = {'%','&','@','*','#','$','^','?'};
	char A[8] = { 2,1,7,5,9,3,44,19};
	sortM(A,0,7);

	for(i=0;i<8;i++)
		printf("%d \t",A[i]);
	sortA(nuts,0,8);
	sortA(bolts,0,8);
	printf("\n");
	matchPrint(nuts,bolts);

}
