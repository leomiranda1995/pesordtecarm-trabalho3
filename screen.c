#include <stdio.h>
#include <stdlib.h>

void cabecalho(){
	system("cls");
	
	printf("Alunos do Trabalho");
	printf("\n\nLeonardo da Silva Miranda - alu2017110378");
	printf("\nJeferson Ferreira dos Santos - alu201522688");
	printf("\nGilmar Bernardes dos Santos Junior - alu202013348");
	printf("\n\n-------------------------------------------------\n\n");
}

int tamanhoVetor(int opcao){
	int tamanho;
	int minimo;
	
	if (opcao == 2){
		minimo = 5;
	} else {
		minimo = 10; // -> Alterar para 100 antes de entregar
	}
	
	do {
        cabecalho();

		printf("Digite a quantidade de dados do vetor (minimo %d): ", minimo);
				
		scanf("%d", &tamanho);
	} while((tamanho < minimo) || (tamanho < 1));
	
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
