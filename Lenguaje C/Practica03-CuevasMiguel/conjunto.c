#include <stdio.h>
#include <stdlib.h>

int main(void){
    int max, min, n, i, num;
    printf("Cuantos numeros quiere capturar? ");
    scanf("%d", &n);
    for(i=0; i<=n; i++){
        printf("Inserte un numero: ");
        scanf("%d", &num);
        if(i==0){
            max=num;
            min=num;
        }
        else if(num<min){
            min=num;
        }
        else if(num>max){
            max=num;
        }
    }
    printf("\nMayor: %d", max);
    printf("\nMenor: %d", min);

    return EXIT_SUCCESS;
}