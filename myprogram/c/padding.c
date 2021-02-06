#include <stdio.h> 
  
// A simple representation of the date 
struct date { 
	char padd[11];
    unsigned int d:5; 
	int a;
    //unsigned int m:3; 
  //  unsigned int y; 
}; 
  
int main() 
{ 
    printf("Size of date is %d bytes %d\n",  sizeof(struct date),sizeof(long)); 
//    struct date dt = { 31, 12, 2014 }; 
  //  printf("Date is %d/%d/%d", dt.d, dt.m, dt.y); 
} 

