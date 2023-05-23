#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 200

typedef struct nArv{

	char caracter;
	struct nArv *esq;
	struct nArv *dir;

} nArv;

void infixa(nArv *);
void prefixa(nArv *);
void posfixa(nArv *);
void printInfixa(char *);
void printPrefixa(char *);
void printPosfixa(char *);
nArv* push(nArv *, char );
_Bool busca(nArv *, char );

char letrasIn[MAXSIZE] = { 0 };
char letrasPos[MAXSIZE] = { 0 };
char letrasPre[MAXSIZE] = { 0 };

int i = 0;
int j = 0;
int k = 0;

void test(nArv *no){

	if (no){

		test(no->esq);
		printf("%c ", no->caracter);
		test(no->dir);

	}

}

void main (){

	char option[20], caracter;

	nArv *no = NULL;
	while (scanf("%s%*c", option) != EOF){

		if (strcmp(option, "I") == 0){
			scanf("%c", &caracter);
			no = push(no, caracter);
		}

		else if (strcmp(option, "INFIXA") == 0)
			infixa(no), printInfixa(letrasIn);
		else if (strcmp(option, "PREFIXA") == 0)
			prefixa(no), printPrefixa(letrasPre);
		else if (strcmp(option, "P") == 0){
			scanf("%c", &caracter);
			if (busca(no, caracter))
				printf("%c existe\n", caracter);
			else
				printf("%c nao existe\n", caracter);
		}
		else
			posfixa(no), printPosfixa(letrasPos);
	}
}

nArv* push(nArv *no, char caracter){

	if (!no){
		no = (nArv *) malloc(sizeof(nArv));
		no->caracter = caracter;
		no->dir = no->esq = NULL;
	}
	else if (no->caracter > caracter)
		no->esq = push(no->esq, caracter);
	else
		no->dir = push(no->dir, caracter);

	return no;
}

void infixa(nArv *no){

	if (no){
		infixa(no->esq);
		letrasIn[i++] = no->caracter;
		infixa(no->dir);
	}
}

void posfixa(nArv *no){

	if (no){
		posfixa(no->esq);
		posfixa(no->dir);
		letrasPos[j++] = no->caracter;
	}
}

void prefixa(nArv *no){

	if (no){
		letrasPre[k++] = no->caracter;
		prefixa(no->esq);
		prefixa(no->dir);
	}
}

_Bool busca(nArv *no, char caracter){

	_Bool dir, esq;

	if (!no)
		return false;

	if (no->caracter == caracter)
		return true;

	if (no->caracter > caracter)
		esq = busca(no->esq, caracter);
	else
		dir = busca(no->dir, caracter);
}

void printInfixa(char *caracter){

	int z;
	for (z = 0; z < i; ++z){
		if (!z)
			printf("%c", letrasIn[z]);
		else
			printf(" %c", letrasIn[z]);
	}

	i = 0;
	printf("\n");
}

void printPrefixa(char *caracter){
	
	int z;
	for (z = 0; z < k; ++z){
		if (!z)
			printf("%c", letrasPre[z]);
		else
			printf(" %c", letrasPre[z]);
	}

	k = 0;
	printf("\n");

}

void printPosfixa(char *caracter){

	int z;
	for (z = 0; z < j; ++z){
		if (!z)
			printf("%c", letrasPos[z]);
		else
			printf(" %c", letrasPos[z]);
	}

	j = 0;
	printf("\n");

}
