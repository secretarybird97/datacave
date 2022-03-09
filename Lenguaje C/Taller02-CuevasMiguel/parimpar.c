#include <stdio.h>
#include <stdlib.h>

int main (void){
    int num;
    printf("Inserte un numero: ");
    scanf("%d", &num);
    if(num%2==0){
        printf("\n%d es un numero par.", num);
    }
    else{
        printf("\n%d es un numero impar.", num);
    }

    return EXIT_SUCCESS;
}