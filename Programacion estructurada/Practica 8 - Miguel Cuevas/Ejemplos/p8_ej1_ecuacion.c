/// Apuntadores como parametros de funciones
/// Actividad 1
#include<stdio.h>

typedef struct{
    float real;
    float img;
} complejo_t;

/*
ax^2 + bx + c = 0
Parametros:
    1. Coeficiente a
    2. Coeficiente b
    3. Coeficiente c
    4. Direccion de raiz 1
    5. Direccion de raiz 2
*/
void solucion_ec(float, float, float, complejo_t*, complejo_t*);

int main(void)
{
    float a, b, c;
    complejo_t raiz1, raiz2;

    /// Capturar abc
    solucion_ec(a,b,c, &raiz1, &raiz2);

    ///Impresion de resultado

    return 0;
}

void solucion_ec(float a, float b, float c, complejo_t *r1, complejo_t *r2)
{

    /// Instrucciones

    r1->img = 0;
    r2->img = 0;

    r1->real = 0;
    r2->real = 0;
}


