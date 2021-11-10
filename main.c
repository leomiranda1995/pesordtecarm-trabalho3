#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "screen.c"
#include "arrays.c"
#include "order.c"

void NumerosInteiros();

int main(){	
	int opcaoDado, opcaoContinuar;
	srand(time(NULL));
	
	do {
		cabecalho();
        opcaoDado = opcaoTipoDado();
        
        switch (opcaoDado) {
			case 1:				
				NumerosInteiros();
				break;
		}

		printf("\n\n0 - Sair");
		printf("\n1 - Reiniciar\n");
		scanf("%d", &opcaoContinuar);
	} while(opcaoContinuar != 0);
	
	cabecalho();

    return 0;
}

void NumerosInteiros(){
	int opcaoVetor, i, tamanho;
	clock_t t;
	
	tamanho = tamanhoVetor();
	
	int vetor[tamanho];	
	int vetorQuickSort[tamanho];
	int vetorMergeSort[tamanho];
	int vetorBubbleSort[tamanho];
	
    int vetIntCopia[tamanho];
	
	cabecalho();
	
	do {
		printf("1 - Gerar dados aleatorios");
		printf("\n2 - Informar dados manualmente");
		printf("\n3 - Ler arquivo - O arquivo deve estar com o nome dados.txt e valores separados por ;");

		printf("\n\nSelecione uma opcao: ");
		scanf("%d", &opcaoVetor);

	} while ((opcaoVetor != 1) && (opcaoVetor != 2) && (opcaoVetor != 3));
	
	cabecalho();
	
	switch(opcaoVetor){
		case 1:
			geraVetor(vetor, tamanho, 0);
			break;
		
		case 2:
			printf("\nDigite %d numeros inteiros:\n", tamanho);
	        for (i = 0; i < tamanho; i++){
	            scanf("%d", &vetor[i]);
	        }
	        
	    case 3:
	    	leArquivo(vetor, tamanho);
	    	break;
	}
	
	// Copia o vetor original para um vetor a ser ordenada	
	copiaVetor(vetor,vetorQuickSort,tamanho);	
	copiaVetor(vetor,vetorMergeSort,tamanho);
	copiaVetor(vetor,vetorBubbleSort,tamanho);

	printf("Vetor original:\n");
//	printVetor(vetor, tamanho, 0);
	
	// Ordenando o vetor com quickSort
	t = clock();
	quickSort(vetorQuickSort, 0, tamanho-1);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo QuickSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
//	printVetor(vetorQuickSort, tamanho, 0);

    //Ordenando o vetor com mergeSort
    t = clock();
	mergesort(vetorMergeSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo MergeSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
//	printVetor(vetorMergeSort, tamanho, 0);

	//Ordenando o vetor com bubble
	t = clock();
	bubble(vetorBubbleSort,tamanho);
	t = clock() - t;
	printf("\n\nVetor ordenado pelo BubbleSort: (Tempo de execucao: %2f ms)\n",  ((double)t)/((CLOCKS_PER_SEC/1000)));
//	printVetor(vetorBubbleSort, tamanho, 0);
}
