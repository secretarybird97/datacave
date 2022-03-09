/*
Nombre: Miguel Angel Cuevas Gonzalez 
Matricula: #1279713
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    char fecha[25] = "31 de agosto de 2021";
    char cliente_nombre[25] = "Miguel Cuevas";
    char cliente_rfc[15] = "CUGM020831LN7";

    char producto_1_nombre[80] = "Aceite acpullo 1 lt.";
    float producto_1_precio_unitario =  17.6;
    int producto_1_cantidad = 2;
    float producto_1_costo = 35.2;

    char producto_2_nombre[80] = "Galletas OREO 8 piezas";
    float producto_2_precio_unitario =  14.5;
    int producto_2_cantidad = 3;
    float producto_2_costo = 43.5;

    char producto_3_nombre[80] = "Botellas de agua";
    float producto_3_precio_unitario =  150;
    int producto_3_cantidad = 1;
    float producto_3_costo = 150;
    float subtotal = producto_1_costo+producto_2_costo+producto_3_costo;

    printf("\n\t\t      Costco  Wholesale");
    printf("\n\t\t       Orden de compra");
    printf("\n\t\t\t\t\t %s", fecha);
    printf("\nPRODUCTO\tPRECIO UNITARIO\t\tCANTIDAD\tCOSTO");
    printf("\n--------------------------------------------------------------");
    printf("\n%s\t%.2f\t\t%d\t\t%.2f", producto_1_nombre, producto_1_precio_unitario, producto_1_cantidad, producto_1_costo);
    printf("\n%s\t%.2f\t\t%d\t\t%.2f", producto_2_nombre, producto_2_precio_unitario, producto_2_cantidad, producto_2_costo);
    printf("\n%s\t%.2f\t\t%d\t\t%.2f", producto_3_nombre, producto_3_precio_unitario, producto_3_cantidad, producto_3_costo);
    printf("\n\n");
    printf("\n--------------------------------------------------------------");
    printf("\n\t\t\t\t\tSUB-TOTAL:\t%.2f", subtotal);
    printf("\n\n\t\t\t\t\tIVA:\t\t%.2f", subtotal*0.08);
    printf("\n\t\t\t\t        ----------------------");
    printf("\n\t\t\t\t\tTOTAL:\t\t%.2f", subtotal*1.08);
    printf("\nCANTIDAD EN LETRA:");
    printf("\n( Doscientos cuarenta y siete MXN )");


    return EXIT_SUCCESS;
}