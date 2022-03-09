#include <stdio.h>

int main(void){
    char cadena[51], may[51], min[51];
    int i, l, a, voc=0, cons=0, opt=1;
    while(opt==1){ //menu
        printf("Inserte una oracion (menos de 50 caracteres y utilize _ para espacios): ");
        scanf("%s", cadena);
        printf("\n\n%c%s%c\n", 34, cadena, 34);
        printf("Datos sobre la cadena:\n");
        for(i=0; i<50; i++){
            a=("%d", cadena[i]);
            if(a==97 || a==101 || a==105 || a==111 || a==117){
                voc+=1;
            }
            if(a!=97 && a!=101 && a!=105 && a!=111 && a!=117 && a!=32){
                cons+=1;
            }
        }
        printf("Num. de vocales = %d\nNum. de consonantes = %d\n\n", voc, cons);
        printf("Convertir a mayusculas:\n");
        for(i=0; i<50; i++){
            a=("%d", cadena[i]);
            if(a>96 && a<123){
                cadena[i]=a-32;
            }
            if(cadena[i]!=0){
                printf("%c", cadena[i]);
            }
        }
        printf("\n\nConvertir a minusculas:\n");
        for(i=0; i<50; i++){
            a=("%d", cadena[i]);
            if(a>64 && a<91){
                cadena[i]=a+32;
            }
            printf("%c", cadena[i]);
        }
        printf("\n\nDesea repetir el programa? Si (1) / No (0): ");
        scanf("%d", &opt);
    }
    return 0;
}
