#include <stdio.h>
#include <stdlib.h>

#include "arrays.c"
#include "order.c"

void limpaTela(){
	system("cls");
	
	printf("Alunos do Trabalho");
	printf("\n\nLeonardo da Silva Miranda - alu2017110378");
	printf("\nJeferson Ferreira dos Santos - alu201522688");
	printf("\nGilmar Bernardes dos Santos Junior - alu202013348");
	printf("\n\n-------------------------------------------------\n\n");
}

int tamanhoVetor(){
	int tamanho;
	do {
        // ******************alterar para 100 na entrega*************************
        limpaTela();
		printf("Digite a quantidade de dados do vetor (minimo 10): ");
		scanf("%d", &tamanho);
	} while(tamanho < 10);
	
	return tamanho;
}

int opcaoTipoDado(){
	int opcao;
	
	do {
		printf("1 - Numeros Inteiros");
		printf("\n2 - Numeros Reais");
		printf("\n3 - Palavras");
		printf("\n4 - Datas\n");
		printf("\nDigite o tipo de dado a ser inserido: ");
		scanf("%d", &opcao);
	} while((opcao != 1) && (opcao != 2) && (opcao != 3) && (opcao != 4));
	
	return opcao;
}


int main(){
	int tamanho, opcaoDado, opcaoContinuar, opcaoVetor, nomeArquivo, i;

	limpaTela();

	do {
        opcaoDado = opcaoTipoDado();
        
        switch (opcaoDado) {
			case 1:
				tamanho = tamanhoVetor();
				
				limpaTela();
				
				do {
					printf("1 - Gerar dados aleatorios");
					printf("\n2 - Informar dados manualmente");
					printf("\n3 - Ler arquivo - O arquivo deve estar com o nome dados.txt e valores separados por ;");
		
					printf("\n\nSelecione uma opcao: ");
					scanf("%d", &opcaoVetor);
		
				} while ((opcaoVetor != 1) && (opcaoVetor != 2) && (opcaoVetor != 3));
				
				limpaTela();
		
		        int vetInt[tamanho];
		        int vetIntCopia[tamanho];
				int comparacoes;
		
				if (opcaoDado == 1){
		
		            if (opcaoVetor == 1){
					geraVetor(vetInt, tamanho, 0);
		            } else if (opcaoVetor == 2) {
		                printf("\nDigite %d numeros inteiros:\n", tamanho);
		                for (i = 0; i < tamanho; i++){
		                    scanf("%d", &vetInt[i]);
		                }
		            } else if (opcaoVetor == 3){
		                leArquivo(vetInt, tamanho);
		            } else {
		                return;
		            }
		        }
		
				printf("Vetor:\n");
				printVetor(vetInt, tamanho, 0);
		
				//Copia o vetor orginal para ordenação
				copiaVetor(vetInt,vetIntCopia,tamanho);
		
				// Ordenando o vetor com quickSort
				quickSort(vetIntCopia, 0, tamanho-1);
		        //Informações quickSort
				printf("\n\nVetor ordenado quickSort:\n");
				printVetor(vetIntCopia, tamanho, 0);
		
		
		        //Copia o vetor orginal para ordenação
		        copiaVetor(vetInt,vetIntCopia,tamanho);
		
		        //Ordenando o vetor com mergeSort
				mergesort(vetIntCopia,tamanho);
				//Informações mergeSort
				printf("\n\nVetor ordenado mergeSort:\n");
				printVetor(vetIntCopia, tamanho, 0);
		
		
				//Copia o vetor orginal para ordenação
		        copiaVetor(vetInt,vetIntCopia,tamanho);
		
				//Ordenando o vetor com bubble
				bubble(vetIntCopia,tamanho);
				//Informações bubble
				printf("\n\nVetor ordenado bubble:\n");
				printVetor(vetIntCopia, tamanho, 0);
				break;
		}


		printf("\n\n0 - Sair\n1 - Reiniciar\n");
		scanf("%d", &opcaoContinuar);

	} while(opcaoContinuar != 0);

    return 0;
}
