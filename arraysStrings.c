#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVetorString(char* vetor, int tam, int cont) {
    if (cont < tam) {
        vetor[cont] = 97 + (char)(rand() % 26);
        geraVetorString(vetor, tam, ++cont);
    } else {
        return;
    }
}

void vetorManualString(char* vetor, int tam, int cont) {	
	if (cont < tam){
		printf("%d -> ", cont+1);
		scanf("%s", &vetor[cont]);		
		vetorManualString(vetor, tam, ++cont);
	} else {
		return;
	}
}

void leArquivoString(char* vetor, int tam){
    int i;

    FILE *arquivo;
    arquivo = fopen("caracteres.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        return;
    }

    for(i=0; i<tam; i++){
        fscanf(arquivo, "%s;", &vetor[i]);
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
