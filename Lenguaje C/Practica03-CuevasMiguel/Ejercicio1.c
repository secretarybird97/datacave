#include <stdio.h>
#include <stdlib.h>

int main (void){
    int a,b,k; char op;
    printf("Numero a = "); setbuf(stdin, 0);
    scanf("%d", &a);
    printf("Numero b = "); setbuf(stdin, 0);
    scanf("%d", &b);
    printf("Inserte un caracter: "); setbuf(stdin, 0);
    scanf("%c", &op);
    k = ("%d", op);
    if(((k>=65)&&(k<=90))||((k>=97)&&(k<=122))){
        k=a+b;
        printf("\nSe introdujo una letra!");
        printf("\nLa suma de a y b es: %d", k);
    }
    else if((k>=48)&&(k<=57)){
        k=a*b;
        printf("\nSe introdujo un numero entre 0-9!");
        printf("\nEl producto de a y b es: %d", k);
    }
    else{
        printf("\nERROR: Se introdujo un caracter invalido %c", op);
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}