#include <stdio.h>
#include <stdlib.h>

int main (void){
    int op, i; 
    printf("1) for\n2) while\n3) do while");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &op);
    switch(op){
        case 1:
            for(i=1; i<=10; i++){
                printf("%d", i);
            }
            break;
        case 2:
            i=1;
            while(i<=10){
                printf("%d", i);
                i++;
            }
            break;
        case 3:
            i=1;
            do{
                printf("%d", i);
                i++;
            }while (i<=10);
            break;
        default:
            printf("\nERROR: Opcion invalida\n");
            return EXIT_FAILURE;
            break;   
    }

    return EXIT_SUCCESS;
}