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

void vetorManual(int* vetor, int tam, int cont) {
	if (cont < tam){
		printf("%d -> ", cont+1);
		scanf("%d", &vetor[cont]);
		vetorManual(vetor, tam, ++cont);
	} else {
		return;
	}
}

void printVetor(int *vetor, int tam, int cont){
	if (cont < tam-1) {
		printf("%d, ", vetor[cont]);
	} else if (cont < tam) {
		printf("%d", vetor[cont]);
	} else {
		return;
	}
	
	printVetor(vetor, tam, ++cont);
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

void copiaVetor(int* vetorOriginal,int* vetorCopia,int tam, int cont){
	if (cont < tam){
		vetorCopia[cont] = vetorOriginal[cont];
		copiaVetor(vetorOriginal, vetorCopia, tam, ++cont);
	} else {
		return;
	}
}
