#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int a, int b, int c) {
    int i, j, k;
    int n1 = b - a + 1;
    int n2 = c - b;

    int A[n1], C[n2];

    for (i = 0; i < n1; i++) {
        A[i] = array[a + i];
    }
    for (j = 0; j < n2; j++) {
        C[j] = array[b + 1 + j];
    }

    i = 0;
    j = 0;
    k = a;
    while (i < n1 && j < n2) {
        if (A[i] <= C[j]) {
            array[k] = A[i];
            i++;
        }
        else {
            array[k] = C[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = A[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = C[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int a, int c) {
    if (a < c) {
        int b = a + (c - a) / 2;
        mergeSort(array, a, b);
        mergeSort(array, b + 1, c);
        merge(array, a, b, c);
    }
}

int main() {
    int n;
    printf("Informe o valor de n: ");
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++){
        array[i] = rand() % 100;
    }

    clock_t ini, fim;
    double timer;

    // método para contabilizar o tempo
    ini = clock();

    mergeSort(array, 0, n-1);
    
    //fim da contagem do tempo
    fim = clock();

    timer = ((double) (fim - ini)) / (CLOCKS_PER_SEC / 1000);

    printf("Array aleatório em ordem crescente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nTempo de execução do código (em milissegundos): %f", timer);

    return 0;
}