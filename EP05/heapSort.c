#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int array[], int x, int i) {
    int tam = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < x && array[l] > array[tam]) {
        tam = l;
    }

    if (r < x && array[r] > array[tam]) {
        tam = r;
    }

    if (tam != i) {
        int aux = array[i];
        array[i] = array[tam];
        array[tam] = aux;

        heapify(array, x, tam);
    }
}

void heapSort(int array[], int x) {
    int i;
    for (i = x / 2 - 1; i >= 0; i--) {
        heapify(array, x, i);
    }

    for (i = x - 1; i >= 0; i--) {
        int aux = array[0];
        array[0] = array[i];
        array[i] = aux;

        heapify(array, i, 0);
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

    heapSort(array, n);
    
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