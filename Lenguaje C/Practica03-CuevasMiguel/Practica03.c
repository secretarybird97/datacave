/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CLEAR() system("CLS")

int ejercicio1();
int ejercicio2();
int ejercicio3();
int ejercicio4();
int ejercicio5();

int main (void){
    int op;
    printf("1) Ejercicio 1");
    printf("\n2) Ejercicio 2");
    printf("\n3) Ejercicio 3");
    printf("\n4) Ejercicio 4");
    printf("\n5) Ejercicio 5");
    printf("\n0) Salir");
    printf("\nSeleccione una opcion: "); setbuf(stdin,0);
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        CLEAR();
        ejercicio1();
        break;
    case 2:
        CLEAR();
        ejercicio2();
        break;
    case 3:
        CLEAR();
        ejercicio3();
        break;
    case 4:
        CLEAR();
        ejercicio4();
        break;
    case 5:
        CLEAR();
        ejercicio5();
        break;
    
    default:
        return EXIT_SUCCESS;
        break;
    }

}

int ejercicio1(){
    int a,b,k; char op;
    printf("Numero a = "); setbuf(stdin, 0);
    scanf("%d", &a);
    printf("Numero b = "); setbuf(stdin, 0);
    scanf("%d", &b);
    printf("Inserte un caracter: "); setbuf(stdin, 0);
    scanf("%c", &op);
    k = ("%d", op);
    if(((k>=65)&&(k<=90))||((k>=97)&&(k<=122))){
        k=a+b;
        printf("\nSe introdujo una letra!");
        printf("\nLa suma de a y b es: %d", k);
    }
    else if((k>=48)&&(k<=57)){
        k=a*b;
        printf("\nSe introdujo un numero entre 0-9!");
        printf("\nEl producto de a y b es: %d", k);
    }
    else{
        printf("\nERROR: Se introdujo un caracter invalido %c", op);
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}

int ejercicio2(){
    int num, i;
    printf("Inserte un numero: ");
    scanf("%d", &num);
    if(num%2==0){
        printf("\nEl numero capturado es par.", num);
    }
    else{
        printf("\nEl numero capturado es impar.", num);
    }
    printf("\nLos multiplos de %d son: ", num);
    for(i=1; i<=50; i++){
        if(i==50){
            printf("%d.", num*i);
        }
        else{
            printf("%d, ", num*i);
        }
    }

    return EXIT_SUCCESS;
}

int ejercicio3(){
    float salario, enganche, parcial;
    printf("EMPRESA DE BIENES RAICES\n");
    printf("Cual es su salario mensual? "); setbuf(stdin, 0);
    scanf("%f", &salario);
    if(salario<=8000){
        enganche=salario*0.15;
        parcial=(salario-enganche)/180;
    }
    else{
        enganche=salario*0.3;
        parcial=(salario-enganche)/84;
    }
    printf("\nEnganche: %.2f MXN", enganche);
    printf("\nCosto mensual: %.2f MXN", parcial);

    return EXIT_SUCCESS;
}

int ejercicio4(){
    int max, min, n, i, num;
    printf("Cuantos numeros quiere capturar? ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Inserte un numero: ");
        scanf("%d", &num);
        if(i==0){
            max=num;
            min=num;
        }
        else if(num<min){
            min=num;
        }
        else if(num>max){
            max=num;
        }
    }
    printf("\nMayor: %d", max);
    printf("\nMenor: %d", min);

    return EXIT_SUCCESS;
}

int ejercicio5(){
    float a,b, i; int op;
    printf("Inserte un numero: "); setbuf(stdin,0);
    scanf("%f", &a);
    do{
        printf("Resultado: %.2f", a);
        printf("\nInserte otro numero: "); setbuf(stdin,0);
        scanf("%f", &b);
        printf("1) Suma");
        printf("\n2) Resta");
        printf("\n3) Multiplicacion");
        printf("\n4) Division");
        printf("\n5) Potencia");
        printf("\n6) Modulo");
        printf("\n0) Salir");
        printf("\nSeleccione una opcion: "); setbuf(stdin,0);
        scanf("%d", &op); printf("\n");
        switch(op){
            case 1:
                a=a+b;
                break;
            case 2:
                a=a-b;
                break;
            case 3:
                a=a*b;
                break;
            case 4:
                a=a/b;
                break;
            case 5:
                a=powf(a,b);
                break;
            case 6:
                a = ((int)a)%((int)b);
                break;
            default:
                break;
        }

    }while(op!=0);

    return EXIT_SUCCESS;

}