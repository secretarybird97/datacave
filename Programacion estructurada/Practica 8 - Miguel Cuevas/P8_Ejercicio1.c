#include <stdio.h>
#include <math.h>
#define k 1e-4 //aproximacion a cero para validar valor imaginario
typedef struct numero_complejo{
    float real;
    float img;
} comp;

void raices_fg(float, float, float, comp*, comp*);

int main(void){
    float a, b, c;
    comp x1, x2;
    printf("Introduzca el valor de a: "); //captura de coeficientes
    scanf("%f", &a);
    printf("Introduzca el valor de b: ");
    scanf("%f", &b);
    printf("Introduzca el valor de c: ");
    scanf("%f", &c);
    
    raices_fg(a, b, c, &x1, &x2);
    if((x1.img<=k) && (x2.img<=k)){
        printf("\n\nx1 = %.2f | x2 = %.2f", x1.real, x2.real);
    }
    else{
        printf("\n\nx1 = %.2f +%.2fi | x2 = %.2f %.2fi", x1.real, x1.img, x2.real, x2.img);
    }
    return 0;
}

void raices_fg(float a, float b, float c, comp *raiz1, comp *raiz2){
    float r;
    r = b*b-(4*a*c);
    if(r>=0){
        raiz1->img = 0;
        raiz2->img = 0;
        raiz1->real = (-b+sqrt(r))/(2*a);
        raiz2->real = (-b-sqrt(r))/(2*a);
    }
    else{
        r = fabs(r);
        raiz1->img = sqrt(r)/(2*a);
        raiz2->img = -sqrt(r)/(2*a);
        raiz1->real = (-b)/(2*a);
        raiz2->real = (-b)/(2*a);
    }
}

