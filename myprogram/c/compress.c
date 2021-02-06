

#include  <stdio.h>

/*
 *
 * test case 
 * "aaabbbcccdddaaaabb"
 * "abcdef"
 * "aabbccddeeffghi"
 * */
int main(void)
{
//    char name[100] = "aaabbcccaaannnhhhttt";
	char name[100] = "abcdefghiii";
	int count=0;
	int i=0,k=0;
	int len= strlen(name);
	for(i=0;name[i] != '\0' && i < len;i++)
	{
		if(len == (i + 1)) {
			if(count != 0)
			{
				sprintf(&name[k],"%d",count);
				k++;
			}
			else {
				name[k] = name[i];
				k++;
			}
			break;
			// last char
		}
		else {
			if ( count == 0 ) { 
				name[k] = name[i];k++;
				count++;
			}
			if(name[i] == name [i + 1]) {
				count++;
				continue;
			}
			if(count > 1 )
			{
				sprintf(&name[k],"%d",count);
				k++;
				count =0;
			}
		}
	}

	for(;k<len;k++) {
		name[k] = '\0';
	}

    printf("%s !\n",name);
    return 0;
}

