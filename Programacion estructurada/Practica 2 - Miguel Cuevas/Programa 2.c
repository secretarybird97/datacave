/* Miguel Cuevas: 1279713
Programa para convertir unidades: centigrados a Fahrenheit*/
#include<stdio.h>

/*funcion principal*/
int main(void)
{
    float cel, fahr;
    printf("Este programa convierte grados Celcius a grados Farenheit.\n");
    printf("Introduzca la temperatura del ambiente en grados Celsius: ");

    //funcion de captura
    scanf("%f", &cel);

    //25.4mm = 1 pulgada
    fahr = cel*(9.0/5)+32;

    //funcion de salida
    printf("\n%f grados Celsius equivalen a %f grados Farenheit\n", cel, fahr);

    return 0;
}
