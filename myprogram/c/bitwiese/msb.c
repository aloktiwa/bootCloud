#include  <stdio.h>
// input  0xAB33CD55
// output 0x

int main(void)
{
//    printf("Hello, world!\n");
    int Ai = 0x45adbe12,Bi;
	int x;
	x = ((Ai << 24)| (Ai >> 24)) | (0x00ffff00 & Ai);
	printf("%x == %x \n",Ai,x);
	int pos =6,n=3;
    int B1 = ((Ai & 0xff000000) >> 24 ) | (( Ai & 0x000000ff) << 24) | ((Ai & 0x00ff0000) >> 8 ) | (( Ai & 0x0000ff00) << 8);

   // printf("%x \n%x ",((~0 << 3) << (pos - n -1)));
    return 0;
}
