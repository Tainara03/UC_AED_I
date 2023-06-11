#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
 
    int n, k;
    char nome[30];
 
    scanf("%d", &n);
    scanf("%d", &k);
    
    char name[n][30];
    
    for (int x = 0; x < n; x++){
        scanf("%s", nome);
        strcpy(name[x], nome);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(name[j], name[i]) > 0)
            {
                char aux[30];
                strcpy(aux, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], aux);
            }
        }
    }

    printf("%s\n", name[k - 1]);
    
    return 0;
}