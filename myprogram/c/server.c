#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MYPORT 8647

struct sockaddr_in my_addr, peer_addr;
int sock_init() {
	/* create socket and bind to port */
	int sf;
	sf = socket(AF_INET,SOCK_STREAM,0);
	if (sf == -1){
		printf("sock create error \n");
		return sf;
	}


	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	//my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if( bind(sf,(struct sockaddr *)&my_addr,sizeof(my_addr)) < 0){
			perror("bind error\n");
			return -1;
	}

#if 1
	if(listen(sf,1) < 0) {
		perror("listen error \n");
		return -1;
	}
#endif

	return sf;
}

int main()
{
	int tcp_sock,asock;
	char buff[100];
	socklen_t len;
	bzero(&my_addr,sizeof(my_addr));
	bzero(&peer_addr,sizeof(peer_addr));
	tcp_sock = sock_init();
	if(tcp_sock == -1)
	{
		printf(" sock init error \n");
		return -1;
	}
	len =sizeof(peer_addr);
	for( ; ; ) {
		asock = accept(tcp_sock,(struct sockaddr *) &peer_addr,&len);
		printf("connect from %s port %d \n",
				inet_ntop(AF_INET,&peer_addr.sin_addr,buff,sizeof(buff)),ntohs(peer_addr.sin_port));

		recv(asock,buff,sizeof(buff),0);
		printf("this recv =%s \n",buff);

	}
}
