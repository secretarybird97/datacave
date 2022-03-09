#include <stdio.h>
#include <stdlib.h>

int main (void){
    int num;
    printf("Inserte un numero entero del 1 al 4: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("\n%d en letra es: uno", num);
        break;
    case 2:
        printf("\n%d en letra es: dos", num);
        break;
    case 3:
        printf("\n%d en letra es: tres", num);
        break;
    case 4:
        printf("\n%d en letra es: cuatro", num);
        break;
    default:
        printf("\nERROR!");
        return EXIT_FAILURE;
        break;
    }

    return EXIT_SUCCESS;
}