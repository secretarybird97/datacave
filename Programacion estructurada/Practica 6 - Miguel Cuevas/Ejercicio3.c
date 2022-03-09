#include<stdio.h>

long int factorial(int);
int main (void){
    int n;
    printf("Inserte un numero: ");
    scanf("%d", &n);
    printf("\nEl factorial de %d es igual a %ld", n, factorial(n));

    return 0;
}

long int factorial(int numero){ //funcion que calcula el factorial de 'numero'
    int i;
    for (i=numero-1; i>0; i--){
        numero = numero*i;
    }
    return numero;
}
