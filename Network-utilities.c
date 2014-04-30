#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

//Crea una socket da un indirizzo e una porta, ritorna il valore della connect, -1 se errore

int crea_Socket(char* address, int port){
	struct sockaddr_in client;
	struct hostent *hp;
	int sock, errore;
	client.sin_family=AF_INET;
	client.sin_port=htons(port);
	hp=gethostbyname(address);
	bcopy(hp->h_addr, &client.sin_addr, hp->h_length);
	sock=socket(AF_INET, SOCK_STREAM,0);
	errore=connect(sock, (struct sockaddr*)&client, sizeof(client));
	return sock;
}

void chiudiSocket(int des){
	close(des);
}

int inviaMessaggio(int sock, char* messaggio, int mlength){
	return write(sock, messaggio, mlength);
}
int main(int argc, char **argv) {

	int des=crea_Socket("127.0.0.1", 1725);
	inviaMessaggio(des, "Ciao", 4);
}

