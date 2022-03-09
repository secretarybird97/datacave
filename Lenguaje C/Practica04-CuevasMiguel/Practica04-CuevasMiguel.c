#include <stdio.h>
#include <stdlib.h>
#define CLEAR() system("CLS")

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
int par(int);
int primo(int);

int main (void){
    int op;
    printf("1) Ejercicio 1");
    printf("\n2) Ejercicio 2");
    printf("\n3) Ejercicio 3");
    printf("\n4) Ejercicio 4");
    printf("\n0) Salir");
    printf("\nSeleccione una opcion: "); setbuf(stdin,0);
    scanf("%d", &op);
    switch (op){
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
        
        default:
            break;
    }
    return EXIT_SUCCESS;
}

void ejercicio1(){
    int n, op, sum=0, i, x;
    do{
        printf("\nCuantos numeros quiere capturar? "); setbuf(stdin, 0);
        scanf("%d", &n);
        printf("\n");
        for(i=0; i<n; i++){
            printf("Ingresa un numero: "); setbuf(stdin, 0);
            scanf("%d", &x);
            if(par(x)==1){
                sum+=x;
            }
        }
        printf("\nSuma de numeros impares = %d", sum);
        printf("\n0) Repetir programa\n1) Salir");
        printf("\nSeleccione una opcion: "); setbuf(stdin, 0);
        scanf("%d", &op);
    }while(op!=1);
}

void ejercicio2(){
    int a, b, c, op=0;
    printf("\nIntroduce tres numeros consecutivos para terminar el programa!");
    do{
        printf("\nNumero 1: "); setbuf(stdin, 0);
        scanf("%d", &a);
        printf("Numero 2: "); setbuf(stdin, 0);
        scanf("%d", &b);
        printf("Numero 3: "); setbuf(stdin, 0);
        scanf("%d", &c);
        if((b==(a+1))&&(c==(b+1))){
            printf("\nPrograma finalizado. Gracias");
            op=1;
        }
    }while(op!=1);
}

void ejercicio3(){
    int a, b, op=0, op1=0, i, x;
    do{
        do{
            printf("\nNumero inicial: "); setbuf(stdin, 0);
            scanf("%d", &a);
            printf("Numero final: "); setbuf(stdin, 0);
            scanf("%d", &b);
            if(a>b){
                printf("\nERROR: Numero inicial mayor al final.");
            }
            else{
                op=1;
            }
        }while(op!=1);
        printf("\nNumeros primos entre a y b: ");
        for(i=a; i<=b; i++){
            if(primo(i)==0){
                printf("%d ", i);
            }
        }
        printf("\n0) Repetir programa\n1) Salir");
        printf("\nSeleccione una opcion: "); setbuf(stdin, 0);
        scanf("%d", &op1);

    }while(op1!=1);
}

void ejercicio4(){
    int i, j, k, n=6, pos;
    for(i=1; i<=6; i++){
        for(j=1; j<=11; j++){
            k=0; pos=0;
            if(j==n){
                while(k<i){
                    if(par(pos)==0){
                        printf("*");
                        k++; //n de asteriscos mas 1
                    }
                    else{
                        printf(" ");
                    }
                    pos++; //posicion mas 1
                }
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
        n--;
    }
}

int primo(int x){ //funcion para saber si es primo un numero
    int i=1, d=0;
    while(i<x){
        if(x%i==0){
            d+=1;
        }
        i++;
    }
    if(d<=1){
        return 0;
    }
    else{
        return 1;
    }
}

int par(int x){ //funcion para saber si es par un numero
    if(x%2==0){
        return 0;
    }
    else{
        return 1;
    }
}

/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/