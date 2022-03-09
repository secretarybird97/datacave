/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/


#include <stdio.h>
#include <stdlib.h>

int main(void){
    char nom[15]; int edad; float cal;
    printf("\nInserta tu nombre: ");
    setbuf(stdin,0);
    gets(nom);
    printf("Inserta tu edad: ");
    scanf("%d", &edad);
    printf("Inserta tu calificacion: ");
    scanf("%f", &cal);
    printf("\n\tRESULTADOS\n");
    printf("\nTu nombre es: %s", nom);
    printf("\nTu edad es: %d anos", edad);
    printf("\nTu calificaion es: %.2f", cal);

    return EXIT_SUCCESS;
}