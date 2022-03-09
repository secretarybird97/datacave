/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/


#include <stdio.h>
#include <stdlib.h>

int main (void){
    int i, j, k=0;
    for(i=0; i<6; i++){
        k++;
        for(j=0; j<k; j++){
            printf("*");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}