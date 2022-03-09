/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/


#include <stdio.h>
#include <stdlib.h>

int main (void){
    int i=0, op;
    float prom,sum=0.0,min;
    do{
        printf("\nMinutos en llamada: "); setbuf(stdin, 0);
        scanf("%f", &min);
        sum+=min;
        i++;
        printf("0) Capturar otra llamada\n1) Salir");
        printf("\nSeleccione una opcion: "); setbuf(stdin, 0);
        scanf("%d", &op);
    }while(op!=1);
    prom=sum/i;
    printf("\nDuracion media de llamada: %.1f minutos", prom);

    return EXIT_SUCCESS;
}