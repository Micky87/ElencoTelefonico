#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

//Crea una socket da un indirizzo e una porta, ritorna il valore della connect, -1 se errore

int creaServerSocket(int Porta, int max_connections)
{
  int sock,errore;
  struct sockaddr_in server;

  //Creazione socket
  sock=socket(AF_INET,SOCK_STREAM,0);
  //Tipo di indirizzo
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(Porta);

  //Bind del socket
  errore=bind(sock,(struct sockaddr*) &server,sizeof(server));
  //Per esempio, facciamo accettare fino a 7 richieste di servizio
  //contemporanee (che finiranno nella coda delle connessioni).
  errore=listen(sock,max_connections);

  return sock;
}
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

