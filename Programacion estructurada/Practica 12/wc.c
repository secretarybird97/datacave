#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
   FILE *archivo;
   char c, buffer[255];
   int a, voc=0, cons=0, i=0;
   archivo = fopen(argv[2], "r");
    if(!archivo)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }
    if(argv[1]=="-c"){
        while (!feof(archivo))
        {
            c = fgetc(archivo);
            i++;
        }
        printf("Numero de caracteres: %d", i);
    }
    if(argv[1]=="-l"){
        while (!feof(archivo))
        {
            c = fgetc(archivo);
            a = ("%d", c);
            if(a==10){
                i++;
            }
        }
        printf("Numero de lineas de texto: %d", i);
    }

    if(argv[1]=="-w"){
        while(!feof(archivo)){
            fscanf(archivo, "%s", buffer);
            i++;
        }
        printf("Numero de palabras: %d", i);
    }
    return 0;
}