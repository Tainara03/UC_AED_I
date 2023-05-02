#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int x) {
    int i, k, aux;

    for (i = 0; i < x-1; i++) {
        aux = i;
        for (k = i+1; k < x; k++) {
            if (array[k] < array[aux]) {
                aux = k;
            }
        }
        int temp = array[i];
        array[i] = array[aux];
        array[aux] = temp;
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

    selectionSort(array, n);
    
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