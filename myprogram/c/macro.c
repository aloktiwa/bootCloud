
#include <stdio.h>


#define ADDS(x) ("this is str add" #x )
#define GOOL(x,y) (x##y)
int main()

{
//	int typedef = 10;
	int t =10;
	typeof(int) B =800;
	printf("%s \n",ADDS('google'));
	printf("%s \n",ADDS( #GOOL(12,31)) );
	printf("hellow %d %d %d \n",t,B);
}
