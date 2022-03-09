#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL)); //semilla para generar diferentes secuencias de numeros aleatorios
    int i, j, num, x=1; //i y j son contadores; num = numero random;
    int calificaciones[50], frecuencia[10];
    for(i=0; i<50; i++){
        num = rand() % (10) +1; //generacion de numero aleatorio
        calificaciones[i]=num;
    }
    for(i=0; i<10; i++){
        frecuencia[i]=0;
        for(j=0; j<50; j++){
            if(calificaciones[j]==x){
                frecuencia[i]+=1;
            }
        }
        x+=1;
    }

    printf("\nCalificaciones\tFrecuencia\tHistograma"); //generacion de tabla
    for(i=0; i<10; i++){
        printf("\n%-5d\t        %-10d\t", i+1, frecuencia[i]);
        for(j=0; j<frecuencia[i]; j++) printf("*"); //histograma
    }
    return 0;
}
