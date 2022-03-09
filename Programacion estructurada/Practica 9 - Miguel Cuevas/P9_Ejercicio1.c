#include <stdio.h>
#include <stdlib.h>

void arreglo_primos(int*);
void print_array(int*, int);
int primo(int);

int main(void){
    int *ptr=NULL;

    arreglo_primos(ptr);

    printf("%d\n", *ptr);
    return 0;
}

void arreglo_primos(int* array){
    int xi, xs;
    printf("\nLimite inferior: ");
    scanf("%d", &xi);
    printf("Limite superior: ");
    scanf("%d", &xs);
    int i=0;
    do{
        if(primo(xi)){
            i++;
            if(!array){
                array = malloc(sizeof(int));
            }
            else{
                array = realloc(array, sizeof(int)*i);
            } 
            array[i-1]=xi;
        }
        xi++;
    }while(xi<=xs);
    print_array(array, i);
}

void print_array(int* array, int tam){
    while(tam>0){
        printf("%d\n", *array);
        array++;
        tam--;
    }
}

int primo(int x){
    int d=0, i=1;
    if(x==0 || x==1){
        return 0;
    }
    while(i<x){
        if(x%i==0){
            d++;
        }
        i++;
    }
    if(d<=1){
        return 1;
    }
    else{
        return 0;
    }
}