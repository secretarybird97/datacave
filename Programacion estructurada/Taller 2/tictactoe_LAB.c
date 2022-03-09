#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void inicializar_tablero(char[3][3]); // llenar el arreglo de espacios
void dibujar_tablero(char[3][3]);
char asignar_turno(); //'X' o  'O'
//Tablero, turno, coordenadas x,y
int movimiento(char[3][3], char, int, int);
int espacios_disponibles(char[3][3]); //1 si si hay espacios. 0 Caso contrario
char verificar_ganador(char[3][3], char); //'X', 'O', NULL
//Regresan 1 si hay una linea completa igual que no sean vacios
//Regresan 0 en caso contrario
int dia(char[3][3]);
int hor(char[3][3]);
int ver(char[3][3]);

int main(void)
{
    printf("TicTaoe!\n");
    int opt, i=0;
    int victoiax=0, victoriao=0, empate=0;
    do{
        long long iniciot, finalt, tiempo;
        char tablero[3][3];
        char turno; // 'X' o 'O'
        int x,y,k;
        int fin = 0; //0 No se ha acabado. 1 ya se acabo
        i++;

        srand(time(NULL)); //Establece una semilla

        turno = asignar_turno();
        inicializar_tablero(tablero);
        time(&iniciot);
        printf("\nJPartida #%d", i);
        do{
            printf("\nTurno: %c\n", turno);
            dibujar_tablero(tablero);

            do{
            printf("\nIngrese las coordenadas (ej. 0,1): ");
            scanf("%d, %d", &x, &y);
            }while(!movimiento(tablero, turno, x, y));

            if(verificar_ganador(tablero, turno))
            {//Si la funcion regresa algo diferente de 0 (ej. 'X' o 'O')
                time(&finalt);
                tiempo = finalt -iniciot;
                fin = 1;
                printf("\nFelicidades!!, el jugador %c GANO!\nDuracion de la partida: %d s\n", turno, tiempo);
                dibujar_tablero(tablero);
                if (turno=='X'){
                    victoiax++;
                }
                else{
                    victoriao++;
                }

            }
            else
                if(!espacios_disponibles(tablero))
                {//Verificar si hay espacio disponibles
                    tiempo = finalt -iniciot;
                    printf("\nEs un EMPATE...\nDuracion de la partida: %d s\n", tiempo);
                    empate++;
                    dibujar_tablero(tablero);
                    fin = 1;
                }

            //Cambio de turno
            if(turno=='X')
                turno = 'O';
            else
                turno = 'X';
            //EQUIVALENTE turno = turno=='X'? 'O' : 'X';
        }while(!fin);
        k=0;
        printf("\n");
        do{
            printf("\nDesea volver a jugar? 0) Si. 1) No: ");
            scanf("%d", &opt);
            if(opt==1){
                k=1;
                printf("Victorias de X: %d\nVictorias de O: %d\nEmpates: ", victoiax, victoriao, empate);
            }
            else if(opt==0){
                k=1;
            }
        }while(k!=1);


    }while(opt!=1);


    return 0;
}

int espacios_disponibles(char tablero[3][3])
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(tablero[i][j] == ' ')
                return 1;
    return 0;
}

void inicializar_tablero(char tablero[3][3])
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            tablero[i][j] = ' ';
}

void dibujar_tablero(char tablero[3][3])
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf(" %c ",tablero[i][j]);
            if(j<2)
                printf("|");
            else
                printf("\n");
        }
        if(i<2)
            printf("-----------\n");
    }
}

char asignar_turno()
{
    if(!(rand()%2))// par eq rand()%2==0
        return 'X';
    else
        return 'O';
}

int movimiento(char tablero[3][3], char turno, int x, int y)
{
    /*Regresa 1:Valido y 0:No valido*/
    if(x>=0 && x<=2 && y>=0 && y<=2)
        if(tablero[x][y]==' ')
        {
            tablero[x][y]=turno;
            return 1;
        }

    return 0;
}

char verificar_ganador(char tablero[3][3], char turno)
{
    if(dia(tablero)||hor(tablero)||ver(tablero))
        return turno;
    else
        return 0; //caracter nulo '\x0'
}


int dia(char tablero[3][3])
{
    if(tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
        if(tablero[0][0] != ' ')
            return 1;

    if(tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
        if(tablero[1][1] != ' ')
            return 1;

    return 0;
}

int hor(char tablero[3][3])
{
    if(tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2])
        if(tablero[0][0] != ' ')
            return 1;

    if(tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2])
        if(tablero[1][0] != ' ')
            return 1;

    if(tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2])
        if(tablero[2][0] != ' ')
            return 1;

    return 0;
}


int ver(char tablero[3][3])
{
    if(tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0])
        if(tablero[0][0] != ' ')
            return 1;

    if(tablero[0][1] == tablero[1][1]&& tablero[0][1] == tablero[2][1])
        if(tablero[0][1] != ' ')
            return 1;

    if(tablero[0][2] == tablero[1][2]&& tablero[0][2] == tablero[2][2])
        if(tablero[0][2] != ' ')
            return 1;

    return 0;
}








