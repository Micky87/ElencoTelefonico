#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include "NetworkUtils.c"

int main(int argc, char **argv) {
	int ds=crea_Socket("10.42.0.1", 1725);
	inviaMessaggio(ds,"ciao",4);
	chiudiSocket(ds);
}
