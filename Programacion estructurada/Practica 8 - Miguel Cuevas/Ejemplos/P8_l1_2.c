#include<stdio.h>

typedef struct{
    float real;
    float img;
} complejo_t;


void imprimir_complejo(complejo_t);
void ecuacion(float, float, float, complejo_t*, complejo_t*);

int main(void)
{
    complejo_t r1, r2;

    ecuacion(1, 2, 3, &r1, &r2);

    imprimir_complejo(r1);
    imprimir_complejo(r2);

    return 0;
}

void ecuacion(float a, float b, float c, complejo_t* raiz1, complejo_t* raiz2)
{
    (*raiz1).real = 1; // ---> r1@main
    (*raiz1).img = 2; // ---> r1@main

    raiz2->real = 3; // (*raiz2).real
    raiz2->img = 4; // (*raiz2).img
}

void imprimir_complejo(complejo_t c)
{
    printf(" %.2f + %.2f ", c.real, c.img);
}

