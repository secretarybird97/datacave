#include <stdio.h>
#include <math.h>

void dsegundos(int[], int[], char);
int main(void){

    int k=0, h[3], h2[3]; float x; char opt;
    while(k==0){ //verifica que el formato de entrada sea correcto
        printf("Inserte la hora inicial (HH:MM:SS): ");
        scanf("%d:%d:%d", &h[0], &h[1], &h[2]);
        printf("Inserte la hora final: ");
        scanf("%d:%d:%d", &h2[0], &h2[1], &h2[2]);
        if ((h[0]<0 || h[0]>23) || (h[1]<0 || h[1]>59) || (h[2]<0 || h[2]>59) || (h2[0]<0 || h2[0]>23) || (h2[1]<0 || h2[1]>59) || (h2[2]<0 || h2[2]>59)){
            printf("\nHora invalida, introduzca una hora valida.\n");
        }
        else{
            k=1;
        }
    }
    k=0;
    while(k==0){ //verifica que el formato de salida sea correcto
        printf("\nSeleccione el formato de salida:\nH: horas\nM: Minutos\nS: Segundos\nIngrese una opcion: ");
        scanf(" %c", &opt);
        if (opt=='H' || opt=='M' || opt=='S'){
            k=1;
        }
        else{
            printf("\nFormato invalido, selecciona una opcion.\n");
        }
    }
    dsegundos(h, h2, opt); //funcion
    return 0;
}

void dsegundos(int x[3], int y[3], char opt){ //imprime la diferencia entre dos horas
    float r; int s;
    switch (opt){
        case 'H':
            r = fabs((x[0]+(x[1]/60.0)+(x[2]/3600.0))-(y[0]+(y[1]/60.0)+(y[2]/3600.0)));
            printf("\nDiferencia entre %d:%d:%d y %d:%d:%d es de %.2f horas", x[0], x[1], x[2], y[0], y[1], y[2], r);
            break;
        case 'M':
            r = fabs(((x[0]*60)+x[1]+(x[2]/60.0))-((y[0]*60)+y[1]+(y[2]/60.0)));
            printf("\nDiferencia entre %d:%d:%d y %d:%d:%d es de %.2f minutos", x[0], x[1], x[2], y[0], y[1], y[2], r);
            break;
        case 'S':
            s = abs(((x[0]*3600)+(x[1]*60)+x[2])-((y[0]*3600)+(y[1]*60)+y[2]));
            printf("\nDiferencia entre %d:%d:%d y %d:%d:%d es de %d segundos", x[0], x[1], x[2], y[0], y[1], y[2], s);
            break;
        default:
            break;
    }
}