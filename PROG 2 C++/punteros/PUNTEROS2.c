#include <stdio.h>
#include <conio.h>

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



