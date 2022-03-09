#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define h 1e-4

float biseccion( float (*f)(float), float tolerancia, float max_iter);
float falsa_posicion( float (*f)(float), float tolerancia, float max_iter);
float newton( float (*f)(float), float tolerancia, float max_iter);
float derivada(float (*f)(float), float x);

float func(float x)
{
    return  x*x-3;
}

int main (void)
{
  int opt, size, i;
  //EJEMPLO
  float (*metodos[])(float (*f)(float), float, float) = {biseccion, falsa_posicion, newton};
  char* nombres[] = {"Biseccion", "Falsa posicion", "Newton"};

  size=sizeof(nombres)/sizeof(char*);

  printf("Seleccione un metodo:\n");
  i=1;
  do
  {
    printf("%d) %s\n", i, nombres[i-1]);
    i++;
  }while(i<=size);

  printf("Ingrese opcion: ");
  scanf("%d", &opt);

  if(opt<=size && opt>=1)
    printf("Solucion: %f", metodos[opt-1](func, 1e-3, 100));
  else
    printf("Seleccione opcion correcta");



  return 0;
}


float biseccion( float (*f)(float), float tolerancia, float max_iter)
{
    //solicitar limite izquierdo y derecho
    float error=1e10, Xi, Xs, xr=0;
    int iter=0;
    //Xi: Limite izquierdo | Xs: Limite Derecho

    printf("Ingrese rango de busqueda (ej 1.0, 2.0):");

    scanf("%f, %f", &Xi, &Xs);

    if(Xi>=Xs || f(Xs) * f(Xi) > 0)
    {
        printf("\n****Intente otro rango****\n");
        return 0;
    }


    while(error>tolerancia && iter<max_iter)
    {
        xr = (Xi+Xs)/2.0; //evaluacion
        if(f(xr) * f(Xi) <0)
            Xs = xr;
        else
            Xi = xr;
        iter++;
        error = fabs(f(xr));
    }
    return xr;
}

float falsa_posicion( float (*f)(float), float tolerancia, float max_iter)
{
    //solicitar limite izquierdo y derecho
    float error=1e10, Xi, Xs, xr=0;
    int iter=0;
    //Xi: Limite izquierdo | Xs: Limite Derecho

    printf("Ingrese rango de busqueda (ej 1.0, 2.0):");

    scanf("%f, %f", &Xi, &Xs);

    if(Xi>=Xs || f(Xs) * f(Xi) > 0)
    {
        printf("\n****Intente otro rango****\n");
        return 0;
    }


    while(error>tolerancia && iter<max_iter)
    {
        xr = Xs-((f(Xs)*(Xi-Xs))/(f(Xi)-f(Xs))); //evaluacion
        if(f(xr) * f(Xi) <0)
            Xs = xr;
        else
            Xi = xr;
        iter++;
        error = fabs(f(xr));
    }
    return xr;
}


float newton( float (*f)(float), float tolerancia, float max_iter){
    float X0, Xi, copia=0, error=1e10, valor_actual, valor_anterior; int iter=0;

    printf("Ingrese un valor inicial (ej 1.0): ");
    scanf("%f", &X0);

    while(error>tolerancia && iter<max_iter)
    {
        valor_actual=X0;
        valor_anterior=copia;
        Xi=X0-(f(X0)/derivada(f, X0)); //evaluacion
        error = fabs((valor_actual-valor_anterior)/valor_actual)*100;
        copia=X0;
        X0=Xi;
        iter++;
    }
    return Xi;
}

float derivada(float (*f)(float), float x)
{
    return (f(x+h)-f(x-h))/(2*h);
}