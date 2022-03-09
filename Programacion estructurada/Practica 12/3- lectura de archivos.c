//Biblioteca estandar de entrada y salida

/*Programa que recibe como parámetro por consola el 
    nombre de un archivo para leer e imprimir su información en consola
    
  Ejemplo:
  >programa.exe archivo.txt
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file;
    char c;

    if (!(argc > 1))
    {
        printf("Error en los parametros por consola.\nRequiere nombre de archivo a leer.");
        exit(-1);
    }

    ///Se abre el archivo modo lectura ("r")
    file = fopen(argv[1], "r");

    ///Se comprueba si se ha abierto de forma correcta
    if (!file)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    ///OPCION 1 Se lee caracter por caracter, comparando si el caracter que se
    /// leyó es el fin del archivo, caracter EOF (constante de stdio.h)

    /*
    while (!((c = fgetc(file)) == EOF))
        printf("%c", c);
    */

    ///FIN OPCION 1

    ///OPCION 2 Se lee caracter por caracter, comparando si ya se leyó todo el archivo
    /// a través de la función feof. Dicha función regresa Verdadero si se consumió todo el archivo,
    /// ó regresa Falso en caso contrario
    c = fgetc(file);

    while (!feof(file))
    {
        printf("%c", c);
        c = fgetc(file);
    }
    ///FIN OPCION 2

    ///FORMA DE LECTURA POR PALABRAS, se usa fscanf para leer por palabras sin considerar espacios
    /*
    fscanf(file, "%s", buffer);
    while(!feof(file))
    {
        printf("%s\n",buffer);
        fscanf(file, "%s", buffer);
    }
    */
    ///FIN DE FORMA DE LECTURA POR PALABRAS

    fclose(file);

    return EXIT_SUCCESS;
}
