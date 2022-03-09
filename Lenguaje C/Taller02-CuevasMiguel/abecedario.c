#include <stdio.h>
#include <stdlib.h>

int main (void){
    int op, i;
    printf("Abecedario utilizando ASCII\n");
    printf("\t1) Mayuscula\n");
    printf("\t2) Minuscula\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    if((op<1)||(op>2)){
        printf("\n\nERROR. Opcion invalida");
        return EXIT_FAILURE;
    }
    
    switch (op)
    {
    case 1:
        i=65;
        while((i>=65)&&(i<=90)){
            printf("%c", i);
            i++;
        }
        break;
    case 2:
        i=97;
        while((i>=97)&&(i<=122)){
            printf("%c", i);
            i++;
        }
        break;

    default:
        break;
    }

    return EXIT_SUCCESS;
}