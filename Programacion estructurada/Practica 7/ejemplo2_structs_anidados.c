#include<stdio.h>

struct fecha{
    int dia;
    int mes;
    int year;
};

struct alumno{
    int matricula;
    char nombre[36];
    char apellidom[36];
    char apellidop[36];
    struct fecha fecha_ing;
    struct fecha fecha_nac;
    float promedio;
};

struct alumno captura_alumno(void);
struct fecha captura_fecha(void);
void imprime_alumno(struct alumno);
void imprime_fecha(struct fecha);


int main(void)
{
    struct alumno al, alumno2;

    al = captura_alumno();
    alumno2 = captura_alumno();

    imprime_alumno(al);

    return 0;
}

struct fecha captura_fecha(void)
{
    struct fecha f;
    printf("\nIngrese fecha (ej dd/mm/aaaa): ");
    scanf("%d/%d/%d", &f.dia, &f.mes, &f.year);

    return f;
}


struct alumno captura_alumno(void)
{
    struct alumno al;

    printf("Ingrese la siguiente informacion del alumno.");
    printf("\nMatricula: "); scanf("%d", &al.matricula);
    printf("Nombre: "); scanf("%s", al.nombre);
    printf("Apellido paterno: "); scanf("%s", al.apellidop);
    printf("Apellido materno: "); scanf("%s", al.apellidom);
    printf("Fecha de ingreso. ");
    al.fecha_ing = captura_fecha();
    printf("Fecha de nacimiento. ");
    al.fecha_nac = captura_fecha();
    al.promedio = 85.0f;

    return al;
}

void imprime_fecha(struct fecha f)
{
    printf(" %d/%d/%d ", f.dia, f.mes, f.year);
}

void imprime_alumno(struct alumno al)
{
    printf("Informacion del alumno\n");
    printf("\nMatricula: %d", al.matricula);
    printf("\nNombre: %s", al.nombre);
    printf("\nApellido paterno: %s", al.apellidop);
    printf("\nApellido materno: %s", al.apellidom);
    printf("\nFecha de ingreso: "); imprime_fecha(al.fecha_ing);
    printf("\nFecha de nacimiento: "); imprime_fecha(al.fecha_nac);
    printf("\nPromedio: %.1f", al.promedio);
}




