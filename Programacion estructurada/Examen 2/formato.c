#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE *archivo, *copia;
    archivo = fopen(argv[1], "r");
    copia = fopen("copia_archivo.txt", "w");

    if(argc<1){ //verificar parametros
        printf("Error al introducir parametros..");
        exit(-1);
    }
    if(!archivo){
        printf("El archivo no se abrio correctamente.");
        exit(-1);
    }
    if(!copia){
        printf("El archivo no se abrio correctamente.");
        exit(-1);
    }

    char c;
    //opt sirve para verificar si el caracter anterior fue un punto o un salto
    int k=0, num_espacios=0, num_saltos=0, opt; 
    c = fgetc(archivo);
    while(!feof(archivo)){
        k=("%d", c);
        if(k==32){ //si el caracter es un espacio
            num_espacios++;
            if(num_espacios>1){
                c = fgetc(archivo);
                continue;
            }
        }
        else if(k==10){// si el caracter es un salto de linea
            num_saltos++;
            if(num_saltos>1){
                c = fgetc(archivo);
                continue;
            }
        }
        else{
            if((opt==1)){
                if(k>=97 && k<=122){ //convierte minusculas a mayusculas
                    k=k-32;
                }
                opt=0;
            }
            num_espacios=0;
            num_saltos=0;
        }

        if((k==46) || (k==10)){// si el caracter es un punto O salto de linea
            opt=1;
        }

        fputc(k, copia);
        c = fgetc(archivo);
    }

    printf("\nEl texto formateado se encuentra en el archivo copia_archivo.txt");
    fclose(archivo);
    fclose(copia);
    return EXIT_SUCCESS;
}