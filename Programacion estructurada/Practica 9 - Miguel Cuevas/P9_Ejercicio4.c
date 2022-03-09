#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 25

void aleatorios(int*, int);
void print_array(int*, int);
int* obtener_unicos(int*, int, int*);
int main(void){
    srand(time(NULL));
    int array[TAM], *unicos, size_unicos;
    aleatorios(array, TAM);
    print_array(array, TAM);
    unicos = obtener_unicos(array, TAM, &size_unicos);
    print_array(unicos, size_unicos);
    printf("\nNumero de numeros unicos en el arreglo: %d", size_unicos);

    return 0;
}

void aleatorios(int* array, int size)
{
    while(size--) *(array++)=rand() % 11;
}

int* obtener_unicos(int *ptr, int size, int *new_size){
    int *new=NULL, i=0, j, exist;
    if(size>0){
        *new_size=1;
        new = (int*) malloc(sizeof(int)*(*new_size));
        new[*new_size-1] = ptr[i];
        i++;
        while(i<size){
            exist=0;
            for(j=0; j<*new_size && !exist; j++){
                if(new[j]==ptr[i]){
                    exist=1;
                }
            }
            if(!exist){
                *new_size = *new_size+1;
                new = (int*) realloc(new, sizeof(int)*(*new_size));
                new[*new_size-1] = ptr[i];
            }
            i++;
        }
    }
    return new;
}

void print_array(int* array, int tam){
    printf("\n[");
    while(tam>0){
        printf("%d,", *array);
        array++;
        tam--;
    }
    printf("]");
}