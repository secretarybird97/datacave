#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ESTRUCTURAS
typedef struct{
    int size;
    float *values;
} Array;

//PROTITIPOS
void crear_arreglo(Array*, int);

void imprimir_arreglo(Array);

void agregar(Array*, float);

void agregar_en(Array*, float, int);

void eliminar(Array*, int);

void reemplazar(Array*, float, float);

void vaciar(Array*);

Array copiar(Array*);

Array unicos(Array*);

float max(Array);

float min(Array);

float media(Array);

float mediana(Array);

float desviacion(Array);

Array ordenar(Array);

float suma(Array);

int comparar(const void *, const void *);

int main(int argc, char** argv){ //FUNCION MAIN
    FILE *archivo; int c;
    Array lista={0};
    archivo = fopen(argv[1], "r");
    if(!archivo){
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }
    fscanf(archivo, "%d", c);
    while (!feof(archivo))
    {
        agregar(&lista, c);
        c = fgetc(archivo);
    }
    imprimir_arreglo(lista);


    return 0;
}

void crear_arreglo(Array* a, int n_elementos)
{
    if(n_elementos<=0)
    {
        printf("El tamano del arreglo debe ser positivo\n");
        exit(-1);
    }
    a->values = (float*) calloc(n_elementos, sizeof(float));
    //(*a).values
    a->size = n_elementos;
}

/*Parametros:
    1. Copia del valor Array
*/
void imprimir_arreglo(Array a)
{
    int i;
    printf("\nCantidad de elementos: %d\n", a.size);
    printf("Valores: ");
    for(i=0; i< a.size ; i++)
        printf(" %.2f ", a.values[i]);
}

/*Parametros:
    1. Apuntador del tipo Array
    2. Valor a agregar
*/
void agregar(Array* a, float value)
{
    if(!a->values)
    {
        crear_arreglo(a, 1);
    }
    else
    {
        a->size = a->size+1;
        a->values = realloc(a->values, a->size*sizeof(float));
    }
    a->values[a->size-1] = value;
}

void agregar_en(Array* a, float value, int pos){
    int n = a->size-1, i; float copia;
    if(pos>n){
        printf("La posicion debe existir en el arreglo\n");
        exit(-1);
    }
    else{
        n++;
        a->size = a->size+1;
        a->values = realloc(a->values, a->size*sizeof(float));
    }
    for(i=n; i>=pos; i--){
        if(i==pos){
            a->values[i]=value;
        }
        else{
            a->values[i] = a->values[i-1];
        }
    }
}

void eliminar(Array* a, int pos){
    int n = a->size-1, i;
    if(pos>n){
        printf("La posicion debe existir en el arreglo\n");
        exit(-1);
    }
    else{
        for(i=pos+1; i<=n; i++){
            a->values[i-1] = a->values[i];
        }
        n--;
        a->size = a->size-1;
        a->values = realloc(a->values, a->size*sizeof(float));
    }
}

void reemplazar(Array* a, float x, float y){
    int n = a->size-1, i;
    for(i=0; i<=n; i++){
        if(a->values[i] == x){
            a->values[i] = y;
        }
    }
}

void vaciar(Array* a){
    a->values=NULL;
    a->size=0;
}

Array copiar(Array* a){
    Array copia; Array *b = &copia;
    b->size = a->size;
    b->values = a->values;
    return copia;
}

Array unicos(Array* a){
    int i=0, j, exist;
    Array new; Array *b = &new;
    if((a->size)>0){
        b->size = 1;
        b->values = (int*) malloc(sizeof(int)*(b->size));
        b->values[b->size-1] = a->values[i];
        i++;
        while(i<(a->size)){
            exist=0;
            for(j=0; j<(b->size) && !exist; j++){
                if(b->values[j]==a->values[i]){
                    exist=1;
                }
            }
            if(!exist){
                b->size = (b->size)+1;
                b->values = (int*) realloc(b->values, sizeof(int)*(b->size));
                b->values[b->size-1] = a->values[i];
            }
            i++;
        }
    }
    return new;
}

float max(Array a){
    float maximo = a.values[0]; int i, size=a.size;
    i=0;
    while(size--)
    {
        if(maximo < a.values[i])
            maximo = a.values[i];
        i++;
    }

    return maximo;
}

float min(Array a){
    float minimo = a.values[0]; int i, size=a.size;
    i=0;
    while((size)--)
    {
        if(minimo > a.values[i])
            minimo = a.values[i];
        i++;
    }

    return minimo;
}

float media(Array a){
    return suma(a)/(a.size);
}

float mediana(Array a){
    Array b = ordenar(a);
    int pos=((b.size)/2), mediana, i=0;

    //Elementos del arreglo ordenado
    while((b.size)--){
        if((b.size)==pos){
            mediana=b.values[i];
        }
        i++;
    }


    return mediana;
}

float desviacion(Array a){
    Array copia=copiar(&a);
    float prom=media(copia), numerador=0, desv; int i=0;
    int n=copia.size;
    while((copia.size)--){
        numerador+=pow(copia.values[i]-prom, 2);
        i++;
    }
    desv=sqrt(numerador/(n-1)); //formula desviacion estandar
    return desv;
}

Array ordenar(Array a){
    Array b =copiar(&a);
    qsort(b.values, b.size, sizeof(float), comparar);
    return b;
}

float suma(Array a){
    float sum = 0; int i=0;
    while((a.size)--)
    {
        sum+= a.values[i];
        i++;
    }

    return sum;
}

int comparar(const void *x, const void *y)
{
    return *(int*)x - *(int*)y;
}