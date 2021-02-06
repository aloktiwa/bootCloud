#include <stdio.h>

int main()
{
	char A[] = "HellowAMi!!  xxx 1234 ??";
	int i;
	for(i=0;A[i] != '\0';i++) {
		if(A[i] >= 65 && A[i] <= 96)
			A[i] = A[i]  + 32;
		else if(A[i] >= 97 && A[i] <= 129)
			A[i] = A[i]  - 32;
	}

	printf("%s \n",A);
	for(i=0;A[i] != '\0';i++) {
		if(A[i] >= 65 && A[i] <= 96)
			A[i] = A[i]  + 32;
		else if(A[i] >= 97 && A[i] <= 129)
			A[i] = A[i]  - 32;
	}

	printf("%s \n",A);
}

