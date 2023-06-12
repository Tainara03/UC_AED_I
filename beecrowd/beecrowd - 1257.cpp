#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    scanf("%d", &a);
    
    while(a--){
        int b, c = 0;
        scanf("%d", &b);
        while(b--){
            char x[501];
            scanf("%s", x);
            c += val(x,b);
        }
        
        printf("%d\n", c);
    }
    
    return 0;
}

int val(char *a, int b){
    int alf, tot = 0;
    for(int c = 0; a[c];c++){
        alf = a[c] - 65;
        tot += (alf + b + c);
    }
    
    return tot;
}
