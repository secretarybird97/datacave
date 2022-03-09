#include<stdio.h>
#include<math.h>

int reversa(int);
int digitos(int);
int suma_cifras(int); 
int primo(int); //Regresa 0 si no es primo, y 1 en caso contrario
int main(void){
    int x, opt;
    printf("Ingresa un numero entero: ");
    scanf("%d", &x);
    do{
        printf("\nQue tarea desea realizar?\n1: Reverso del numero\n2: Cantidad de digitos del numero\n3: Suma de sus cifras\n4: Saber si es primo\nSelecciona una opcion: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("\n%d", reversa(x));
                break;
            case 2:
                printf("\n%d contiene %d digitos", x, digitos(x));
                break;
            case 3:
                printf("\nSuma de cifras de %d es igual a %d", x, suma_cifras(x));
                break;
            case 4:
                if(primo(x)==0){
                    printf("\n%d NO es un numero primo", x);
                }
                else{
                    printf("\n%d es un numero primo", x);
                }
                break;
        }
    }while(opt<1 || opt>4);
    return 0;
}

int reversa(int x){ //invierte los digitos de un numero x
    float y=x; int c=1, i, k, num=0, j, w;
    while(y>=10){
        y=y/10;
        c++;
    }
    j=c-1;
    for(i=1; i<=c; i++){
        w=pow(10,i);
        k=pow(10,j);
        num=num+(((x%w)/(w/10))*k); //formula para separar los digitos
        j--;
    }
    return num;
}

int digitos(int x){ //regresa la cantidad de digitos de un numero x
    float y=x; int c=1;
    while(y>=10){
        y=y/10;
        c++;
    }
    return c;
}

int suma_cifras(int x){ //suma las cifras de un numero
    float y=x; int c=1, i, k, num=0, j, w;
    while(y>=10){
        y=y/10;
        c++;
    }
    j=c-1;
    for(i=1; i<=c; i++){
        w=pow(10,i);
        k=pow(10,j);
        num=num+(((x%w)/(w/10))); //formula para sumar los digitos
        j--;
    }
    return num;
}

int primo(int x){ //calcula si el numero es primo o no
    int i=1, d=0;
    while(i<x){
        if (x%i==0){
            d+=1; /* d igual a numero de divisores*/
        }
        i+=1;
    }
    if (d<=1)
        return 1;
    else
        return 0;
}