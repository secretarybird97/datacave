/* Miguel Cuevas: 1279713
Programa para calcular el numero de segundos en determinado tiempo*/
#include<stdio.h>

/*funcion principal*/
int main(void)
{
    int D, H, M, S, Total;
    printf("Este programa calcula la cantidad de segundos en un tiempo determinado. \n");
    printf("Introduzca x Dias: ");
    scanf("%d", &D); //funcion de captura
    printf("\nIntroduzca x Horas: ");
    scanf("%d", &H); //funcion de captura
    printf("\nIntroduzca x Minutos: ");
    scanf("%d", &M); //funcion de captura
    printf("\nIntroduzca x Segundos: ");
    scanf("%d", &S); //funcion de captura

    Total = S +M*60 +H*60*60 + D*60*60*24;

    //funcion de salida
    printf("\nEn %d dias, %d horas, %d minutos y %d segundos hay en total: %d segundos\n", D, H, M, S, Total);

    return 0;
}
