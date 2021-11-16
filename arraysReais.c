
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_double(){
    return ((double)rand())/((double)RAND_MAX);
}
double rand_double_intervalo(double x, double y){
    return rand_double() * (y-x) + x;
}

void geraVetorR(double* vetor, int tam, int cont) {
	if (cont < tam) {
		vetor[cont] = rand_double_intervalo(0,1000)
		geraVetorR(vetor, tam, ++cont);
	} else {
		return;
	}
}

void vetorManualR(double* vetor, int tam, int cont) {
	if (cont < tam){
		printf("%d -> ", cont+1);
		scanf("%f", &vetor[cont]);
		vetorManualR(vetor, tam, ++cont);
	} else {
		return;
	}
}

void leArquivoR(double* vetor, int tam){
    int i;

    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        return;
    }

    for(i=0; i<tam; i++){
        fscanf(arquivo, "%f;", &vetor[i]);
    }

    fclose(arquivo);
}

void copiaVetorR(double* vetorOriginal,double* vetorCopia,int tam, int cont){
	if (cont < tam){
		vetorCopia[cont] = vetorOriginal[cont];
		copiaVetorR(vetorOriginal, vetorCopia, tam, ++cont);
	} else {
		return;
	}
}

void printVetorR(double *vetor, int tam, int cont){
	if (cont < tam-1) {
		printf("%2f, ", vetor[cont]);
	} else if (cont < tam) {
		printf("%2f", vetor[cont]);
	} else {
		return;
	}

	printVetorR(vetor, tam, ++cont);
}
