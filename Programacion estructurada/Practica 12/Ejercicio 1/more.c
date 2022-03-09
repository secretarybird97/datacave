#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE *archivo;
    char buffer[255];
    archivo = fopen(argv[1], "r");

    if(!archivo){
        printf("El archivo no se abrio correctamente.");
        exit(-1);
    }

    char opt;
    int k=0;
    fgets(buffer, 255, archivo);
    while(!feof(archivo)){
        if(k==0){
            for(int i=0; i<15; i++){
                printf("%s", buffer);
                fgets(buffer, 255, archivo);
            }
            k=1;
        }
        else{
            for(int i=0; i<10; i++){
                printf("%s", buffer);
                fgets(buffer, 255, archivo);
            }
        }
        setbuf(stdin, NULL);
        printf("\nPresione ENTER para contiunar.\n");
        scanf("%c", &opt);
    }
    fclose(archivo);
    return EXIT_SUCCESS;
}
