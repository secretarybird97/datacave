#include <stdio.h>

int main(void){
    int opt=1;
    while(opt==1){ //inicio de ciclo
        float matriz1[3][3], matriz2[3][3], matrizf[3][3];
        int i, j, z;
        printf("A continuacion inserta los elementos de la matriz A:\n");
        for(i=0; i<3; i++){ //captyra de matriz A
            for(j=0; j<3; j++){
                printf("Elemento [%d, %d] = ", i, j);
                scanf("%f", &matriz1[i][j]);
            }
        }
        printf("\n\nA continuacion inserta los elementos de la matriz B:\n");
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                printf("Elemento [%d, %d] = ", i, j);
                scanf("%f", &matriz2[i][j]); //captura de matriz B
            }
        }

        printf("\n\nResultado de A*B: \n");
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                matrizf[i][j]=0;
                for(z=0; z<3; z++){
                    matrizf[i][j]+=matriz1[i][z]*matriz2[z][j]; //multiplicaion de matrices
                }
                printf("%.2f, ", matrizf[i][j]);
            }
            printf("\n");
        }
        printf("\n\nDesea repetir el programa? Si (1) / No (0): ");
        scanf("%d", &opt);
    }


    return 0;
}
