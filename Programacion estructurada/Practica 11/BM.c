/*PE 2021-1 Grupo 531*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINA 255

#define RESET "\x1B[0m"

typedef enum
{
    negro = 30,
    rojo,
    verde,
    amarillo,
    azul,
    magenta,
    cyan,
    gris_claro,
    gris = 90,
    rojo_claro,
    verde_claro,
    amarillo_claro,
    azul_claro,
    magenta_claro,
    cyan_claro,
    blanco
} Colores;

void set_color(Colores);
void set_bgcolor(Colores);
void reset_color();

typedef unsigned char int_8;

typedef enum
{
    CUBIERTO,
    EXPLORADO,
    BANDERA
} Estado_celda;
typedef enum
{
    PERDIDO,
    GANADO,
    EN_PROGRESO
} Estado_juego;

typedef struct
{
    Estado_celda estado;
    int_8 valor;
} celda_t;

typedef struct
{
    celda_t **celdas; /// [dimx][dimy]
    int_8 dimx;       /// 8
    int_8 dimy;       /// 8
} tablero_t;

tablero_t crea_tablero(int_8, int_8);

void muestra_tablero(tablero_t);
void muestra_celda(celda_t celda);
void captura(char *, int *, int *, int_8, int_8);
void movimiento(Estado_juego *, tablero_t, char, int_8, int_8);
void explorar(Estado_juego *, tablero_t, int_8, int_8);
void verifica_juego(Estado_juego *, tablero_t);

void inicializa_tablero(tablero_t, int);

int main(void)
{
    tablero_t tablero;
    Estado_juego juego = EN_PROGRESO;
    char opc;
    int i, j, z;

    srand(time(NULL));
    do{
        printf("\nFacil (0), Normal (1), Dificil (2)\nElija una dificiltad: ");
        scanf("%d", &z);
    } while(z>2 || z<0);

    switch (z) //DIFICULTAD
    {
    case 0:
        tablero = crea_tablero(8, 8);
        break;

    case 1:
        tablero = crea_tablero(16, 16);
        break;

    case 2:
        tablero = crea_tablero(24, 24);
        break;
    
    default:
        break;
    }
    inicializa_tablero(tablero, z);
    muestra_tablero(tablero);

    do
    {
        captura(&opc, &i, &j, tablero.dimx, tablero.dimy);
        printf("\nOPCION: %c, COORD: %d,%d", opc, i, j);

        movimiento(&juego, tablero, opc, i, j);
        muestra_tablero(tablero);
        verifica_juego(&juego, tablero);

    } while (juego == EN_PROGRESO);

    if (juego == GANADO)
        printf("\nHas ganado!");
    else
        printf("\nSuerte para la proxima!");

    return 0;
}

tablero_t crea_tablero(int_8 dimx, int_8 dimy)
{
    int j;
    tablero_t tablero;

    tablero.dimx = dimx;
    tablero.dimy = dimy;

    tablero.celdas = (celda_t **)calloc(dimx, sizeof(celda_t *));

    for (j = 0; j < dimx; j++)
    {
        tablero.celdas[j] = (celda_t *)calloc(dimy, sizeof(celda_t));
    }

    return tablero;
}

void inicializa_tablero(tablero_t tablero, int z)
{
    //10% de minas
    int minas;
    int i, j, x, y, k, w;
    int_8 vecinos;

    switch(z) //DIFICULTAD
    {
    case 0:
        minas = (int)tablero.dimx * tablero.dimy * 0.10;
        break;

    case 1:
        minas = (int)tablero.dimx * tablero.dimy * 0.14;
        break;

    case 2:
        minas = (int)tablero.dimx * tablero.dimy * 0.18;
        break;
    
    default:
        break;
    }

    /// Posicionar de forma aleatoria las minas usando rand
    ///     Verificar que no existan bombas en la misma posicion

    /// MODIFICAR LO SIGUIENTE
    while (minas)
    {
        i = rand() % tablero.dimx;
        j = rand() % tablero.dimy;
        if((tablero.celdas[i][j].valor)==MINA){
            continue;
        }
        else{
            tablero.celdas[i][j].valor = MINA;
            minas--;
        }
    }
    /// Calcular los numeros de las celdas segun el numero de minas al rededor

    ///Modificar lo siguiente
    for(y=0; y<tablero.dimy; y++){
        for(x=0; x<tablero.dimx; x++){
            vecinos=0;
            for(k=y-1; k<y+2; k++){
                for(w=x-1; w<x+2; w++){
                    if((k<tablero.dimy && k>=0) && (w<tablero.dimx && w>=0) && (tablero.celdas[k][w].valor==MINA)){
                        vecinos+=1;
                    }
                }
            }
            if(vecinos>0){
                tablero.celdas[y][x].valor = vecinos;
            }
        }
    }

    ///BORRAR
    //tablero.celdas[1][0].estado = EXPLORADO;
}

void muestra_tablero(tablero_t tablero)
{
    int i, j;

    printf("\n\n");

    for (i = 0; i < tablero.dimx; i++)
    {
        for (j = 0; j < tablero.dimy; j++)
        {
            if (!j)
                printf("%2c) | ", 'A' + i);
            muestra_celda(tablero.celdas[i][j]);
            printf(" | ");
        }
        printf("\n");
    }
    printf("    ");
    for (j = 0; j < tablero.dimy; j++)
    {
        printf(" %2d ", j);
    }
}

void muestra_celda(celda_t celda)
{
    switch (celda.estado)
    {
    case CUBIERTO:
        printf("%c", '-');
        break;
    case EXPLORADO:
        if (celda.valor != MINA)
        {
            set_color(celda.valor ? verde : amarillo);
            printf("%d", celda.valor);
            reset_color();
        }
        else
        {
            set_bgcolor(rojo_claro);
            set_color(gris);
            printf("%c", '*');
            reset_color();
        }
        break;
    case BANDERA:
        set_bgcolor(azul_claro);
        set_color(rojo);
        printf("%c", 'B');
        reset_color();
        break;
    }
}

void captura(char *opc, int *i, int *j, int_8 dimx, int_8 dimy)
{
    char fila;
    do
    {
        setbuf(stdin, NULL); // Limpia bufer de entrada
        printf("\nCaptura tu jugada (B: Bandera, E: Explorar ej. E A,2): ");
        scanf("%c %c,%i", opc, &fila, j);
        *i = fila - 'A';
        //printf("\nOPCION: %c, COORD: %d,%d", opc, *i, *j);
    } while ((*opc != 'B' && *opc != 'E') || *i >= dimx || *i < 0 || *j >= dimy);
}

void movimiento(Estado_juego *juego, tablero_t tablero, char opc, int_8 i, int_8 j)
{

    if (opc == 'B')
    {
        if (tablero.celdas[i][j].estado == CUBIERTO)
            tablero.celdas[i][j].estado = BANDERA;
        else if (tablero.celdas[i][j].estado == BANDERA)
            tablero.celdas[i][j].estado = CUBIERTO;
    }
    else if (opc == 'E')
        explorar(juego, tablero, i, j);
}

void explorar(Estado_juego *juego, tablero_t tablero, int_8 i, int_8 j)
{
    int x, y;

    if (tablero.celdas[i][j].estado == MINA)
    {
        *juego = PERDIDO;
        return;
    }

    if (tablero.celdas[i][j].estado == CUBIERTO)
    {
        tablero.celdas[i][j].estado = EXPLORADO;

        if (tablero.celdas[i][j].valor > 0)
            return;

        for (x = -1; x <= 1; x++)
            for (y = -1; y <= 1; y++)
            {
                if (!(x == 0 && y == 0) &&
                    (i + x) >= 0 &&
                    (j + y) >= 0 &&
                    (i + x) < tablero.dimx &&
                    (j + y) < tablero.dimy)
                    if (tablero.celdas[i + x][j + y].estado == CUBIERTO)
                        explorar(juego, tablero, i + x, j + y);
            }
    }
}

void verifica_juego(Estado_juego *juego, tablero_t tablero)
{
    int i, j;

    if (*juego != EN_PROGRESO)
        return;

    *juego = GANADO;

    for (i = 0; i < tablero.dimx; i++)
        for (j = 0; j < tablero.dimy; j++)
        {
            //Falta explorar
            if (tablero.celdas[i][j].valor != MINA && tablero.celdas[i][j].estado != EXPLORADO)
            {
                *juego = EN_PROGRESO;
                return;
            }
        }
}

void set_color(Colores color)
{
    printf("\x1B[%dm", color);
}

void set_bgcolor(Colores color)
{
    printf("\x1B[%dm", color + 10);
}
void reset_color()
{
    printf(RESET);
}
