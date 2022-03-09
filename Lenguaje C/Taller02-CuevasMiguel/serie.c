#include <stdio.h>
#include <stdlib.h>

int main (void){
    int sum=0, i;
    printf("El programa terminara hasta que se introduzca un cero!\n\n");
    do{
        printf("Ingrese un numero: "); setbuf(stdin, 0);
        scanf("%d", &i);
        sum+=i;
    }while(i!=0);
    printf("Sumatoria = %d", sum);

    return EXIT_SUCCESS;
}