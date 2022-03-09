#include"funciones.h"

int main(void)
{
    Array miarreglo={0}, vacio={0}, xd={0};

    crear_arreglo(&vacio, 10); printf("| AREGLO EN 0s");
    imprimir_arreglo(vacio); //FUNCION IMPRIMIR
    agregar(&miarreglo, 5.0);
    agregar(&miarreglo, 6.0); //FUNCION AGREGAR NUEVO ELEMENTO AL FINAL
    agregar(&miarreglo, 7.0);
    agregar(&miarreglo, 8.0);
    xd=copiar(&miarreglo); //FUNCION COPIAR
    imprimir_arreglo(miarreglo); printf("| FUNCION AGREGAR NUEVO ELEMENTO AL FINAL");
    agregar_en(&miarreglo, 6, 3);
    imprimir_arreglo(miarreglo); printf("| FUNCION AREGAR_EN");
    imprimir_arreglo(unicos(&miarreglo)); printf("| FUNCION UNICOS");
    reemplazar(&miarreglo, 6, 9);
    imprimir_arreglo(miarreglo); printf("| FUNCION REEMPLAZAR");
    eliminar(&miarreglo, 3);
    imprimir_arreglo(miarreglo); printf("| FUNCION ELIMINAR");
    vaciar(&miarreglo);
    imprimir_arreglo(miarreglo); printf("| FUNCION VACIAR");
    imprimir_arreglo(xd); printf("| IMPRIME COPIAR ORIGINAL");

    printf("\n\nMaximo de funcion original: %.2f", max(xd));
    printf("\n\Minimo de funcion original: %.2f", min(xd));
    printf("\n\Promedio de funcion original: %.2f", media(xd));
    printf("\n\Mediana de funcion original: %.2f", mediana(xd));
    printf("\n\Desviacion estandar de funcion original: %.2f", desviacion(xd));
    printf("\n\Funcion original ordenada");
    imprimir_arreglo(ordenar(xd));

    return 0;
}
