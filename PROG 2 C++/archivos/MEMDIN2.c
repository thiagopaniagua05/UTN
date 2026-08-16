#include <stdio.h>
#include <conio.h>



int main( int argc , char ** argv ){

    int I ;

    printf ("\n\n\t\t LISTA DE NOMBRES\n\n");

    for ( I = 0 ; I < *(argv+1) ; I++)
        printf("\n\\\t\t %s" , *(argv+2) );

    getch();
    return 0 ;
}



