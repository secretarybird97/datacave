#include<stdio.h>
#include<math.h>

typedef struct vector_r3_estructura {
    float i;
    float j;
    float k;
} vector;

vector captura_vector(void); //captura los elemntos i, j, k de un vector
void impresion_vector(vector); //imprime un vector en R3
float modulo_vector(vector); //regresa el modulo del vector
vector suma_vector(vector, vector); //suma dos vectores
vector resta_vector(vector, vector); //resta dos vectores
float producto_escalar(vector, vector); //regresa el producto punto de dos vectores
vector producto_vectorial(vector, vector); //regresa el producto cruz de dos vectores

int main(void){ //funcion principal
    //codigo de prueba
    vector a,b,c;
    a = captura_vector();
    b = captura_vector();
    c = producto_vectorial(a, b);
    impresion_vector(c);

    return 0;
}

vector captura_vector(void){
    vector x;
    int i;
    printf("\n");
    for(i=0; i<3; i++){
        switch (i){
            case 0:
                printf("Ingrese el elemento i del vector: ");
                scanf("%f", &x.i);
                continue;
            case 1:
                printf("Ingrese el elemento j del vector: ");
                scanf("%f", &x.j);
                continue;
            case 2:
                printf("Ingrese el elemento k del vector: ");
                scanf("%f", &x.k);
                continue;
            default:
                continue;
        }
    }
    printf("Vector Capturado: (%.2f)i +(%.2f)j +(%.2f)k\n", x.i, x.j, x.k);
    return x;
}

void impresion_vector(vector x){
    printf("\n(%.2f)i +(%.2f)j +(%.2f)k\n", x.i, x.j, x.k);
}

float modulo_vector(vector x){
    float modulo;
    modulo = sqrt(pow(x.i, 2) +pow(x.j, 2) +pow(x.k, 2)); // formula de modulo
    return modulo;
}

vector suma_vector(vector x, vector y){
    vector resultado;
    resultado.i = x.i +y.i;
    resultado.j = x.j +y.j;
    resultado.k = x.k +y.k;
    return resultado;
}

vector resta_vector(vector x, vector y){
    vector resultado;
    resultado.i = x.i -y.i;
    resultado.j = x.j -y.j;
    resultado.k = x.k -y.k;
    return resultado;
}

float producto_escalar(vector x, vector y){
    float resultado;
    resultado = (x.i*y.i) +(x.j*y.j) +(x.k*y.k);
    return resultado;
}

vector producto_vectorial(vector x, vector y){
    vector z;
    z.i = (x.j*y.k) -(x.k*y.j); //formula de producto cruz
    z.j = (x.k*y.i) -(x.i*y.k);
    z.k = (x.i*y.j) -(x.j*y.i);
    return z;
}
