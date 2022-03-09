#include <stdio.h>
#include <math.h>

int main(void)
{
int h, m, s; //declaracion de variables
    printf("Este programa redondea la hora introducida\n");
    printf("Introducir hora en formato HH/MM/SS de manera secuencial\n\n");

    printf("Introduzca las horas: "); //capturacion de datos
    scanf("%d", &h);
    printf("Introduzca los minutos: ");
    scanf("%d", &m);
    printf("Introduzca los segundos: ");
    scanf("%d", &s);

    if ((s<0)||(m<0)||(h<0)||(s>59)||(m>59)||(h>23))
        printf("Error: formato incorrecto");
    else if ((m==0)&&(s==0))
        printf("%d horas", h);
    else if (s!=59){
        s+=1;
        printf("%d:%d:%d", h,m,s);
    }
    else if (m!=59){
        m+=1;
        printf("%d:%d:00", h,m);
    }
    else if (h!=23){
        h+=1;
        printf("%d horas", h);
    }
    else{
        printf("00:00:00");
    }
    return 0;
}