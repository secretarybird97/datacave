#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int x, num, i=0, w=0; char opt; long long inicio, final; /* w cuenta los intentos, i determina si continnua el ciclo, x es el numero aleatorio*/
    printf("Adivina un numero entre 1 y 1000\n\n");
    do{
        if (w==0){
            printf("Ingresa un numero: ");
            scanf("%d", &num); /* captura de numero*/
            time(&inicio); /* inicio del reloj*/
        }
        else{
            printf("\nIngresa otro numero: ");
            scanf("%d", &num);
        }
        x = rand() % 10 + 1; /* generacion de numero aleatorio*/
        w+=1; /* intento mas 1*/
        if (x==num){ 
            if (w<10){
                printf("\n\n%cFelicidades%c has adivinado en pocos intentos.", 173, 33);
            }
            else if (w==10){
                printf("\n\n%cya conoces el n%cmero secreto%c", 173, 163, 33);
            }
            else{
                printf("\n\n%cBien hecho, lo puedes hacer mejor%c", 173, 33);
            }
            time(&final); /* final del reloj*/
            time_t elapsed = final - inicio;
            printf("\n%cExcelente%c has adivinado el n%cmero en %d intentos y %ld segundos%c\nQuieres jugar una vez m%cs (y/n)%c ", 173, 33, 163, w, elapsed, 33, 160, 63);
            scanf(" %c", &opt);
            if ((opt!='y')&&(opt!='Y')){ /* menu */
                i=1;
            }
            else{
                w=0;
            }
        }
        else if (num<x){
            printf("Muy bajo. Int%cntalo nuevamente", 130);
        }
        else{
            printf("Muy alto. Int%cntalo nuevamente", 130);
        }
    }while(i==0);

    return 0;
}
