#include <stdio.h>
#include <conio.h>


/*1. Ingresar un nombre e imprimir la totaldiad de datos que le corresponde o indicar que no esta.
2. Permitir el codigo de una nota, por ej 3, y ordenar el vector de estructuras completo en forma decreciente de esa nota. Quiero al principio los alumnos con mejores notas.
3. Construir la funcion PROMEDIO que recibe una estructura de tipo alumno y retorna el promedio flotante de ese alumno. Osea el promedio de sus notas enteras.
4. Permitir el ingreso de una materia y determinar los dos mejores alumnos en esa materia para una competencia*/

void main(){

    unsigned char * P ;
    int A ;
    int I ;

    A = 0X4B27FF30 ;
    printf("\n\n  ") ;

    P = (unsigned char *)&A ;

    printf("\n\n\t\t");
    for ( I = 0 ; I < 4 ; I++ )
         printf("%10X " , *(P + I) ) ;

    // LITTLE ENDIAN

    printf("\n\n\t\t");
    for ( P = (char *)&A ; P < (unsigned char *) (&A + 1) ; P++ )
         printf("%10X " , *P ) ;


   getch();
   return 0 ;
}



