#include <stdio.h>
#define TAM 51

typedef struct {
    int voc;
    int cons;
    int dig;
} chain;

void chain_specs(char[], chain*); //captura el numero de vocales, consonantes, y digitos de una cadena
void chain_space(char[]); //elimina los espacios de la cadena
int main(void){
    char cadena[TAM];
    printf("Inserte una cadena de caracteres: ");
    scanf("%[^\n]s", cadena);
    chain x;
    chain_specs(cadena, &x); 
    printf("\n%c%s%c\n", 34, cadena, 34);
    printf("Numero de vocales: %d\n", x.voc);
    printf("Numero de consonantes: %d\n", x.cons);
    printf("Numero de digitos: %d\n", x.dig);
    chain_space(cadena);
    printf("\nSin espacios!\n%s", cadena);


    return 0;
}

void chain_specs(char array[TAM], chain *cadena){
    int i, a, voc=0, cons=0, dig=0;
    for(i=0; i<TAM-1; i++){
        a=("%d", array[i]); //valor ascii del caracter actual
        if(a==97 || a==101 || a==105 || a==111 || a==117){ //verifica si es vocal
            voc+=1;
        }
        else if((a>=65 && a<=90) || (a>=97 && a<=122)){ //verifica si es consonante
            cons+=1;
        }
        if(a>=48 && a<=57){ //verifica si es digito
            dig+=1;
        }
    }
    cadena->cons = cons;
    cadena->voc = voc;
    cadena->dig = dig;
}

void chain_space(char array[TAM]){
    int size=TAM-1, a, num=0, i, j=0;
    for(i=0; i<TAM-1; i++){ //cuenta el numero  de espacios en la cadena
        a=("%d", array[i]);
        if(a==32){
            num++;
        }
    }

    int espacios[num];
    for(i=0; i<TAM-1; i++){ //captura en un arreglo en que lugar estan los espacios
        a=("%d", array[i]);
        if(a==32){
            espacios[j]=i;
            j++;
        }
    }

    for(i=0; i<num; i++){ 
        espacios[i]-=i;
        for(j=espacios[i]; j<TAM-1; j++){ //mueve los caracteres un lugar hacia atras
            a=("%d", array[j]);
            if((j+1)>=(TAM)){
                break;
            }
            if(a>=32 && a<=255){
                array[j]=array[j+1];
            }
            else{
                continue;
            }
        }
    }
}