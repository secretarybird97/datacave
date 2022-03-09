#ifndef FUNCIONES_H
#define FUNCIONES_H

/*Importar bibliotecas*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*Definir estructuras y tipos de datos */

typedef struct{
    int size;
    float *values;

} Array;


/*Prototipos de funciones*/

/*Parametros:
  1. La direccion de nuestro elemento Array
  2. La cantidad de elementos que debe contener nuestro arreglo
*/
void crear_arreglo(Array*, int);

/*Parametros:
    1. Copia del valor Array
*/
void imprimir_arreglo(Array);

/*Parametros:
    1. Apuntador del tipo Array
    2. Valor a agregar
*/
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

#endif
