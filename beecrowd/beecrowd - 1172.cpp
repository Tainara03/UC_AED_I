#include <stdio.h>

int main()
{
    int X[10];
    
    for(int i = 0; i<10; i++){
        scanf("%d", &X[i]);
        //converte todos os números negativos ou zero em 1
        if(X[i] <= 0)
            X[i] = 1;
    }
   
    for(int i=0; i<10; i++)
        printf("X[%d] = %d\n", i, X[i]);
    return 0;
}