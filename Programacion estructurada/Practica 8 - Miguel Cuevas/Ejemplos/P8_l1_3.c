#include<stdio.h>

int main(void)
{

    int array[] = {11, 12, 13, 14, 15, 16} , tam = 6;
    int *ptr;
    char cadena[] = "Hola Mundo";
    char *ptr2;

    ptr = array; //OK &array[0]

    printf("Direccion de arreglo: %p", array);
    printf("\nDireccion del primer elemento: %p", &array[0]);
    printf("\nValor del primer elemento: %d", array[0]);
    printf("\nValor del primer elemento: %d", *(&array[0]) );


    printf("\n\nValor de la variable ptr: %p", ptr); //ptr = &array[0]
    printf("\nValor de Indireccion de ptr: %d", *ptr); // array[0]

    printf("\n\nDireccion del segundo elemento: %p", &array[1]);
    printf("\nValor del segundo elemento: %d", *&array[1]);

    ptr = array;
    printf("\n\nLos valores del arreglo son: \n");
    while(tam) //Continua mientras que tam NO sea 0
    {
        printf("Valor: %d \n", *ptr);
        ptr++; //ptr++;
        tam--; // tam = tam-1; tam--;
    }

    printf("\n\nEjemplo con cadenas de caracteres..\n\n");
    ptr2 = cadena;
    while(*ptr2)
    {
        printf("%c", *ptr2);
        ptr2++;
    }




    return 0;
}
