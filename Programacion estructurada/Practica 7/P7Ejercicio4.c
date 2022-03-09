#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct estructura_alumno{ //estructura de un alumno
    int matricula;
    char nombre[36];
    char apellido_paterno[36];
    char apellido_materno[36];
    int ingreso[3];
    int nacimiento[3];
    int promedio;
} alumno;

alumno captura_alumno(void); //captura los datos de un alumno
void mostrar_alumno(alumno);
float promedio_grupo(alumno[], int);
int grupo_aprobados(alumno[], int);
int grupo_reprobados(alumno[], int);
void buscar_alumno_matricula(alumno[], int, int);
void buscar_alumno_nombre(alumno[], int, char[]);

int main (void){
    srand(time(NULL));
    int n, i; float z; char nombrea[36]; int mat;
    printf("Este programa captura los datos de cada alumno, de un grupo universitario");
    printf("\nDe cuantos alumnos es el grupo? ");
    scanf("%d", &n);
    alumno grupo[n];
    for(i=0; i<n; i++){
        printf("\nDATOS DE ALUMNO %d", i+1);
        grupo[i] = captura_alumno();
    }
    mostrar_alumno(grupo[0]);
    printf("\nPromedio del grupo: %.2f", promedio_grupo(grupo, n));
    printf("\nAlumnos aprobados: %d", grupo_aprobados(grupo, n));
    printf("\nAlumnos reprobados: %d", grupo_reprobados(grupo, n));
    printf("\nQue matricula desea buscar? ",);
    scanf("%d", &mat);
    buscar_alumno_matricula(grupo, n, mat);
    /*printf("\nQue nombre desea buscar?: ");
    scanf(" %[^\n]s", nombrea);
    buscar_alumno_nombre(grupo, n, nombrea);*/
    return 0;
}

alumno captura_alumno(void){
    alumno x;
    printf("\nMatricula del alumno (ej. 1279713): ");
    scanf("%d", &x.matricula);
    printf("Nombre del alumno: ");
    scanf(" %[^\n]s", x.nombre);
    printf("Apellido paterno: ");
    scanf(" %[^\n]s", x.apellido_paterno);
    printf("Apellido materno: ");
    scanf(" %[^\n]s", x.apellido_materno);
    printf("Fecha de ingreso (ej. 2021/08/27): ");
    scanf("%d/%d/%d", &x.ingreso[0], &x.ingreso[1], &x.ingreso[2]);
    printf("Fecha de nacimiento (ej. 2021/08/27): ");
    scanf("%d/%d/%d", &x.nacimiento[0], &x.nacimiento[1], &x.nacimiento[2]);
    x.promedio = rand() % 101; //asigna un numero aleatorio del 0 al 100
    printf("Promedio final: %d", x.promedio);
    return x;
}

void mostrar_alumno(alumno x){
    printf("\n#%d, %s, %s, %s, %d/%d/%d, %d/%d/%d, %d", x.matricula, x.nombre, x.apellido_paterno, x.apellido_materno, x.ingreso[0], x.ingreso[1], x.ingreso[2], x.nacimiento[0], x.nacimiento[1], x.nacimiento[2], x.promedio);
}

float promedio_grupo(alumno x[], int n){
    float sum=0, prom; 
    int i;
    for(i=0; i<n; i++){
        sum+= x[i].promedio;
    }
    prom = sum/n;
    return prom;
}

int grupo_aprobados(alumno x[], int n){
    int sum=0, i;
    for(i=0; i<n; i++){
        if(x[i].promedio>=60){
            sum++;
        }
    }
    return sum;
}

int grupo_reprobados(alumno x[], int n){
    int sum=0, i;
    for(i=0; i<n; i++){
        if(x[i].promedio<60){
            sum++;
        }
    }
    return sum;
}

void buscar_alumno_matricula(alumno x[], int n, int matricula){
    int i, k, z;
    for(i=0; i<n; i++){
        if(x[i].matricula==matricula){
            k=1;
            z=i;
            break;
        }
    }
    if(k==1){
        printf("\nAlumno #%d encontrado: ", matricula);
        /*mostrar_alumno(x[z]);*/
        printf("\n#%d, %s, %s, %s, %d/%d/%d, %d/%d/%d, %d", x[z].matricula, x[z].nombre, x[z].apellido_paterno, x[z].apellido_materno, x[z].ingreso[0], x[z].ingreso[1], x[z].ingreso[2], x[z].nacimiento[0], x[z].nacimiento[1], x[z].nacimiento[2], x[z].promedio);
    }
}

void buscar_alumno_nombre(alumno x[], int n, char nombre[36]){
    int i, k, z;
    for(i=0; i<n; i++){
        if(x[i].nombre==nombre || x[i].apellido_paterno==nombre || x[i].apellido_materno==nombre){
            k=1;
            z=i;
            break;
        }
    }
    if(k==1){
        printf("\nAlumno encontrado: ");
        /*mostrar_alumno(x[z]);*/
        printf("\n#%d, %s, %s, %s, %d/%d/%d, %d/%d/%d, %d", x[z].matricula, x[z].nombre, x[z].apellido_paterno, x[z].apellido_materno, x[z].ingreso[0], x[z].ingreso[1], x[z].ingreso[2], x[z].nacimiento[0], x[z].nacimiento[1], x[z].nacimiento[2], x[z].promedio);
    }
}