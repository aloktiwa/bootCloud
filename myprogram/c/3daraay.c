#include "stdio.h" 
#include <stdlib.h>


typedef struct {
	char b;
}NODE;
int main() 
{ 
	int ***ptr; // [3][4][5]

   int i=0,j,k,count=0;

   ptr = (int ***)malloc(3*sizeof(int * *));
   for(i=0;i<3;i++) {
	   ptr[i] = (int **)malloc(sizeof(int *)*4);
	}

   for(i=0;i<3;i++) {
	   for(j=0;j <4;j++) {
		   ptr[i][j] = (int * )malloc(5 *sizeof(int ));
		}
	}

   for(i=0;i<3;i++) {
	   for(j=0;j <4;j++) {
		   for(k=0;k<5;k++)
			   ptr[i][j][k] = count++;
	   }
   }
   for(i=0;i<3;i++) {
	   printf("[ ");
	   for(j=0;j <4;j++) {
		   for(k=0;k<5;k++) {
			   printf("\t %d\t",ptr[i][j][k]);
			}
		   printf("\n");
	   }
		printf(" ]\n");
   }
  
   return 0; 
} 
