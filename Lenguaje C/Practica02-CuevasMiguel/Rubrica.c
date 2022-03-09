/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    char nombre[30], matricula[15], materia1[25], materia2[25], materia3[25];
    float calificaciones[3], promedio;


    printf("\n\t     PRACTICA 4. ENTRADA Y SALIDA DE DATOS");
    printf("\n--------------------------------------------------------------");
    printf("\nIngresa nombre: "); setbuf(stdin, 0);
    gets(nombre);
    printf("Ingresa tu matricula: "); setbuf(stdin, 0);
    gets(matricula);

    printf("\nIngresa materia 1: "); setbuf(stdin, 0);
    gets(materia1);
    printf("Ingresa calificacion 1: "); setbuf(stdin, 0);
    scanf("%f", &calificaciones[0]);

    printf("\nIngresa materia 2: "); setbuf(stdin, 0);
    gets(materia2);
    printf("Ingresa calificacion 2: "); setbuf(stdin, 0);
    scanf("%f", &calificaciones[1]);

    printf("\nIngresa materia 3: "); setbuf(stdin, 0);
    gets(materia3);
    printf("Ingresa calificacion 3: "); setbuf(stdin, 0);
    scanf("%f", &calificaciones[2]);

    promedio = (calificaciones[0]+calificaciones[1]+calificaciones[2])/3; //PROMEDIO DE CALIFICACIONES

    printf("\n");
    printf("\n\t\t  PROMEDIO DE CALIFICACIONES");
    printf("\n--------------------------------------------------------------");
    printf("\nNOMBRE DEL ALUMNO: %s\t Matricula: %s", nombre, matricula);
    printf("\n--------------------------------------------------------------");
    printf("\nMateria\t\t\t\t\t\t  Calificacion");
    printf("\n--------------------------------------------------------------");
    printf("\n%s\t\t\t\t\t%.2f", materia1, calificaciones[0]);
    printf("\n%s\t\t\t\t\t%.2f", materia2, calificaciones[1]);
    printf("\n%s\t\t\t\t\t%.2f", materia3, calificaciones[2]);
    printf("\n--------------------------------------------------------------");
    printf("\n\t\t\t\t       Promedio General: %.2f", promedio);


    return EXIT_SUCCESS;
}