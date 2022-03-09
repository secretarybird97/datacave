#include <stdio.h>

int main(void){
    int i=1000, x, a, b, c, d, sumpar, sumimpar;
    printf("Programa que calcula todos los numeros de 4 cifras que cumplen con la siguiente condicion:\n");
    printf("%cLa suma de las cifras de orden impar es igual a la suma delas cifras de orden par%c\n", 34, 34);
    while(i<10000){
        a=i/1000;
        b=(i%1000)/100;
        c=(i%1000)/10;
        d=i%10;
        sumpar = b+d;
        sumimpar = a+c;
        if (sumpar==sumimpar){
             printf("%d cumple con la condicion:\n%d+%d = %d+%d\n\n", i,a,c,b,d);           
        }
        i+=1;
    }

    return 0;
}