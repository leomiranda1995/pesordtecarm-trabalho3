#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "screen.c"
#include "arrays.c"
#include "order.c"
#include "arraysReais.c"
#include "orderReais.c"
#include "arraysStrings.c"
#include "orderStrings.c"
#include "arraysDatas.c"

void NumerosInteiros();
void NumerosReais();
void Palavras();
void Datas();

int main(){
	int opcaoDado, opcaoContinuar;
	srand(time(NULL));

	do {
		cabecalho();
        opcaoDado = opcaoTipoDado();
        cabecalho();

        switch (opcaoDado) {
			case 1:
				NumerosInteiros();
				break;

			case 2:
				NumerosReais();
				break;

			case 3:
				Palavras();
				break;

			case 4:
				Datas();
				break;
		}

		printf("\n\n\n1 - Reiniciar");
		printf("\n0 - Sair\n");
		printf("\nSelecine uma opcao: ");
		scanf("%d", &opcaoContinuar);
	} while(opcaoContinuar != 0);

	cabecalho();

    return 0;
}

void NumerosInteiros(){
	int opcaoVetor, i, tamanho, ordenar;
	clock_t t;

	cabecalho();

	do {
		printf("1 - Gerar numeros aleatorios");
		printf("\n2 - Informar numeros manualmente");
		printf("\n3 - Ler arquivo - O arquivo deve estar com o nome [dados.txt] e numeros separados por ;");

		printf("\n\nSelecione uma opcao: ");
		scanf("%d", &opcaoVetor);
	} while ((opcaoVetor != 1) && (opcaoVetor != 2) && (opcaoVetor != 3));

	tamanho = tamanhoVetor(opcaoVetor);

	int vetor[tamanho];
	int vetorQuickSort[tamanho];
	int vetorMergeSort[tamanho];
	int vetorBubbleSort[tamanho];

	cabecalho();

	switch(opcaoVetor){
		case 1:
			geraVetor(vetor, tamanho, 0);
			break;

		case 2:
			printf("Digite %d numeros inteiros:\n\n", tamanho);
			vetorManual(vetor, tamanho, 0);
			break;

	    case 3:
	    	leArquivo(vetor, tamanho);
	    	break;
	}

	cabecalho();

	// Copia o vetor original para um vetor a ser ordenado
	copiaVetor(vetor,vetorQuickSort,tamanho, 0);
	copiaVetor(vetor,vetorMergeSort,tamanho, 0);
	copiaVetor(vetor,vetorBubbleSort,tamanho, 0);

	printf("Vetor desordenado:\n");
	printVetor(vetor, tamanho, 0);

	// Ordenando o vetor com quickSort
	t = clock();
	quickSort(vetorQuickSort, 0, tamanho-1);
	t = clock() - t;
	printf("\n\n\nVetor de n?meros inteiros ordenado pelo QuickSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetorQuickSort, tamanho, 0);

	//Ordenando o vetor com bubbleSort
	t = clock();
	bubble(vetorBubbleSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor de n?meros inteiros ordenado pelo BubbleSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetorBubbleSort, tamanho, 0);

    //Ordenando o vetor com mergeSort
    t = clock();
	mergesort(vetorMergeSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor de n?meros inteiros ordenado pelo MergeSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetorMergeSort, tamanho, 0);
}

void NumerosReais(){
	int opcaoVetor, i, tamanho, ordenar;
	clock_t t;

	cabecalho();

	do {
		printf("1 - Gerar dados aleatorios");
		printf("\n2 - Informar dados manualmente");
		printf("\n3 - Ler arquivo - O arquivo deve estar com o nome [dados.txt] e valores separados por ;");

		printf("\n\nSelecione uma opcao: ");
		scanf("%d", &opcaoVetor);
	} while ((opcaoVetor != 1) && (opcaoVetor != 2) && (opcaoVetor != 3));

	tamanho = tamanhoVetor(opcaoVetor);

	double vetor[tamanho];
	double vetorQuickSort[tamanho];
	double vetorMergeSort[tamanho];
	double vetorBubbleSort[tamanho];

	cabecalho();

	switch(opcaoVetor){
		case 1:
			geraVetorR(vetor, tamanho, 0);
			break;

		case 2:
			printf("Digite %d numeros reais:\n\n", tamanho);
			vetorManualR(vetor, tamanho, 0);
			break;

	    case 3:
	    	leArquivoR(vetor, tamanho);
	    	break;
	}

	cabecalho();

	// Copia o vetor original para um vetor a ser ordenado
	copiaVetorR(vetor,vetorQuickSort,tamanho, 0);
	copiaVetorR(vetor,vetorMergeSort,tamanho, 0);
	copiaVetorR(vetor,vetorBubbleSort,tamanho, 0);

	printf("Vetor:\n");
	printVetorR(vetor, tamanho, 0);

	// Ordenando o vetor com quickSort
	t = clock();
	quickSortR(vetorQuickSort, 0, tamanho-1);
	t = clock() - t;
	printf("\n\n\nVetor ordenado pelo QuickSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetorR(vetorQuickSort, tamanho, 0);

	//Ordenando o vetor com bubbleSort
	t = clock();
	bubbleR(vetorBubbleSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo BubbleSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetorR(vetorBubbleSort, tamanho, 0);

    //Ordenando o vetor com mergeSort
    t = clock();
	mergesortR(vetorMergeSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo MergeSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetorR(vetorMergeSort, tamanho, 0);
}

void Palavras(){
	int opcaoVetor, tamanho, ordenar;
	clock_t t;

	cabecalho();

	do {
		printf("1 - Gerar letras aleatorias");
		printf("\n2 - Informar letras manualmente");
		printf("\n3 - Ler arquivo - O arquivo deve estar com o nome [caracteres.txt] e as letras no arquivo sem separacao");

		printf("\n\nSelecione uma opcao: ");
		scanf("%d", &opcaoVetor);
	} while ((opcaoVetor != 1) && (opcaoVetor != 2) && (opcaoVetor != 3));

	if (opcaoVetor != 2){
		tamanho = tamanhoVetor(opcaoVetor);		
	} else {
		tamanho = 1000;
	}

	char vetor[tamanho];
	char vetorQuickSort[tamanho];
	char vetorMergeSort[tamanho];
	char vetorBubbleSort[tamanho];
	
	cabecalho();
	
	int qtdDigitada = 0;
	char palavra[1000];

	switch(opcaoVetor){
		case 1:
			geraVetorString(vetor, tamanho, 0);
			break;

		case 2:
			do {
				printf("Digite sua palavra (min 5 - max 1000 letras sem espacos): ");
				scanf("%s", &palavra);
				
				qtdDigitada = strlen(palavra);
				
			} while (qtdDigitada > 1000 || qtdDigitada < 5);
			
			tamanho = qtdDigitada;			
			copiaVetorString(palavra, vetor, tamanho, 0);
			break;

	    case 3:
	    	leArquivoString(vetor, tamanho);
	    	break;
	}

	cabecalho();

	// Copia o vetor original para um vetor a ser ordenado
	copiaVetorString(vetor,vetorQuickSort,tamanho, 0);
	copiaVetorString(vetor,vetorMergeSort,tamanho, 0);
	copiaVetorString(vetor,vetorBubbleSort,tamanho, 0);

	printf("Vetor desordenado:\n");
	printVetorString(vetor, tamanho, 0);

	// Ordenando o vetor com quickSort
	t = clock();
	quickSortString(vetorQuickSort, 0, tamanho-1);
	t = clock() - t;
	printf("\n\n\nVetor de letras ordenado pelo QuickSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetorString(vetorQuickSort, tamanho, 0);

	//Ordenando o vetor com bubbleSort
	t = clock();
	bubbleString(vetorBubbleSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor de letras ordenado pelo BubbleSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetorString(vetorBubbleSort, tamanho, 0);

    //Ordenando o vetor com mergeSort
    t = clock();
	mergesortString(vetorMergeSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor de letras ordenado pelo MergeSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetorString(vetorMergeSort, tamanho, 0);
}

void Datas(){
	int opcaoVetor, i, tamanho, ordenar;
	clock_t t;

	cabecalho();

	do {
		printf("1 - Gerar dados aleatorios");
		printf("\n2 - Informar dados manualmente");
		printf("\n3 - Ler arquivo - O arquivo deve estar com o nome [dados.txt] e valores separados por ;");

		printf("\n\nSelecione uma opcao: ");
		scanf("%d", &opcaoVetor);
	} while ((opcaoVetor != 1) && (opcaoVetor != 2) && (opcaoVetor != 3));

	tamanho = tamanhoVetor(opcaoVetor);

	int vetorDia[tamanho];
	int vetorMes[tamanho];
	int vetorAno[tamanho];
	//char vetorData[tamanho][10];
	int vetorQuickSort[tamanho];
	int vetorMergeSort[tamanho];
	int vetorBubbleSort[tamanho];

	cabecalho();

	switch(opcaoVetor){
		case 1:
			geraVetorD(vetorDia,vetorMes,vetorAno, tamanho, 0);
			break;

		case 2:
            printf("Digite %d Datas entre 01/01/1900 e 31/12/2100 no formato dd/mm/aaaa:\n\n", tamanho);
			vetorManualD(vetorDia,vetorMes,vetorAno, tamanho, 0);
            break;

	    case 3:
	        printf("\nAs datas devem estar no formato dd/mm/aaaa.");
	    	leArquivoD(vetorDia,vetorMes,vetorAno, tamanho);
	    	break;
	}

	cabecalho();

	//cria vetor Data
  //  criaVetorData(vetorDia,vetorMes,vetorAno,vetorData,tamanho,0);
    //for (int i=0;i<tamanho;i++){
   //    printf("%c",vetorData[i]);
   // }

	// Copia o vetor original para um vetor a ser ordenado
//	copiaVetorD(vetorData,vetorQuickSort,tamanho, 0);
//	copiaVetorD(vetorData,vetorMergeSort,tamanho, 0);
//	copiaVetorD(vetorData,vetorBubbleSort,tamanho, 0);

	printf("Vetor:\n");
	printVetorD(vetorDia,vetorMes,vetorAno, tamanho, 0);
/*
	// Ordenando o vetor com quickSort
	t = clock();
	quickSort(vetorQuickSort, 0, tamanho-1);
	t = clock() - t;
	printf("\n\n\nVetor ordenado pelo QuickSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetorQuickSort, tamanho, 0);

	//Ordenando o vetor com bubbleSort
	t = clock();
	bubble(vetorBubbleSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo BubbleSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetorBubbleSort, tamanho, 0);

    //Ordenando o vetor com mergeSort
    t = clock();
	mergesort(vetorMergeSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo MergeSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetorMergeSort, tamanho, 0);
*/}
