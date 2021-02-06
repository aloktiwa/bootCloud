
#include <stdio.h>
void findluck(char name[100])
{
	if((strstr(name,"111111") == NULL) || (strstr(name,"000000") == NULL)) {
		printf("Sorry, sorry!");
	}
	else {
		printf("Good luck!");
	}
}


int main(){
	char num[101];
	scanf("%100[01]", &num);   
	printf("Input number is %s.\n", num);       // Writing //output to STDOUT
	findluck2(num);           			// Reading //input from STDIN
}


void findluck2(char *name)
{
	char *p1,*p2;
	if(name == NULL || strlen(name) < 6) {
		printf("Good luck!");
		return;
	}
	p1 = strcasestr(name,"111111");
	p2 = strcasestr(name,"000000");
	if((p1 == NULL) && (p2  == NULL)) {
		
		printf("Good luck!");
	}
	else {
		printf("Sorry, sorry!");
		//printf("%s %s \n",p1,p2);
	}
}


