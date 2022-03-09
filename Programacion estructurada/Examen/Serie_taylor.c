#include<stdio.h>
#include<math.h>

float mycos(float, int);
int main(void){
    printf("%.4f", mycos(-3,3));
    return 0;
}

float mycos(float x, int n){
    int i, j, k=0;
    float coseno=0;
    for(i=1; i<n+1; i++){
        int factorial=1;
        for(j=1; j<=k; j++){
            factorial = factorial*j;
        }
        if(i%2==0){
            coseno-=(pow(x, k))/factorial;
        }
        else{
            coseno+=(pow(x, k))/factorial;
        }
        k+=2;
    }
    return coseno;
}
