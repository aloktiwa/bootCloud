#include <stdio.h>

#include <net/if.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	struct if_nameindex * if_ni, *ip;

	if_ni = if_nameindex();

	if(if_ni == NULL ) {
		perror("if_nameindex error\n");
		exit(EXIT_FAILURE);
	}

	for(ip = if_ni; (ip != NULL && ip->if_name != NULL); ip++){
		printf("%u : %s \n",ip->if_index,ip->if_name);

	}
	if_freenameindex(if_ni);
}
