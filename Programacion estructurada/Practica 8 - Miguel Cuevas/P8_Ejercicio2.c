#include<stdio.h>
#include<stdlib.h> //funcion qsort
#include<time.h>
#include<math.h>
#define TAM 50

void aleatorios(int*, int);

///Primer parametro: Arreglo
///Segundo parametro: Tamano

float suma(int*, int);
float max(int*, int);
float min(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);
float desviacion(int*, int); //EXTRA 10pts

int comparar(const void *, const void *);






int main(void)
{
    int size, i, arreglo[TAM];
    float (*funciones[])(int*, int) = {suma, max, min, media, mediana, moda, desviacion };
    char* nombres[] = {"suma", "maximo", "minimo", "media", "mediana", "moda", "desviacion"};

    srand (time(NULL));//Establecer semilla para valores aleatorios
    aleatorios(arreglo, TAM);

    ///Calcula el total de elementos  = 6
    size = sizeof(funciones)/sizeof(funciones[0]);

    for(i=0; i<size; i++)
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo, TAM));
    /*for(i=0; i<TAM; i++){
        printf("%d\n", arreglo[i]);
    }*/

    return 0;
}


float suma(int* array, int size)
{
    float sum = 0;
    while(size--)
    {
        sum += *array;
        array++;
    }

    return sum;
}

float max(int* array, int size)
{
    float maximo = *array;
    while(size--)
    {
        if(maximo < *array)
            maximo =*array;
        array++;
    }

    return maximo;
}

float min(int* array, int size)
{
    float minimo = *array;
    while(size--)
    {
        if(minimo > *array)
            minimo =*array;
        array++;
    }
    return minimo;
}

float media(int* array, int size)
{
    return suma(array, size)/size;
}

//Se requiere datos ordenados
float mediana(int* array, int size)
{
    int pos=(size/2), mediana;
    qsort(array, size, sizeof(int), comparar);

    //Elementos del arreglo ordenado
    while(size--){
        if(size==pos){
            mediana=*array;
        }
        array++;
    }


    return mediana;
}

float moda(int* array, int size)
{
    int repeticiones, i, moda, freq_mayor=0, freq_actual;
    int* copia = array; int copia_size = size;
    for(i=0; i<11; i++){
        repeticiones=0;
        while(size--){
            if(i==*array){
                repeticiones++;
            }
            array++;
        }
        array = copia;
        size = copia_size;


        freq_actual = repeticiones;
        if(freq_actual > freq_mayor){
            freq_mayor = freq_actual;
            moda = i;
        }
    }

    return moda;
}

void aleatorios(int* array, int size)
{
    while(size--) *(array++)=rand() % 11;
}

int comparar(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

float desviacion(int* array, int size){ //EXTRA 
    float prom=media(array, size), numerador=0, desv;
    int copia_size=size;
    while(size--){
        numerador+=pow((*array)-prom, 2);
        array++;
    }
    desv=sqrt(numerador/(copia_size-1)); //formula desviacion estandar
    return desv;
}