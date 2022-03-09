#include<stdio.h>
#include <stdlib.h>
#include <math.h>

void arreglo_primos(int*);
void imprime_arreglo(int*, int);
float evaluar(float*, int, float);

int main(void){
    int size, i=0, k=0, tama;
    float *poly=NULL, x, u;
    printf("\nGrado del polinomio: ");
    scanf("%d", &size);
    i = size;
    do{
        printf("Valor del coeficiente de X^%d: ", i);
        scanf("%f", &x);
        k++;
        if(!poly){
            poly = malloc(sizeof(float));
        }
        else{
            poly = realloc(poly, sizeof(float)*k);
        }
        poly[k-1] = x;
        i--;
    }while(i>=0);
    printf("En que valor desea evaluar el polinomio? ");
    scanf("%f", &u);
    printf("\nResultado = %.3f", evaluar(poly, size, u));
    return 0;
}

float evaluar(float *array, int tam, float x){
    float resultado=0;
    while(tam>=0){
        resultado+= *array*(pow(x, tam));
        tam--;
        array++;
    }
    return resultado;
}