#include<stdio.h>

/*Definicion de Estructuras*/
struct complejo{
    float real;
    float img;
};

/*Prototipos de funciones*/
struct complejo captura_complejo(void);
void imprimir_complejo(struct complejo);
struct complejo suma(struct complejo, struct complejo);

int main(void)
{


    struct complejo c1, c2; //declaracion


    //printf("Tamano de la variable: %d bytes", sizeof(c1));

    // 0+1i  = i
    c1 = captura_complejo();
    c2 = captura_complejo();

    printf("El primer numero complejo es: ");
    imprimir_complejo(c1);

    printf("\nEl segundo numero complejo es: ");
    imprimir_complejo(c2);

    printf("\nEl resultado de la suma de los dos numeros complejos es: ");
    imprimir_complejo( suma(c1,c2) );



    return 0;
}

struct complejo captura_complejo(void)
{
    struct complejo nuevo_comp;

    printf("\nIngrese un numero complejo (ej 3, 4i): ");
    scanf("%f, %fi", &nuevo_comp.real, &nuevo_comp.img);

    return nuevo_comp;
}

void imprimir_complejo(struct complejo comp)
{
    printf("\n%.2f + %.2fi", comp.real, comp.img);
}

struct complejo suma(struct complejo c1, struct complejo c2)
{
    struct complejo resultado;

    resultado.real = c1.real + c2.real;
    resultado.img = c1.img + c2.img;

    return resultado;
}

