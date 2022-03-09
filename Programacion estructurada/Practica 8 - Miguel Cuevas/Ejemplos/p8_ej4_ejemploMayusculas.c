#include<stdio.h>

char car2mayus(char);
void str2mayus(char[]);
void str2mayusPtr(char[]);


int main(void)
{
    char cad[] = "hola mundo 101";
    char cad2[] = "bienvenido a C!";

    char *cad_ptr = cad;

    printf("Cadena original: %s", cad_ptr);
    str2mayus(cad_ptr);
    printf("\nCadena mayusculas: %s", cad_ptr);

    cad_ptr = cad2;
    printf("\n\nCadena original: %s", cad_ptr);
    str2mayusPtr(cad_ptr);
    printf("\nCadena mayusculas: %s", cad_ptr);

    return 0;
}

char car2mayus(char car)
{
    if(car>='a' && car<='z')
        return car-32;
    return car;
    //return car>='a'&&car<='z'? car-32:car;
}

void str2mayus(char cadena[])
{
    int i=0;
    while(cadena[i])
    {
        cadena[i] = car2mayus(cadena[i]);
        i++;
    }
}


void str2mayusPtr(char* cadena)
{
    while(*cadena)
    {
        *cadena = car2mayus(*cadena);
        cadena = cadena + 1;
        //cadena++; //Incremento en el valor (direccion)
    }
}
