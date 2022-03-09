#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
   FILE *archivo;
   char c;
   printf("hol;a");
   if(argc==3){
       switch (argv[1])
       {
       case "mayus":
           archivo = fopen(argv[1], "r");
           if(!archivo){
                printf("El archivo no se abrio correctamente.");
                exit(-1);
           }
           while (!((c = fgetc(archivo)) == EOF))
            printf("%c", c);
           break;
       
       default:
           break;
       }
   }
    return 0;
}
