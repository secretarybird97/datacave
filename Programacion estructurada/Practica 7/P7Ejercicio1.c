#include<stdio.h>
#include<math.h>
typedef struct numero_complejo{
    float real;
    float img;
} numcom;

numcom captura_complejo(void); //capturacion de un numero complejo
void printr_complejo(numcom); //impresion en forma rectangular
void printp_complejo(numcom); //impresion en forma polar
numcom suma_complejo(numcom, numcom); //suma de numeros complejos
numcom resta_complejo(numcom, numcom); //resta de numeros complejos
numcom multiplicacion_complejo(numcom, numcom); //multiplicacion de numeros complejos
numcom division_complejo(numcom, numcom); //division de numeros complejos

int main(void){ //funcion principal
    numcom a, b, c;
    a = captura_complejo();
    b = captura_complejo();
    printr_complejo(a);
    printr_complejo(b);
    c = multiplicacion_complejo(a, b);
    printr_complejo(c);
    printp_complejo(c);
    return 0;
}

numcom captura_complejo(void){ //capturacion de un numero complejo
    numcom ncomplejo;
    printf("\nIngrese un numero complejo (eg. 2, 5i): ");
    scanf("%f, %fi", &ncomplejo.real, &ncomplejo.img);

    return ncomplejo;
}

void printr_complejo(numcom x){ //forma rectangular
    if(x.img<0){
        printf("\n%.2f %.2fi", x.real, x.img);
    }
    else{
        printf("\n%.2f + %.2fi", x.real, x.img);
    }
}

void printp_complejo(numcom x){ //forma polar
    float r, z;
    r = sqrt(pow(x.real, 2) +pow(x.img, 2));
    z = atan(x.img / x.real);
    if(x.real<0){
        z+=M_PI;
    }
    printf("\n%.2f(cos(%.3f rad) +isin(%.3f rad))", r, z, z);
}

numcom suma_complejo(numcom x, numcom y){ //suma de numeros complejos
    numcom resultado;
    resultado.real = x.real +y.real;
    resultado.img = x.img +y.img;
    return resultado;
}

numcom resta_complejo(numcom x, numcom y){ //resta de numeros complejos
    numcom resultado;
    resultado.real = x.real -y.real;
    resultado.img = x.img -y.img;
    return resultado;
}

numcom multiplicacion_complejo(numcom x, numcom y){ //multiplicacion de numeros complejos
    numcom resultado;
    resultado.img = (x.real*y.img)+(x.img*y.real);
    resultado.real = (x.real*y.real)-(x.img*y.img);
    return resultado;
}

numcom division_complejo(numcom x, numcom y){ //division de numeros complejos
    numcom resultado;
    float d; //denominador
    d = pow(y.real, 2) +pow(y.img, 2);
    resultado.img = ((x.real*-y.img)+(x.img*y.real))/d;
    resultado.real = ((x.real*y.real)-(x.img*-y.img))/d;
    return resultado;
}