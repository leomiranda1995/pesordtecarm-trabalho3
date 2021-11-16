#include <stdio.h>
#include <stdlib.h>

void quickSortR(double *vetor, int left, int right) {
	int i, j, x, y;

	i = left;
	j = right;
	x = vetor[(left+right) / 2];

	while(i <= j) {
		while(vetor[i] < x && i < right) {
			i++;
		}

		while(vetor[j] > x && j > left) {
			j--;
		}

		if(i <= j) {
			y = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = y;
			i++;
			j--;
		}
	}

	if(j > left) {
		quickSortR(vetor, left, j);
	}

	if(i < right) {
		quickSortR(vetor, i, right);
	}
}


void bubbleR (double* vetor,int tam){
    int i,j;
    for (i=tam-1; i>=1; i--)
        for (j=0; j<i; j++)
            if (vetor[j]>vetor[j+1]) {
                double temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
}


void mergeR(double *vet, int n) {
  int mid;
  int i, j, k;
  double *tmp;

  tmp = (double *) malloc(n * sizeof(double));
  if (tmp == NULL) {
  	printf("Memoria insuficiente.\n");
    exit(1);
  }

  mid = n / 2;

  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < n) {
    if (vet[i] < vet[j]) {
      tmp[k] = vet[i];
      i++;
    }
    else {
      tmp[k] = vet[j];
      j++;
    }
    k++;
  }

  if (i == mid) {
    while (j < n) {
      tmp[k] = vet[j];
      j++;
      k++;
    }
  }
  else {
    while (i < mid) {
      tmp[k] = vet[i];
      i++;
      k++;
    }
  }

  for (i = 0; i < n; ++i) {
    vet[i] = tmp[i];
  }

  free(tmp);
}

void mergesortR(double *vet, int n) {
  int mid;

  if (n > 1) {
    mid = n / 2;
    mergesortR(vet, mid);
    mergesortR(vet + mid, n - mid);
    mergeR(vet, n);
  }
}

