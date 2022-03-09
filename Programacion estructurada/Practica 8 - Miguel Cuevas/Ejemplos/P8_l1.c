/*Apuntadores*/
#include<stdio.h>


int main(void)
{
    int a = 5; /*4 bytes*/
    int *ptr; /*4 bytes  => 32 bits ||| 8 bytes => 64bits*/
    char b; /*1 byte*/
    char *ptr2; /*4 bytes => 32 bits ||| 8 bytes => 64bits*/

    ptr = &a;

    printf("Direccion de la variable a: %p", &a);
    printf("\nValor de la variable a: %d", a);

    printf("\n\nDireccion de la variable ptr: %p", &ptr);
    printf("\nValor de la variable ptr: %p", ptr);
    printf("\nEl valor de Indireccion de la variable ptr: %d", *ptr);

    *ptr = 10;
    printf("\n\nEl nuevo valor de a es: %d", a);

    printf("\n\nTamano de un apuntador a int:  %d bytes", sizeof(int*));
    printf("\nTamano de un apuntador a char:  %d bytes", sizeof(char*));



    return 0;
}
