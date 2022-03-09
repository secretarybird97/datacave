/// Pase de parametros por consola


#include<stdio.h>
#include<string.h>

/// argc: cuenta los argumentos
/// argv: contiene los valores de los argumentos
/*
    argv: {dir1, dir2, dir3}

    dir1: "cadena1"
    dir2: "cadena2"
    dir3: "cadena3"

    printf("%s", argv[0]) -> "cadena1"
*/

/// FORMATO >parametros primo/par numero
/// Ejemplo.
///         >parametros primo 13
///          Salida: El numero 13 si es primo

///         >parametros par 13
///          Salida: El numero 13 no es par

///         >parametros sumar 13 8
///          Salida: La suma es 13+8=21

int es_primo(int);

int main(int argc, char* argv[])
{
    int num, num2;
    if(argc<3)
    {
        printf("Error al recibir parametros por consola.\n");
        printf("\tEjecutar el programa de la siguiente forma:\n");
        printf("FORMATO >parametros primo/par numero\nEjemplo.\n\
        >parametros primo 13\nSalida: El numero 13 si es primo\n\n\
        >parametros par 13\nSalida: El numero 13 no es par");
        printf("\nPresione ENTER para continuar\n");
        getchar();
    }

    num = atoi(argv[2]); // convierte cadena a entero

    if(!strcmp(argv[1], "primo"))
    {
        if(es_primo(num))
            printf("El numero %d si es primo.\n", num);
        else
            printf("El numero %d no es primo.\n", num);
    }
    else if(!strcmp(argv[1], "par"))
    {
        if(num%2)
            printf("El numero %d no es par.\n", num);
        else
            printf("El numero %d si es par\n.", num);
    }
    else if(!strcmp(argv[1], "sumar"))
    {
       if(argc>3) //Verdadero con valor 4
       {
            num2=atoi(argv[3]);
            printf("\nLa suma de %d+%d=%d\n", num, num2, num2+num);
       }
       else
       {
        printf("\nPara sumar se requiere capturar dos numeros.\n");
       }
    }
    else
    {
        printf("\nFORMATO >parametros primo/par numero\nEjemplo.\n\
        >parametros primo 13\nSalida: El numero 13 si es primo\n\n\
        >parametros par 13\nSalida: El numero 13 no es par");
        printf("\nPresione ENTER para continuar\n");
        getchar();

    }


    return 0;
}


int es_primo(int num) //version no eficiente
{
    int i;

    for(i=2; i<num; i++)
    {
        if(num%i==0)
            return 0; //el numero no es primo
    }

    return 1; // es primo
}
