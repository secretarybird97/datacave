#include <stdio.h>
#include <math.h>
int main(void)
{
    float l1, l2, l3, p, a, s, M, m1, m2; //declaracion de variables

    printf("Programa para determinar tipo de triangulo, asi como su area y perimetro\n\n");

    printf("Introduzca el valor de los lados del triangulo\n"); //Captura de datos
    printf("Lado 1: ");
    scanf("%f", &l1);
    printf("Lado 2: ");
    scanf("%f", &l2);
    printf("Lado 3: ");
    scanf("%f", &l3);

    p = l1+l2+l3; s = p/2; //perimetro y semiperimetro
    a = sqrt(s*(s-l1)*(s-l2)*(s-l3)); //area del triangulo

    if (l1>l2) //estructura para determinar que lado es el mayor
    {
        if (l1>l3)
        {
            M=l1; m1=l2; m2=l3;
        }
        else 
        {
            M=l3; m1=l1; m2=l2;
        }
    }
    else
    {
        if (l2>l3)
        {
            M=l2; m1=l1; m2=l3; 
        }
        else
        {
            M=l3; m1=l1; m2=l2;
        }
    }

    if (M>=(m1+m2))
    {
        printf("\nLa figura no es un triangulo");
    }
    else if (M*M == (m1*m1 +m2*m2))
    {
        printf("\nLa figura es un triangulo rectangulo\n");
        printf("Area = %.2f | Perimetro = %.2f\nLado 1 = %.2f | Lado 2 = %.2f | Lado 3 = %.2f", a, p, l1, l2, l3);
    }
    else if (M*M >= (m1*m1 +m2*m2))
    {
        printf("\nLa figura es un triangulo obtuso\n");
        printf("Area = %.2f | Perimetro = %.2f\nLado 1 = %.2f | Lado 2 = %.2f | Lado 3 = %.2f", a, p, l1, l2, l3);
    }
    else if (M*M <= (m1*m1 +m2*m2))
    {
        printf("\nLa figura es un triangulo agudo\n");
        printf("Area = %.2f | Perimetro = %.2f\nLado 1 = %.2f | Lado 2 = %.2f | Lado 3 = %.2f", a, p, l1, l2, l3);
    }
    else
    {
        printf("\nLa figura es un triangulo equilatero\n");
        printf("Area = %.2f | Perimetro = %.2f\nLado 1 = %.2f | Lado 2 = %.2f | Lado 3 = %.2f", a, p, l1, l2, l3);
    }


    return 0;
}