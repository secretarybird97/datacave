///ahorcado.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* nombre;
    char** frases;
    int num;
}categoria_t;

typedef struct {
    categoria_t* lista;
    int num;
}categorias_t;

void agrega_categoria(categorias_t*, char*);
void agrega_frase(categoria_t*, char*);
void imprime_todo(categorias_t);
void reemplazar(char*, char, char);
void mayus(char*);
categorias_t leer_categorias(FILE*);
void imprime_categorias(categorias_t);
char* crea_mascara(char*);
int destapa(char*, char*, char);
int completado(char*);
char* frase_random(categoria_t);
int existe_char(char*, char);
void agregar_char(char*, char);
void mostrar_oculta(char*);
long int size(FILE * file);


int main(int argc, char **argv)
{
    FILE *file;

    categorias_t categorias = {0};
    char *frase; ///" _ _ _   _ _ _"
    char* respuesta;
    char* letras=calloc(1,1); ///"AZ"

    srand(time(NULL));

    if (!(argc > 1))
    {
        printf("Error en los parametros por consola.\nRequiere nombre de archivo a leer.");
        exit(-1);
    }

    ///Se abre el archivo modo lectura ("r")
    file = fopen(argv[1], "r");

    ///Se comprueba si se ha abierto de forma correcta
    if (!file)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }


    categorias = leer_categorias(file);



    imprime_categorias(categorias);

    imprime_todo(categorias);


    respuesta = frase_random(categorias.lista[0]);
    printf("\nRespuesta: %s\n", respuesta);



    frase = crea_mascara(respuesta);

    printf("\nMascara: %s\n", frase);

    destapa(frase, respuesta, 'M');

    printf("\nDestapada:%s\n", frase);


    agregar_char(letras, 'Z');
    agregar_char(letras, 'A');
    agregar_char(letras, 'Z');//NO se agrega

    printf("\nLetras: %s\n", letras);

    mostrar_oculta(frase);





    fclose(file);

    return EXIT_SUCCESS;
}

void mostrar_oculta(char* frase)
{
    putchar('\n');
    while(*frase)
    {
        printf(" %c ",*frase==' '?'\t':*frase);
        frase++;
    }
}

char* frase_random(categoria_t categoria)
{
    return categoria.frases[rand()%categoria.num];
}

int existe_char(char* cadena, char car)
{
    while(*cadena)
    {
        if(*cadena==car)
            return 1;
        cadena++;
    }
    return 0;
}

void agregar_char(char* cadena, char car)
{
    int tam;

    if(!existe_char(cadena, car))
    {
        tam = strlen(cadena);
        cadena = realloc(cadena, tam+1);
        cadena[tam+1]='\x0';
        cadena[tam]=car;
    }
}


int destapa(char* oculta, char* respuesta, char letra)
{
    int encontradas=0;
    while(*respuesta)
    {
        if(*respuesta==letra)
        {
            *oculta=*respuesta;
            encontradas++;
        }
        respuesta++;
        oculta++;
    }
    return encontradas;
}

int completado(char* frase)
{
    return !existe_char(frase, '_');
}


char* crea_mascara(char* respuesta)
{
    char* oculto = calloc(strlen(respuesta), 1);
    char* cad = respuesta;
    char* ptr_oculto = oculto;
    while(*cad)
    {
        *ptr_oculto = *cad>='A'&&*cad<='Z' ? '_' : ' ';
        cad++;
        ptr_oculto++;
    }

    return oculto;
}


void agrega_categoria(categorias_t* categorias, char* nombre)
{
    if(!categorias->lista)
        categorias->lista = calloc(sizeof(categoria_t),1); //FAIL PORQUE EL APUNTADOR FRASE NO ERA CERO CON MALLOC
    else
        categorias->lista = realloc(categorias->lista, sizeof(categoria_t)*(categorias->num+1));

    categorias->lista[categorias->num].nombre = calloc(strlen(nombre)-1, 1);
    strcpy(categorias->lista[categorias->num].nombre, nombre+1); ///nombre es el buffer

    categorias->num++;
}

void agrega_frase(categoria_t* categoria, char* frase)
{
    if(!categoria->frases)
        categoria->frases = malloc(sizeof(char**));
    else
        categoria->frases = realloc(categoria->frases, sizeof(char**)*(categoria->num+1));

    categoria->frases[categoria->num] = calloc(strlen(frase), 1);
    strcpy(categoria->frases[categoria->num], frase);

    categoria->num++;
}

void imprime_todo(categorias_t categorias)
{
    int i, j;
    for(i=0; i<categorias.num; i++)
    {
        printf("*** %s ***\n",categorias.lista[i].nombre);
        for(j=0; j<categorias.lista[i].num; j++) ///numero de frases
            printf(" %d- %s \n",j+1,categorias.lista[i].frases[j]);
    }
}

void imprime_categorias(categorias_t categorias)
{
    int i;
    for(i=0; i<categorias.num; i++)
    {
        printf("%2d) %s \n",i+1, categorias.lista[i].nombre);
    }
}


void reemplazar(char*cad, char car, char new_car)
{
    while(*cad)
    {
        if(*cad==car)
            *cad=new_car;
        cad++;
    }
}

void mayus(char* cad)
{
    while(*cad)
    {
        if(*cad>='a' && *cad<='z')
            *cad-=32;
        cad++;
    }
}

categorias_t leer_categorias(FILE* file)
{
    categorias_t categorias = {0};
    int num_categoria=-1;
    char buffer[128];
    long int tamano;

    tamano=size(file); // TAMANO DEL ARCHIVO EN BYTES (CARACTERES)

    do
    {
        fgets(buffer, 128, file); //Lee un renglon del archivo
        reemplazar(buffer,'\n','\x0');
        mayus(buffer);

        if(buffer[0] == '-')
        {
            agrega_categoria(&categorias, buffer);
            num_categoria++;
        }
        else if(buffer[0]<='Z'&&buffer[0]>='A')
        {
            agrega_frase(&categorias.lista[num_categoria], buffer);
        }
    }while(tamano>ftell(file)); //MIENTRAS QUE NO SE HAYAN LEIDO TODOS LOS CARACTERES SEGUN EL INDICADOR DE POS


    return categorias;
}

long int size(FILE * file)
{
    long int bytes=0;
    unsigned char c;
    rewind(file);
    while(fread(&c,1,1,file)>0)bytes++;
    rewind(file);
    return bytes;
}

