#include <stdio.h>
#include <stdlib.h>

int main (void){
    int num, i;
    printf("Inserte un numero: ");
    scanf("%d", &num);
    if(num%2==0){
        printf("\nEl numero capturado es par.", num);
    }
    else{
        printf("\nEl numero capturado es impar.", num);
    }
    printf("\nLos multiplos de 5 son: ");
    for(i=1; i<=50; i++){
        if(i==50){
            printf("%d.", num*i);
        }
        else{
            printf("%d, ", num*i);
        }
    }

    return EXIT_SUCCESS;
}