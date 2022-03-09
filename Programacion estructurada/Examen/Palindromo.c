#include<stdio.h>

int main(void){
    char frase[25];
    int i=0, car=0, k, opt=1;
    printf("Escriba una frase (no utilice espacios): ");
    scanf("%s", frase);
    while(frase[i]!='\x0'){
        car+=1;
        i++;
    }
    k=car-1;
    for(i=0; i<car+1; i++){
        if(frase[i]!=frase[k]){
            opt=0;
        }
        k-=1;
    }
    if(opt==1){
        printf("La frase <%s> es un palindromo", frase);
    }
    else{
        printf("La frase <%s> no es un palindromo:(", frase);
    }
    return 0;
}
