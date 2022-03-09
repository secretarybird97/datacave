#include <stdio.h>
#include <math.h>

int main(void){
    int i=100, x, a, b, c; /* declaracion de variables*/
    printf("Programa que calcula todos los numeros de tres cifras tales que la suma de los cubos de las cifrtas es igual al valor del numero\n");
    while(i<1000){
        a=i/100; /* centenas*/
        b=(i%100)/10; /* decimas */
        c=i%10; /* unidades */
        x = (a*a*a)+(b*b*b)+(c*c*c); /* condicion*/
        if (x==i){
             printf("%d cumple con la condicion:\n%d^3 +%d^3 +%d^3 = %d\n\n", i,a,b,c,i);           
        }
        i+=1;
    }

    return 0;
}
