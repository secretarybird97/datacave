#include<stdio.h>

void muestra_primos(int, int);
int main (void){
    muestra_primos(2,50);
    return 0;
}

void muestra_primos(int x, int y){
    int num, i, d, k=0; //d cuenta el numero de divisores; k cuenta la cantidad de numeros primos en el rango establecido
    for(num=x; num<y+1; num++){
        i=1;
        d=0;
        while(i<num){
            if (num%i==0){
                d+=1;
                }
            i+=1;
        }
        if (d<=1){
            k++;
            if(k!=1){
                printf(",");
            }
            printf("%d", num);
        }
    }
}