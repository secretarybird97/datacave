#include <stdio.h>
#include <stdlib.h>

/*
Prototipo de la funcion qsort para ordenar arreglos
    void qsort(void *arreglo,
                size_t numeroElementos,
                size_t tamanoElemento,
                int (*comparar)(const void *, const void *));
*/

int compare (const void * a, const void * b)
{
  return    *((int*)b)-*((int*)a) ;
}


int main (void)
{
  int n, size, values[] = { 40, 10, 100, 90, 20, 25 };

  size=6;

  qsort (values, size, sizeof(int), compare);

  for (n=0; n<size; n++)
     printf ("%d ",values[n]);

  return 0;
}
