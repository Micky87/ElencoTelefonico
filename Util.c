#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>c"
#define STD_INPUT 0
#define STD_OUTPUT 1
#define RUBRICA "rubrica.txt"
#define NAME_SIZE 15
#define COGNOME_SIZE 15
#define TELEFONO_SIZE 15
#define DOM1_SIZE 16
#define DOM2_SIZE 19
#define DOM3_SIZE 20
#define DOM1 "Inserisci nome: "
#define DOM2 "Inserisci cognome: "
#define DOM3 "Inserisci telefono: "
#define DIM_ARRAY 10

typedef struct {
	char nome[NAME_SIZE];
	char cognome[COGNOME_SIZE];
	char telefono[TELEFONO_SIZE];
}record;


void copiaValore(char* dest, char* sorg){
	//Copia una stringa da sorgente a destinazione aggiungendo il terminatore come strcpy
	int i=0;
	while(sorg[i]!='\0'){
		dest[i]=sorg[i];
		i++;
	}
	dest[i]='\0';

}

void prendiDaTastiera(int id, record* r){
		write(STD_OUTPUT, DOM1, DOM1_SIZE);
		int length=read(STD_INPUT, r->nome, NAME_SIZE-1);
		r->nome[length-1]=' ';
		r->nome[length]='\0';
		write(id,r->nome,length);
		write(STD_OUTPUT, DOM2,DOM2_SIZE);
		length=read(STD_INPUT, r->cognome, COGNOME_SIZE-1);
		r->cognome[length-1]=' ';
		r->cognome[length]='\0';
		write(id, r->cognome, length);
		write(STD_OUTPUT, DOM3,DOM3_SIZE);
		length=read(STD_INPUT, r->telefono, TELEFONO_SIZE-1);
		write(id, r->telefono, length);
		r->telefono[length-2]=' ';
		r->telefono[length-1]='\n';
		r->telefono[length]='\0';


}
//void popolaArray(int id, record array[]){
//	int j=0;int i=0;int res;
//	do{

//	}while(res!=0);



//}

int main(int argc, char **argv) {
	int ds_file=open(RUBRICA,O_RDWR|O_CREAT|O_APPEND,0666);
	record r;
	prendiDaTastiera(ds_file, &r);
}

