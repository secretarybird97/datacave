/* Miguel Cuevas: 1279713
Programa para convertir unidades de pulgadas a milimetros*/
#include<stdio.h>

/*funcion principal*/
int main(void)
{
    float inch, mm;
    printf("Este programa convierte unidades\n");
    printf("Introduzca la cantidad de lluvia que se ha presentado este año en pulgadas: ");

    //funcion de captura
    scanf("%f", &inch);

    //25.4mm = 1 pulgada
    mm = inch * 25.4;

    //funcion de salida
    printf("\n%f in de lluvia equivalen a %f mm de lluvia\n", inch, mm);

    return 0;
}
