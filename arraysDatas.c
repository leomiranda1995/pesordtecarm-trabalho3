#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVetorD(int* vetorD,int* vetorM,int* vetorA, int tam, int cont) {
    if (cont < tam) {
        vetorD[cont] = rand()%31;
        vetorM[cont] = rand()%13;
        vetorA[cont] = rand()%3001;
        geraVetorD(vetorD,vetorM,vetorA, tam, ++cont);
    } else {
        return;
    }
}

void vetorManualD(int* vetorD,int* vetorM,int* vetorA, int tam, int cont) {
	if (cont < tam){
		printf("Data %d -> Digite o dia:\n", cont+1);
		scanf("%02d", &vetorD[cont]);
        printf("Data %d -> Digite o mes:\n", cont+1);
		scanf("%02d", &vetorM[cont]);
		printf("Data %d -> Digite o ano:\n", cont+1);
		scanf("%04d", &vetorA[cont]);
		vetorManualD(vetorD,vetorM,vetorA, tam, ++cont);
	} else {
		return;
	}
}

void leArquivoD(int* vetorD,int* vetorM,int* vetorA, int tam){
    int i;

    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        return;
    }

    for(i=0; i<tam; i++){
        fscanf(arquivo, "%02d/", &vetorD[i]);
        fscanf(arquivo, "%02d/", &vetorM[i]);
        fscanf(arquivo, "%04d;", &vetorA[i]);
    }

    fclose(arquivo);
}

void criaVetorData(int* vetorD,int* vetorM,int* vetorA,int* vetorDt,int tam,int cont){
    if(cont < tam){
        vetorDt[cont] = (((vetorA*10000)+vetorM)*100)+vetorD;
    criaVetorData(vetorD;vetorM;vetorA;vetorDt;tam;++cont);
    }else {
        return;
    }
}

void copiaVetorD(int* vetorOriginal,int* vetorCopia,int tam, int cont){
	if (cont < tam){
		vetorCopia[cont] = vetorOriginal[cont];
		copiaVetorD(vetorOriginal, vetorCopia, tam, ++cont);
	} else {
		return;
	}
}

void printVetorD(int *vetor, int tam, int cont){
    int d,m,a;

	if (cont < tam-1) {
		printf("%d, ", vetor[cont]);
	} else if (cont < tam) {
		printf("%d", vetor[cont]);
	} else {
		return;
	}

	printVetor(vetor, tam, ++cont);
}

