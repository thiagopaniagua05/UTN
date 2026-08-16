#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>



int main( int argc , char ** argv, char ** envp ){

    int I ;

    printf ("\n\n\t\t LISTA DE VARIABLES DE ENTRONO\n\n");

    sfor (  ; envp ; envp++ )
        printf("\n\t\t %s" , *envp );
    printf("\n\n");

/*
    char **P ;
    for ( P = envp ; *P ; P++ )
        printf("\n\t\t %s" , *P)
 */ getch();
    return 0 ;
}



