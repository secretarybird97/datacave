#include<stdio.h>
#include<math.h>
typedef struct numero_racional_estructura{
    int numerador;
    int denominador;
} racional;

racional captura_racional(void); //capturacion de un numero racional
void print_racional(racional); //impresion en forma rectangular
racional suma_racional(racional, racional); //suma de numeros racionales
racional resta_racional(racional, racional); //resta de numeros racionales
racional multiplicacion_racional(racional, racional); //multiplicacion de numeros racionales
racional division_racional(racional, racional); //division de numeros racionales

int main(void){ //funcion principal
//codigo de prueba
    racional a, b, c;
    a = captura_racional();
    b = captura_racional();
    c = division_racional(a, b);
    print_racional(c);

    return 0;
}

racional captura_racional(void){ //captura de un numero racional
    racional num; int opt=0;
    do{
        printf("\nInserta un numero racional (eg. 2/5): ");
        scanf("%d/%d", &num.numerador, &num.denominador);
        if(num.denominador==0){
            printf("ERROR Matematico");
        }
        else{
            opt=1;
        }
    }while(opt==0);
    return num;
}

void print_racional(racional x){ //impresion de numero racional
    if(x.numerador==x.denominador){
        printf("\n%d", abs(x.numerador));
    }
    else{
        printf("\n%d/%d", x.numerador, x.denominador);
    }
}

racional suma_racional(racional x, racional y){ //suma de numeros racional
    racional resultado;
    if(x.denominador==y.denominador){
        resultado.numerador=x.numerador+y.numerador;
        resultado.denominador=x.denominador;
    }
    else{
        int a=x.denominador, b=y.denominador, c, k, mcm;
        k = a*b;
        while(b!=0){ //formula de maximo comun divisor
            c = b;
            b = a % b;
            a = c;
        }
        mcm = k/a; //expresion de minimo comun multiplo
        resultado.numerador = (mcm/y.denominador)*y.numerador +(mcm/x.denominador)*x.numerador;
        resultado.denominador = mcm;
    }
    return resultado;
}

racional resta_racional(racional x, racional y){ //resta de numeros racional
    racional resultado;
    if(x.denominador==y.denominador){
        resultado.numerador=x.numerador+y.numerador;
        resultado.denominador=x.denominador;
    }
    else{
        int a=x.denominador, b=y.denominador, c, k, mcm;
        k = a*b;
        while(b!=0){ //formula de maximo comun divisor
            c = b;
            b = a % b;
            a = c;
        }
        mcm = k/a; //expresion de minimo comun multiplo
        resultado.numerador = (mcm/y.denominador)*y.numerador -(mcm/x.denominador)*x.numerador;
        resultado.denominador = mcm;
    }
    return resultado;
}

racional multiplicacion_racional(racional x, racional y){ //multiplicacion de numeros racionales
    racional resultado;
    int a=(x.numerador*y.numerador), b=(x.denominador*y.denominador), c, mcd;
    while(b!=0){ //maximo comun divisor
        c = b;
        b = a % b;
        a = c;
    }
    mcd = a;
    resultado.numerador = (x.numerador*y.numerador)/mcd;
    resultado.denominador = (x.denominador*y.denominador)/mcd;
    return resultado;
}

racional division_racional(racional x, racional y){ //division de numeros racionales
    racional resultado;
    int a=(x.numerador*y.denominador), b=(x.denominador*y.numerador), c, mcd;
    while(b!=0){ //maximo comun divisor
        c = b;
        b = a % b;
        a = c;
    }
    mcd = a;
    resultado.numerador = (x.numerador*y.denominador)/mcd;
    resultado.denominador = (x.denominador*y.numerador)/mcd;
    return resultado;
}