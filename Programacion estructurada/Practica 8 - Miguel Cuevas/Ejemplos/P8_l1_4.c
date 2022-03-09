#include<stdio.h>

float suma(float, float);
float resta(float, float);
float mult(float, float);
float div(float, float);


int main(void)
{
    float (*ptr[])(float, float) = {suma, resta, mult, div};
    char operaciones[] = "+-*/";
    int i;
    float a,b;
    char op; // + - * /

    printf("Ingrese una operacion (ej. 3 + 5): ");
    scanf("%f %c %f", &a, &op, &b);

    for(i=0; i<4; i++) // 0 1 2 3
        if(op == operaciones[i])
            printf("\n%.2f %c %.2f = %.2f", a, op, b, ptr[i](a,b));

    return 0;
}


float suma(float a, float b)
{
    return a+b;
}

float resta(float a, float b)
{
    return a-b;
}

float mult(float a, float b)
{
    return a*b;
}

float div(float a, float b)
{
    return a/b;
}
