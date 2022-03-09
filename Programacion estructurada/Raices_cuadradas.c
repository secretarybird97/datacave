#include<stdio.h>
#include<math.h>
int main(void)
{
    float a, b, c, x1, x1i, x2, x2i, r; //declaracion de variables
    printf("Calculadora de ecuaciones cuadraticas\n");
    
    printf("Introduzca el valor de a: "); //captura de coeficientes
    scanf("%f", &a);
    printf("Introduzca el valor de b: ");
    scanf("%f", &b);
    printf("Introduzca el valor de c: ");
    scanf("%f", &c);
    r = b*b-(4*a*c);
    printf("\n");

    if (r>0) //raiz cuadrada verdadera
    {
        x1 = (-b+sqrt(r))/(2*a);
        x2 = (-b-sqrt(r))/(2*a);
        printf("x1 = %.2f\nx2 = %.2f", x1, x2);
    }
    else if (r<0) //raiz cuadrada imaginaria
    {
        x1 = -b/(2*a);
        x2 = (sqrt(-r))/(2*a);
        printf("x1 = %.2f+%.2fi\nx2 = %.2f-%.2fi", x1, x2, x1, x2);
    }
    else //raiz cuadrada = 0
    {
        x1 = -b/(2*a);
        printf("x = %.2f", x1);
    }
    return(0);
}
