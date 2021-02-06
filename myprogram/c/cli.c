#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define MYPORT 8647

struct sockaddr_in serv_addr, peer_addr;
int sock_init(char ip[],int port){
	/* create socket and bind to port */
	int sf;
	sf = socket(AF_INET,SOCK_STREAM,0);
	if (sf == -1){
		printf("sock create error \n");
		return sf;
	}


	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htonl(port);
	serv_addr.sin_addr.s_addr = inet_addr(ip);

	bind(sf,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

	listen(sf,20);

	return sf;
}

int main()
{
	int tcp_sock,asock;
	char buff[100];
	socklen_t len;
	int port= MYPORT;
	bzero(&serv_addr,sizeof(serv_addr));
	bzero(&peer_addr,sizeof(peer_addr));
	tcp_sock = socket(AF_INET,SOCK_STREAM,0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
//	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<=0)
	{
		printf("invalid address \n");
		return -1;
	}

	len =sizeof(serv_addr);
//	for( ; ; ) {
		asock = connect(tcp_sock,(struct sockaddr *) &serv_addr,len);
		if(asock != 0){
			perror("connect failed\n");
			printf(" a=%d\n",asock);
		}
		printf("connect from %s port %d \n",
				inet_ntop(AF_INET,&serv_addr.sin_addr,buff,sizeof(buff)),ntohs(serv_addr.sin_port));

		send(tcp_sock,"this is not a jock",20,0);
}
