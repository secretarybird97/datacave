#include<stdio.h>

void secuencia(int); //prototipo de funcion
int main(void){
    secuencia(5);
    return 0;
}

void secuencia(int x){ //imprime el promedio, numero mayor y numero menor de una secuancia de numeros
    printf("\nA continuacion ingresa %d numeros, o finaliza la secuencia ingresando %d\n", x, -1);
    int k=1, i=0; float prom, c, sum=0, max, min;
    do{
        printf("Ingresa un numero: "); 
        scanf("%f", &c); //captura los numeros
        if(c==-1){
            k=0;
            break;
        }
        if(i==0){
            max=c;
            min=c;
        }
        else{
            if(c>max){
                max=c;
            }
            if(c<min){
                min=c;
            }
        }
        sum+=c;
        i++;
    }while(k==1 && i<x);
    prom = sum/i;
    printf("\n\nNumero mayor = %.2f\nNumero menor = %.2f\nPromedio = %.2f", max, min, prom);
}