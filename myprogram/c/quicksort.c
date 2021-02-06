//gcc 7.4.0

#include  <stdio.h>

#define swapB(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while(0)

void swapA(int *a,int *b)
{
    int c;
    c = *b;
    *b=*a;
    *a=c;
}
int Qpartition(int A[],int low,int high)
{
    int pivot = A[high];
    int i = low -1;
    int j;
    
    for(j=low;j<= high -1;j++)
    {
        if(A[j] < pivot) {
            i++;
            swapA(&A[i],&A[j]);           
        }
    }
    swapA(&A[i+1],&A[high]);
    return (i+1);
    
}

void quicksort(int A[],int low,int high)
{
    int pivot;
    if(low < high) {
        pivot = Qpartition(A,low,high);
        quicksort(A,low,pivot -1);
        quicksort(A,pivot+1,high);
    }
}

void Aprint(int A[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
    printf("\n");
}

int qpivot(int A[],int low,int high)
{
	int pivot= A[high];

	int i =low -1,j;

	for(j=low;j<=high -1;j++)
	{
		if(A[j] < pivot) {
			i++;
			swapA(&A[i],&A[j]);
		}
	}

	swapA(&A[i+1],&A[j]);
	return (i+1);
}
void dup_qsort(int A[],int low, int high)
{	
	int pivot;
	if(low < high) {
		pivot = qpivot(A,low,high);
		dup_qsort(A,low,pivot -1);
		dup_qsort(A,pivot,high);
	}
}
int main(void)
{
	int a =10,b=30;
    int A[10] = {10,4,5,14,67,78,3,90,56,44};
    int n = sizeof(A)/sizeof(int);
    
    Aprint(A,10);
  //  quicksort(A,0,9);
	dup_qsort(A,0,n -1);
    Aprint(A,10);
    
	swapB(a,b);
    printf("Hello, world! %d %d \n",a,b);
    return 0;
}

