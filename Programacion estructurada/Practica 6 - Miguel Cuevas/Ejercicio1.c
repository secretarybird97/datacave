#include<stdio.h>
#include<math.h>
float pendiente(float, float, float, float);
float angulo(float);
float rad2grad(float);

int main(void){
    float x0, y0, x1, y1, m, b, deg;
    printf("Inserta las coordenadas del primer punto: "); 
    scanf("%f,%f", &x0, &y0);
    printf("Inserta las coordenadas del segundo punto: ");
    scanf("%f,%f", &x1, &y1);
    m = pendiente(x0, y0, x1, y1); 
    b = (m*-x0)+y0;
    deg = rad2grad(angulo(m));
    if (b>0){
        printf("\nEcuacion de la recta: y = %.2fx +%.2f\n", m, b);
    }
    else if(b<0){
        printf("\nEcuacion de la recta: y = %.2fx -%.2f\n", m, b);
    }
    else{
        printf("\nEcuacion de la recta: y = %.2fx\n", m);
    }

    printf("Angulo de la recta: %.2f grados", deg);



    return 0;
}

float pendiente(float x0, float y0, float x1, float y1){ //caclula la pendiente (m)
    float pendiente;
    pendiente = (y1-y0)/(x1-x0);
    return pendiente;
}

float angulo(float pendiente){ //calcula la inclinacion de la ecuacion
    float rad;
    rad = atan(pendiente);
    return rad;
}

float rad2grad(float rad){  //convierte radianes a grados
    float degrees;
    degrees = (rad*180)/M_PI;
    return degrees;
}