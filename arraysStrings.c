#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVetorString(char* vetor, int tam, int cont) {
    if (cont < tam) {
        vetor[cont] = 97 + (char)(rand() % 26);
//        printf("\nVetor[%d] = %c", cont, vetor[cont]);
        geraVetorString(vetor, tam, ++cont);
    } else {
        return;
    }
}

void vetorManualString(char* vetor, int tam, int cont) {	
	if (cont < tam) {
		printf("%d -> ", cont+1);
//		scanf("%c", &vetor[cont]);
		vetor[cont] = 97 + (char)(rand() % 26);
		printf("%c\n", vetor[cont]);
		
//        printf("\nVetor[%d] = %c\n", cont, vetor[cont]);
        
        vetorManualString(vetor, tam, ++cont);
    } else {
        return;
    }
}

void leArquivoString(char* vetor, int tam){
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

void copiaVetorString(char* vetorOriginal,char* vetorCopia,int tam, int cont){
	if (cont < tam){
		vetorCopia[cont] = vetorOriginal[cont];
		copiaVetorString(vetorOriginal, vetorCopia, tam, ++cont);
	} else {
		return;
	}
}

void printVetorString(char *vetor, int tam, int cont){
	if (cont < tam-1) {
		printf("%c, ", vetor[cont]);
	} else if (cont < tam) {
		printf("%c", vetor[cont]);
	} else {
		return;
	}

	printVetorString(vetor, tam, ++cont);
}
