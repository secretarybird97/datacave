#include <stdio.h>
#include <stdlib.h>

int main(void){
    float salario, enganche, parcial;
    printf("EMPRESA DE BIENES RAICES\n");
    printf("Cual es su salario mensual? "); setbuf(stdin, 0);
    scanf("%f", &salario);
    if(salario<=8000){
        enganche=salario*0.15;
        parcial=(salario-enganche)/180;
    }
    else{
        enganche=salario*0.3;
        parcial=(salario-enganche)/84;
    }
    printf("\nEnganche: %.2f MXN", enganche);
    printf("\nCosto mensual: %.2f MXN", parcial);

    return EXIT_SUCCESS;
}