#include<stdio.h>
#include<stdlib.h>

int main(void){
    int g, i, opt, k=1; float num, ev, x; /* g - grado del polinomio; num, ev y x se usan para evaluar la funcion */
    printf("Inserta el grado del polinomio: ");
    scanf("%d", &g); /* captura del grado del polinomio */
    if (g<1 || g>5){
        printf("Error: Grado de polinomio invalido.");
        exit(0);
    }
    float pol[g+1]; /* creacion del polinomio de grado g */
    printf("\n");
    for(i=0; i<=5; i++){ /* captura de los coeficientes */ 
        printf("X%c%d = ",94, i);
        scanf("%f", &pol[i]);
    }
    while(k==1){
        printf("\n1. Modificar polinomio; 2. Imprimir polinomio; 3. Evaluar el polionmio por un numero ingresado por el usuario; 4. Salir"); /* Menu */
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opt);
        printf("\n");
        switch(opt){
        case 1:
            for(i=0; i<=g; i++){
                printf("Vieja X%c%d = %d | Nueva X%c%d = ",94, i, pol[i], 94, i);
                scanf("%f", &pol[i]);
            }
            break;
        case 2:
            for(i=g; i>=0; i--){
                printf("+%.2fX%c%d ",pol[i], 94, i);
            }
            break;
        case 3:
            ev=pol[0];
            printf("Ingresa el numero a evaluar: ");
            scanf("%f", &num);
            x=num;
            for(i=1; i<=g; i++){
                ev=ev+(num*pol[i]);
                num=num*x;
            }
            printf("f(%.2f) = %.2f", x, ev);
            break;
        case 4:
            k=0;
            break;
        default:
            break;
        }
    }

    return 0;
}
