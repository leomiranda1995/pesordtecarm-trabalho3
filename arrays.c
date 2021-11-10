#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVetor(int* vetor, int tam, int cont) {		
	if (cont < tam) {
		vetor[cont] = rand();		
		geraVetor(vetor, tam, ++cont);
	} else {
		return;
	}
}

void printVetor(int *vetor, int tam, int cont){
	if (cont < tam-1) {
		printf("%d, ", vetor[cont]);
		printVetor(vetor, tam, ++cont);
	} else if (cont < tam) {
		printf("%d", vetor[cont]);
		printVetor(vetor, tam, ++cont);
	} else {
		return;
	}
}

void leArquivo(int* vetor, int tam){
    int i;

    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        return;
    }

    for(i=0; i<tam; i++){
        fscanf(arquivo, "%d;", &vetor[i]);
    }

    fclose(arquivo);
}

void copiaVetor(int* vetorO,int* vetorC,int tam){
	int i;
    for (i=0; i<tam; ++i){
        vetorC[i] = vetorO[i];
    }
}
