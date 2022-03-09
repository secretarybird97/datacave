/* Miguel Cuevas: 1279713
Programa para calcular dosis de anitibiotico para un perro*/
#include<stdio.h>

/*funcion principal*/
int main(void)
{
    float peso, dosis;
    printf("Este programa calcula la cantidad de antibiotico a administrar a su perro \n");
    printf("Introduzca el peso de su perro en kg: ");

    //funcion de captura
    scanf("%f", &peso);
    dosis = peso*12.5;

    //funcion de salida
    printf("\nCantidad de antibiotico a administrar: %f\n", dosis);

    return 0;
}
