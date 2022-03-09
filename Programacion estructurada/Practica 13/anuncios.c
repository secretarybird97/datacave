/*
Manejador de inventarios
ABC
Altas - Bajas y Consultas de articulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Windows
#define CLEAR() system("CLS")
//UNIX
//#define CLEAR() system("clear")

typedef struct anuncio_t
{
  char cat[50]; //clasificacion
  int clave; //Numero de anuncio
  char resp[50]; //responsable
  int tel; //telefono
  char content[50]; //contenido del anuncio
  int fecha[3]; //fecha
} anuncio;

void captura(struct anuncio_t * );
void grabar(struct anuncio_t);
void mostrar();
int busqueda_cat(char llave[] );
int busqueda_resp(char llave[] );
int busqueda_num(int);
void borrar();
void editar ();
void ordenar(); //esta funcion no se utilizo
long int tamano(FILE *); //esta funcion no se utilizo

int main() //FUNCION MAIN
{
    anuncio registro;
    char opc, key[50];

    do
    {
        //CLEAR();
        puts("\n1) Registrar anuncio");
        puts("2) Cancelar anuncio");
        puts("3) Editar");
        puts("4) Consulta por clasificacion");
        puts("5) Consulta por responsable");
        puts("6) Mostrar anuncios");
        puts("0) Salir");
        printf("Opcion:");

        setbuf(stdin, 0);
        opc=getchar();


        switch(opc)
        {
            case '1':   captura(&registro);
                        grabar(registro);
                        break;
            case '2': borrar(); break;
            case '3': editar(); break;
            case '4': 
                printf("Clasificacion del anuncio: ");
                setbuf(stdin, 0);
                gets(key);
                busqueda_cat(key); 
                break;
            case '5': 
                printf("Responsable del anuncio: ");
                setbuf(stdin, 0);
                gets(key);
                busqueda_resp(key); 
                break;
            case '6': 
                mostrar();
                break;
        }
    }while (opc!=48);

    return 0;
}

void captura(struct anuncio_t * registro)
{   float aux; int llave; int ban;
    CLEAR();
    printf("Numero de anuncio: "); scanf("%d",&llave);
    ban=busqueda_num(llave);
    if(ban!=-1){ //VERIFICAR si el numero de anuncio NO esta en la base de datos
        printf("\n\nERROR | Inserte un numero valido..");
        exit(-1);
    }
    else{
        registro->clave=llave;
        setbuf(stdin,0);
        printf("Clasificacion: "); gets(registro->cat);
        setbuf(stdin,0);
        printf("Responsable de la publicacion: "); gets(registro->resp);
        printf("Telefono del responsable: "); scanf("%d",&registro->tel);
        setbuf(stdin,0);
        printf("Contenido del anuncio: "); gets(registro->content);
        setbuf(stdin,0);
        printf("Fecha de publicacion (ej. 2018/07/15): ");
        scanf("%d/%d/%d", &registro->fecha[0], &registro->fecha[1], &registro->fecha[2]);
    }
}
void grabar(struct anuncio_t registro)
{
    FILE * flujo; int ban;
    printf("\n Numero de anuncio: %d",registro.clave);
    printf("\n Clasificacion: %s ", registro.cat);
    printf("\n Responsable de la publicacion: %s",registro.resp);
    printf("\nTelefono del responsable: %d",registro.tel);
    printf("\n Contenido del anuncio: %s",registro.content);
    printf("\n Fecha de publicacion: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
    getchar();
    flujo = fopen("registros.dat","ab");
    if (flujo!=NULL)
    {
        fwrite(&registro,sizeof(struct anuncio_t),1,flujo);
        fclose(flujo);
    }
    else
        printf("No se pudo abrir");

}

void mostrar()
{
    FILE * flujo;
    anuncio registro;
    int cont=1;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(anuncio),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", cont);
            printf("Numero de anuncio: %d \n", registro.clave);
            printf("Clasificacion: %s \n", registro.cat);
            printf("Responsable de la publicacion: %s \n", registro.resp);
            printf("Telefono del responsable: %d \n", registro.tel);
            printf("Contenido del anuncio: %s \n", registro.content);
            printf("Fecha de publicacion: %d/%d/%d \n",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
            setbuf(stdin,0);
            getchar();
            cont++;
        }
    }
    fclose(flujo);
}
int busqueda_cat (char llave[] ) //busqueda por categoria
{
    FILE * flujo;
    struct anuncio_t registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio_t),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.cat,llave)==0)
            {
                printf("\n Numero de anuncio: %d",registro.clave);
                printf("\n Clasificacion: %s ", registro.cat);
                printf("\n Responsable de la publicacion: %s",registro.resp);
                printf("\n Telefono del responsable: %d",registro.tel);
                printf("\n Contenido del anuncio: %s",registro.content);
                printf("\n Fecha de publicacion: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
                getchar();
                fclose(flujo);
                return cont;
            }
            else{
                printf("\n No existe esa categoria de anuncio..");
            }
        }
        fclose(flujo);

    }
    return -1;
}

int busqueda_resp (char llave[] ) //busqueda por responsable
{
    FILE * flujo;
    struct anuncio_t registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio_t),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.resp,llave)==0)
            {
                printf("\n Numero de anuncio: %d",registro.clave);
                printf("\n Clasificacion: %s ", registro.cat);
                printf("\n Responsable de la publicacion: %s",registro.resp);
                printf("\n Telefono del responsable: %d",registro.tel);
                printf("\n Contenido del anuncio: %s",registro.content);
                printf("\n Fecha de publicacion: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
                getchar();
                fclose(flujo);
                return cont;
            }
            else{
                printf("\n No se encontro el responsable..");
            }
        }
        fclose(flujo);

    }
    return -1;
}

int busqueda_num (int llave) //busqueda por numero de anuncio
{
    FILE * flujo;
    struct anuncio_t registro;
    int cont=0;
    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio_t),1,flujo)>0)
        {
            cont++;
            if (llave==registro.clave)
            {
                printf("\n Numero de anuncio: %d",registro.clave);
                printf("\n Clasificacion: %s ", registro.cat);
                printf("\n Responsable de la publicacion: %s",registro.resp);
                printf("\n Telefono del responsable: %d",registro.tel);
                printf("\n Contenido del anuncio: %s",registro.content);
                printf("\n Fecha de publicacion: %d/%d/%d",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
                getchar();
                fclose(flujo);
                return cont;
            }
            else{
                printf("\n No se encontro ese numero de anuncio..");
            }
        }
        fclose(flujo);

    }
    return -1;
}

void editar()
{
    int ban;
    int llave;
    anuncio registro;

    FILE * flujo;
    setbuf(stdin,0);
    getchar();
    printf("Numero de anuncio: "); scanf("%d", &llave);
    ban=busqueda_num(llave);

    if (ban!=-1)
    {
        flujo= fopen("registros.dat","rb+");
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(anuncio),SEEK_SET);
            fread(&registro,sizeof(anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\n Numero de anuncio: %d \n",registro.clave);
            printf("Clasificacion: %s \n", registro.cat);
            printf("Responsable de la publicacion: %s \n",registro.resp);
            printf("Telefono del responsable: %d \n",registro.tel);
            printf("Fecha de publicacion: %d/%d/%d \n",registro.fecha[0], registro.fecha[1], registro.fecha[2]);
            printf("Escriba el nuevo contenido de la publicacion: "); setbuf(stdin,0);
            gets(registro.content);
            fseek(flujo,(ban-1)*sizeof(anuncio),SEEK_SET);
            fwrite(&registro,sizeof(anuncio),1,flujo);
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
   anuncio aux;
   original=fopen("registros.dat","rb");
   copia=fopen("temporal.dat","wb");
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       printf("Numero del anuncio que desea eliminar: ");
       setbuf(stdin, 0);
       getchar();
       scanf("%d", &llave);
       ban=busqueda_num(llave);
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(anuncio),1,original)>0)
           {    if(llave==aux.clave)
                   fwrite(&aux,sizeof(anuncio),1,copia);
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


void ordenar()
{
   FILE *flujo;
   int i, j;

   int n;
   anuncio a,b;

   flujo=fopen("registros.dat","rb+");

   if (flujo==NULL)
      printf("No se puede realizar la operacion");
   else
   {       i=0;
           //fseek(flujo,0,SEEK_END);
           //n=ftell(flujo)/sizeof(struct articulo);
           n=tamano(flujo)/sizeof(anuncio);
           printf("Ordenando %d registros ", n);
           getchar();
           for(i=0;i<n-1;i++)
           {
              for(j=i+1;j<n;j++)
              {
                fseek(flujo,i*sizeof(anuncio),SEEK_SET);
                fread(&a,sizeof(anuncio),1,flujo);
                fseek(flujo,j*sizeof(anuncio),SEEK_SET);
                fread(&b,sizeof(anuncio),1,flujo);
                printf("%d, %d, %s con %s \n", i,j,a.resp, b.resp);
                getchar();
                if( strcmp(a.resp,b.resp)>0)
                {
                    fseek(flujo,i*sizeof(anuncio),SEEK_SET);
                    fwrite(&b,sizeof(anuncio),1,flujo);
                    fseek(flujo,j*sizeof(anuncio),SEEK_SET);
                    fwrite(&a,sizeof(anuncio),1,flujo);
                }
              }
           }
           fclose(flujo);
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

