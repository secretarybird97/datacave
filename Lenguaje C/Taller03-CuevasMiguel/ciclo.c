/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/


#include <stdio.h>
#include <stdlib.h>

int main (void){
    int i, j;
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            printf("\n%d x %d = %d", i, j, i*j);
        }
    }

    return EXIT_SUCCESS;
}