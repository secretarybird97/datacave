/* Miguel Cuevas: 1279713
Programa para calcular el area y perimetro de un terreno mediante el ancho*/
#include<stdio.h>

/*funcion principal*/
int main(void)
{
    float ancho, largo, perimetro, area;
    printf("Este programa calcula el perimetro y el area de un terreno.\n");
    printf("Inserte el ancho del terreno en m: ");

    //funcion de captura
    scanf("%f", &ancho);
    largo = ancho*3;
    perimetro = 2*(ancho+largo);
    area = ancho*largo;

    //funcion de salida
    printf("\nArea = %.3f m  |  Perimetro = %.3f m", area, perimetro);

    return 0;
}
