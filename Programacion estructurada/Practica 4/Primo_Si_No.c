#include <stdio.h>

int main(void)
{
   int num; int d=0; int i=1;/* declaracion de variables */
   printf("Ingresa un numero para saber si es primo o no: ");
   scanf("%d", &num);
   while(i<num){
      if (num%i==0){
         d+=1; /* d igual a numero de divisores*/
      }
      i+=1;
   }
   if (d<=1)
      printf("%d es numero primo", num);
   else
      printf("%d NO es numero primo", num);
   return 0;
}
