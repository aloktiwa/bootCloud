#include "stdio.h" 
#include <stdlib.h>


typedef struct {
	char b;
}NODE;
int main() 
{ 
	int **ptr; // [10][4]
   int array[5],count=0;

   int i=0;

   ptr = (int **)malloc(5*sizeof(int *));
   for(i=0;i<5;i++) {
	   ptr[i] = (int *)malloc(sizeof(int)*10);
	}

   for(i=0;i<5;i++) {
	for(int j=0;j <10;j++)
		ptr[i][j] = count++;
   }

   for(i=0;i<5;i++) {
	for(int j=0;j <10;j++)
		printf("%d \t",ptr[i][j]);
	printf("\n");
   }

  
   /* If %p is new to you, you can use %d as well */
   printf("array=%p : &array=%p\n", array, &array);  
  
   printf("array+1 = %p: &array + 1 = %p %d\n", array+1, &array+1,sizeof(NODE)); 
  
   return 0; 
} 
