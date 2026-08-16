#include <stdio.h>
#include <conio.h>

void main(){

    int * P ;
    char * Q ;
    int A ;

    printf("\n\n LA DIRECCION DE A ES  %10d %10o %10X %10p " , &A , &A , &A ) ;

    P = &A ;
    printf("\n\n LA DIRECCION DE P ES  %10d %10o %10X %10p" , P , P , P ) ;

    P = (int *) 0X2000 ;
    printf("\n\n EL CONTENIDO DE P ES %10X" , P ) ;

    P = P + 4 ;

    printf("\n\n EL CONTENIDO DE P ES %10X" , P ) ;


    Q = (char *) 0X2000 ;
    printf("\n\n EL CONTENIDO DE Q ES %10X" , Q ) ;

    Q = Q + 4 ;

    printf("\n\n EL CONTENIDO DE Q ES %10X" , Q ) ;

   getch();
   return 0;
}



