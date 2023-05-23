#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	char frase[40], word[10] = "zelda";
	int i,j,tam_frase,tam_word,x=0,aux_i=0;
	
	scanf(" %39[^\n]",&frase);
	
	tam_word= strlen(word); 
	tam_frase = strlen(frase);
	
	for (i=0;i<tam_frase;i++){

		if (word[0]==tolower(frase[i])){
			aux_i=i;
			x=0;
			for(j=0;j<tam_word;j++){
				if(word[j]==tolower(frase[aux_i])){
					x++;					
				}
				aux_i++;
			}
			if (x>=tam_word){
			    printf("Link Bolado\n");
			    return 0;
			}
		}	
	}
	
	printf("Link Tranquilo\n");
	
	return 0;
}