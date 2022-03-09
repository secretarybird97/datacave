#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL)); //semilla para generar siempre numeros aleatorios diferentes
    int i, p, aciertos=0, dif, num1, num2, k, opt=0, r, x, pts=0, m, n, tiempo_max, tiempo_min;
    float porciento=0;
    long long inicio, inicio_programa, final, final_programa, tiempo_programa; //variables relacionadas al tiempo
    time(&inicio_programa); //aqui empieza a contar el tiempo de ejecucion total
    printf("Bienvenido al juego de matematicas! ");
    printf("Cuantas preguntas quiere resolver? ");
    scanf("%d", &p); //captura del numero de preguntas
    long long tiempo;

    while(opt==0){ //ciclo que vertifica la captura correcta de la dificultad
        printf("Elegir dificultad: 0. Facil 1. Medio 2. Dificil: ");
        scanf("%d", &dif);
        switch(dif){
            case 0:
                m=1;
                n=12;
                opt=1;
                break;
            case 1:
                m=2;
                n=14;
                opt=1;
                break;
            case 2:
                m=3;
                n=25;
                opt=1;
                break;
            default:
                printf("ERROR: Introduza una dificultad valida.\n\n");
                opt=0;
                break;
        }
    }
    printf("\n");

    for(i=0; i<p; i++){ //for que inicia el juego basado en el numero de preguntas
        num1 = rand() % (n-m+1) +m;
        num2 = rand() % (n-m+1) +m;
        if(dif!=0){ //este if agrega numeros negativos unicamente cuando la dificultad es diferente de Facil
            k = rand() % 4;
            if(k==0){
                num1=num1*-1;
            }
            else if(k==1){
                num2=num2*-1;
            }
            else if(k==2){
                num1=num1*-1;
                num2=num2*-1;
            }
            else{
                num1=num1;
                num2=num2;
            }
        }
        x = num1*num2; //x sirve para identificar si el resultado es correcto
        printf("Cuanto es %d x %d ? ", num1, num2);
        time(&inicio); //inicio de tiempo de usuario
        scanf("%d", &r);
        time(&final); //termina tiempo de usuario
        tiempo = final - inicio;
        if(r==x){ //se verifica el input del usuario
            pts+=1000; aciertos+=1; porciento+=(100/p); 
            if(tiempo>1 && tiempo<4){
                pts=pts+(tiempo*-50);
            }
            else if(tiempo>3 && tiempo<9){
                pts=pts+(tiempo*-100);
            }
            else if(tiempo>8){
                pts-=1000;
            }
        }
        else{
            pts-=100;
        }
        if(i==0){ 
            tiempo_max=tiempo;
            tiempo_min=tiempo;
        }
        else{
            if(tiempo>tiempo_max){
                tiempo_max=tiempo;
            }
            if(tiempo<tiempo_min){
                tiempo_min=tiempo;
            }
        }
    }

    printf("Tiempo minimo en contestar: %d segundos\n", tiempo_min);
    printf("Tiempo maximo en contestar: %d segundos\n", tiempo_max);
    printf("\nNumero de aciertos: %d | Porcentaje de aciertos: %.2f%c", aciertos, porciento, 37);
    time(&final_programa);
    tiempo_programa = final_programa-inicio_programa;
    printf("\nTiempo total de ejecucion: %ld segundos", tiempo_programa);
    printf("\n%d puntos obtenidos", pts);
    return 0;
}