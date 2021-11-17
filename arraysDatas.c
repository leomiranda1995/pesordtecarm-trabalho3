#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVetorD(int* vetorD,int* vetorM,int* vetorA, int tam, int cont) {
    if (cont < tam) {
        vetorD[cont] = 1+rand()%30;
        vetorM[cont] = 1+rand()%12;
        vetorA[cont] = 1900+rand()%200;
        geraVetorD(vetorD,vetorM,vetorA, tam, ++cont);
    } else {
        return;
    }
}

void vetorManualD(int* vetorD,int* vetorM,int* vetorA, int tam, int cont) {
	if (cont < tam){
        do{
            printf("\nData %d -> ", cont+1);
            scanf("%02d/%02d/%04d", &vetorD[cont], &vetorM[cont], &vetorA[cont]);
        } while (((vetorD[cont] > 31) || (vetorD[cont] < 1)) || ((vetorM[cont] > 12) || (vetorM[cont] < 1)) || ((vetorA[cont] < 1900) || (vetorA[cont] > 2100)) );
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
/*
void criaVetorData(int* vetorD,int* vetorM,int* vetorA,char* vetorDt,int tam,int cont){
    char aux[10];
    if(cont < tam){
        sprintf(aux,"%02d/%02d/%02d",vetorD[cont],vetorM[cont],vetorA[cont]);
        vetorDt[cont] = aux;
        criaVetorData(vetorD,vetorM,vetorA,vetorDt,tam,++cont);
    }else {
        return;
    }
}*/

void copiaVetorD(int* vetorOriginal,int* vetorCopia,int tam, int cont){
	if (cont < tam){
		vetorCopia[cont] = vetorOriginal[cont];
		copiaVetorD(vetorOriginal, vetorCopia, tam, ++cont);
	} else {
		return;
	}
}

void printVetorD(int *vetorD,int *vetorM, int *vetorA, int tam, int cont){
	if (cont < tam-1) {
		printf("%02d/%02d/%04d, ", vetorD[cont],vetorM[cont],vetorA[cont]);
		//printf("%s/%s/%s, ", vetorD[cont],vetorM[cont],vetorA[cont]);
	} else if (cont < tam) {
		printf("%02d/%02d/%04d ", vetorD[cont],vetorM[cont],vetorA[cont]);
	} else {
		return;
	}
	printVetorD(vetorD,vetorM,vetorA, tam, ++cont);
}
/*
// checks valid date
int isvalid ( )
{
    int isleap ( long int ) ;

    if ( y <= 0 || m <= 0 || d <= 0 || m > 12 || y > 16384 ||
         ( m == 2 && !isleap ( y ) && d > 28 ) ||
         ( m == 2 && isleap ( y ) && d > 29 ) ||
         ( ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10
          || m == 12 ) && d > 31 ) || ( ( m == 4 || m == 6 || m == 9 ||
             m == 11 ) && d > 30 ) )
        return 0 ;
    else
        return 1 ;
}

// checks whether the given year is leap or not
int isleap ( long int y )
{
    return ( y % 4 == 0 ) ^ ( y % 100 == 0 ) ^ ( y % 400 == 0 ) ;
}

// converts dates in string into equivalent integer values
long int getnum ( char *date )
{
    char *p, str[15] ;
    long int num = 0 ;

    strcpy ( str, date ) ;

    d = m = y = 0 ;
    p = strtok ( str, "/" ) ;
    if ( p != NULL )
        d = num = atoi ( p )  ;

    p = strtok(NULL, "/");
    if ( p != NULL )
        m = atoi ( p ) ;
    num += m * 32 ;

    p = strtok(NULL, "/");
    if ( p != NULL )
        y = atol ( p ) ;
    num += y * 512L ;

    return num ;
}
*/
