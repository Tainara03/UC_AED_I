#include <stdio.h>
 
int main() {
 
    int qtdCase, qtdNumber, var[20];

    scanf("%d", &qtdCase);
    scanf("%d", &qtdNumber);
    
    for(int j = 0; j < qtdCase; j++){
        for(int i = 0; i < qtdNumber; i++){
            scanf("%d", var[i]);
        }
        printf("Case %d:\n", j);
        Pre(var);
        In(var);
        Post(var);
    }
 
    return 0;
}

void Pre(int var[]){
    
    printf("Pre.:");
    
    
}

void In(int var[]){
    
    printf("In..:");
    
    
}

void Post(int var[]){
    
    printf("Post:");
    
    
}
