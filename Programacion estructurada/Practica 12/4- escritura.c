#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;

    //Capturar informacion de clientes en un banco
    int cuenta;
    char nombre[20];
    float fondos;

    //regresa una direccion si fue exitoso el acceso
    //regresa 0 si hubo algun problema
    file = fopen("clientes.dat", "w");

    //Validando que file contenga una direccion
    if (!file)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    printf("Ingrese la cuenta(entero), nombre y fondos(real): \n");
    printf("Para salir ingrese EOF (Win: ctrl+z y Linux: ctrl+d)\n? ");

    //EOF: End of File

    scanf("%d%s%f", &cuenta, nombre, &fondos);

    //feof regresa 0 si aun no se termina el archivo
    //     regresa 1 si ha llegado al fin

    while (!feof(stdin))
    {
        fprintf(file, "%d %s %f\n", cuenta, nombre, fondos);
        printf("? ");
        scanf("%d%s%f", &cuenta, nombre, &fondos);
    }

    fclose(file);

    return EXIT_SUCCESS;
}
