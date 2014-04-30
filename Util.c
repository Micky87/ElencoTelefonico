#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUBRICA "rubrica.txt"
#define BUFSIZE 128
typedef struct {
	char* nome, cognome, telefono;
}record;


int creaRubrica() {
	if(!creat(RUBRICA,O_CREAT|0666))
		printf("Errore nella creat");
	return 0;
}
int aggiungiRecord(record r){
	int id=open(RUBRICA, O_WRONLY,0666);
		if(id==-1) printf("Errore nell'apertura");
	printf("Riga 22");
	char buffer[BUFSIZE];
	int i=0;
	printf("Riga 24");
	while(&r.nome[i]!="\0"){
		buffer[i]=r.nome[i];
		i++;
	}
		return 0;
}
void main(int argc, char **argv) {
	printf("Riga 33");
	creaRubrica();
	record r;
	printf("Riga 35");
	r.nome="Marco";
	strcpy(r.nome, "Marco");
	aggiungiRecord(r);

}

