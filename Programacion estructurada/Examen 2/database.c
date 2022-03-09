/*
Miguel Cuevas #1279713 - El codigo se baso de la practica num 13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Windows
#define CLEAR() system("CLS")
//UNIX
//#define CLEAR() system("clear")

typedef struct cliente_t
{
  int ID; //Numero de anuncio
  char name[50]; //Nombre
  char surname[50]; //Apellido
  int fecha[3]; //fecha de nacimiento
  char gender[50]; //genero
  char email[50]; //correo
  char tel[50]; //numero de telefono
  int sal; //sueldo mensual
} client;

void captura(struct cliente_t * );
void grabar(struct cliente_t);
void mostrar();
int busqueda_surname(char llave[] );
int busqueda_id(int);
void borrar();
void bonus();
long int tamano(FILE *); //esta funcion no se utilizo

int main() //FUNCION MAIN
{
    client registro;
    char opc, key[50]; int llave;

    do
    {
        CLEAR();
        puts("\n1) Registrar cliente");
        puts("2) Consulta por apellido");
        puts("3) Consulta por ID");
        puts("4) Mostrar todos los clientes");
        puts("5) Eliminar cliente");
        puts("6) Aplicar bono");
        puts("0) Salir");
        printf("Opcion:");

        setbuf(stdin, 0);
        opc=getchar();


        switch(opc)
        {
            case '1':
                captura(&registro);
                grabar(registro);
                break;
            case '5':
                borrar();
                break;
            case '2':
                printf("Apellido del cliente: ");
                setbuf(stdin, 0);
                gets(key);
                busqueda_surname(key);
                break;
            case '3':
                printf("ID  del cliente: ");
                setbuf(stdin, 0);
                scanf("%d", &llave);
                busqueda_id(llave);
                break;
            case '4':
                mostrar();
                break;
            case '6':
                bonus();
                break;
        }
    }while (opc!=48);

    return 0;
}

void captura(struct cliente_t * registro)
{   float aux; int llave; int ban;
    CLEAR();
    setbuf(stdin,0);
    printf("Numero de cliente: "); scanf("%d",&llave);
    ban=busqueda_id(llave);
    if(ban!=-1){ //VERIFICAR si el numero de cliente NO esta en la base de datos
        printf("\n\nERROR | Inserte un numero valido..");
        exit(-1);
    }
    else{
        registro->ID=llave;
        setbuf(stdin,0);
        printf("Nombre: "); gets(registro->name);
        setbuf(stdin,0);
        printf("Apellido: "); gets(registro->surname);
        setbuf(stdin,0);
        printf("Fecha de nacimiento (ejemplo 2002/08/31): "); scanf("%d/%d/%d", &registro->fecha[0], &registro->fecha[1], &registro->fecha[2]);
        setbuf(stdin,0);
        printf("Genero: "); gets(registro->gender);
        setbuf(stdin,0);
        printf("Correo electronico: "); gets(registro->email);
        setbuf(stdin,0);
        printf("Numero de telefono: "); gets(registro->tel);
        setbuf(stdin,0);
        printf("Sueldo Mensual: "); scanf("%d", &registro->sal);
    }
}
void grabar(struct cliente_t registro)
{
    FILE * flujo; int ban;
    printf("\n Nun. de ID: %d",registro.ID);
    printf("\n Nombre: %s ", registro.name);
    printf("\n Apellido: %s",registro.surname);
    printf("\n Fecha de nacimiento: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
    printf("\n Genero: %s",registro.gender);
    printf("\n Correo electronico: %s",registro.email);
    printf("\n Telefono del cliente: %s",registro.tel);
    printf("\n Sueldo mensual: $ %d MXN",registro.sal);
    getchar();
    flujo = fopen("registros.dat","ab");
    if (flujo!=NULL)
    {
        fwrite(&registro,sizeof(struct cliente_t),1,flujo);
        fclose(flujo);
    }
    else
        printf("No se pudo abrir");

}

void mostrar()
{
    FILE * flujo;
    client registro;
    int cont=1;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(client),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", cont);
            printf("\n Nun. de ID: %d",registro.ID);
            printf("\n Nombre: %s ", registro.name);
            printf("\n Apellido: %s",registro.surname);
            printf("\n Fecha de nacimiento: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
            printf("\n Genero: %s",registro.gender);
            printf("\n Correo electronico: %s",registro.email);
            printf("\n Telefono del cliente: %s",registro.tel);
            printf("\n Sueldo mensual: $ %d MXN",registro.sal);
            setbuf(stdin,0);
            getchar();
            cont++;
        }
    }
    fclose(flujo);
}

int busqueda_surname (char llave[] ) //busqueda por apellido
{
    FILE * flujo;
    struct cliente_t registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct cliente_t),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.surname,llave)==0)
            {
                printf("\n Nun. de ID: %d",registro.ID);
                printf("\n Nombre: %s ", registro.name);
                printf("\n Apellido: %s",registro.surname);
                printf("\n Fecha de nacimiento: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
                printf("\n Genero: %s",registro.gender);
                printf("\n Correo electronico: %s",registro.email);
                printf("\n Telefono del cliente: %s",registro.tel);
                printf("\n Sueldo mensual: $ %d MXN",registro.sal);
                getchar();
                fclose(flujo);
                return cont;
            }
            else{
                printf("\n No se encuentra ese apellido");
            }
        }
        fclose(flujo);

    }
    return -1;
}

int busqueda_id (int llave) //busqueda por numero de cliente
{
    FILE * flujo;
    struct cliente_t registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct cliente_t),1,flujo)>0)
        {
            cont++;
            if (llave==registro.ID)
            {
                printf("\n Nun. de ID: %d",registro.ID);
                printf("\n Nombre: %s ", registro.name);
                printf("\n Apellido: %s",registro.surname);
                printf("\n Fecha de nacimiento: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
                printf("\n Genero: %s",registro.gender);
                printf("\n Correo electronico: %s",registro.email);
                printf("\n Telefono del cliente: %s",registro.tel);
                printf("\n Sueldo mensual: $ %d MXN",registro.sal);
                fclose(flujo);
                return cont;
            }
        }
        fclose(flujo);

    }
    return -1;
}

void bonus(){
    int ban;
    int llave;
    client registro;

    FILE * flujo;
    setbuf(stdin,0);
    printf("Numero de cliente: "); scanf("%d", &llave);
    ban=busqueda_id(llave);

    if (ban!=-1)
    {
        flujo= fopen("registros.dat","rb+");
        if(flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(client),SEEK_SET);
            fread(&registro,sizeof(client),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            if((2021-(registro.fecha[0]))<60){
                printf("\nERROR: el usuario tiene menos de 60 anos..");
            }
            else{
                printf("\n Nun. de ID: %d",registro.ID);
                printf("\n Nombre: %s ", registro.name);
                printf("\n Apellido: %s",registro.surname);
                printf("\n Fecha de nacimiento: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
                printf("\n Genero: %s",registro.gender);
                printf("\n Correo electronico: %s",registro.email);
                printf("\n Telefono del cliente: %s\n",registro.tel);
                printf("\n Sueldo mensual pre-bono: $ %d MXN",registro.sal);
                registro.sal=(registro.sal)*1.1;
                printf("\n Nuevo saldo mensual: $ %d MXN",registro.sal);
                fseek(flujo,(ban-1)*sizeof(client),SEEK_SET);
                fwrite(&registro,sizeof(client),1,flujo);
            }
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }
    else
            printf("No se encontro");
}

void borrar()
{
   FILE *original, *copia;
   int llave;
   int ban;
   client aux;
   original=fopen("registros.dat","rb");
   copia=fopen("temporal.dat","wb");
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       printf("Numero de cliente que desea dar de baja: ");
       setbuf(stdin, 0);
       scanf("%d", &llave);
       ban=busqueda_id(llave);
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(client),1,original)>0)
           {    if(llave==aux.ID)
                   fwrite(&aux,sizeof(client),1,copia);
           }
           fclose(original);
           fclose(copia);
           remove("registros.dat");
           rename("temporal.dat", "registros.dat");
           printf("\nBorrado...");getchar();
       }
       else
            printf("No se encontro");
   }
}

long int tamano(FILE *file)
{
    char buffer;
    long int size=0;
    fseek(file, 0, SEEK_SET);
    while(fread(&buffer, 1, 1, file)>0)size++;
    fseek(file, 0, SEEK_SET);
    return size;
}

