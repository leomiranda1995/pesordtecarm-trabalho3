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

int tamanhoVetor(){
	int tamanho;
	do {
        // ******************alterar para 100 na entrega*************************
        cabecalho();
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
