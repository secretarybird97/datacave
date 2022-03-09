#include<stdio.h>
#include<math.h>
int main(void){
    int cant, i, k, j, a=0, freqmax=0; double z=0, sum=0, prom, dev, moda=0;
    printf("Cuantas calificaciones va a capturar?: ");
    scanf("%d", &cant);
    double array[cant]; 
    int freq[11];
    for(i=0; i<cant; i++){ //captura de datos
        k=0;
        while(k==0){
            printf("Calificacion %d: ", i+1);
            scanf("%lf", &array[i]);
            if((fmod(array[i],0.5)<0.0000001)){ //verifica de manera aproximada si es divisible entre 0.5
                k=1;
            }
            else{
                printf("\nInserte un numero divisible entre 0.5");
            }
        }
        sum+=array[i];
    }

    prom=sum/cant; //calculo de promedio
    printf("\nFRECUENCIAS:"); //calculo de frecuencias
    for(i=0; i<11; i++){
        freq[i]=0;
        for(j=0; j<cant; j++){
            if(array[j]==z){
                freq[i]++;
            }
        }
        if(freq[i]>moda){
            moda=z;
            freqmax=freq[i];
        }
        printf("\n%.1lf se repite %d", z, freq[i]);
        z+=0.5;
    }

    for(i=0; i<11; i++){ //verifica si hay mas de una moda
        if(freqmax==freq[i]){
            a+=1;
        }
    }
    if(a>1){ //imprime las modas
        printf("\n\nMODA: ");
        double mod[a];
        z=0;
        for(i=0; i<11; i++){
            if(freqmax==freq[i]){
                mod[i]=z;
                printf("%.1lf", mod[i]);
                if(z<moda){
                    printf(", ");
                }
            }
            z+=0.5;
        }
    }
    else{ //imprime la moda
        printf("\n\nMODA: %.1lf", moda);
    }

    printf("\nPROMEDIO: %.2lf", prom); //imprime el promedio

    sum=0;
    for(i=0; i<cant; i++){ //calcula la desvuacion estandar
        sum+=pow((array[i]-prom),2);
    }
    dev=sqrt(sum/cant);
    printf("\nDESVIACION ESTANDAR: %.5lf", dev);


    return 0;
}