#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include "NetworkUtils.c"
#include <string.h>
#include <unistd.h>

#define PORT 1725
#define MAX_DIM 512
#define MAX_CONNECTIONS 4

int main(int argc, char **argv) {

	int ds_sock, sock_accept;
	struct sockaddr client;
	int length=sizeof(client);
	char msg[MAX_DIM];
	ds_sock=creaServerSocket(PORT, MAX_CONNECTIONS);
	//printf("il valore del sock è: %d \n", ds_sock);
	while(1){
				while((sock_accept=accept(ds_sock,&client, &length))==-1);
				do{
				int num=read(sock_accept,msg,MAX_DIM);
				//printf(" num invece è: %d \n", num);
				msg[num-1]='\0';
				msg[num]='\n';
				write(1,msg,num+1);

				}while(strcmp(msg,"exit")!=0);
				chiudiSocket(sock_accept);
				break;
	}
	return 0;

}
