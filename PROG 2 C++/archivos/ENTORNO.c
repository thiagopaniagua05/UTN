#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>



int main( int argc , char ** argv, char ** envp ){

    int I ;

    for (  ; envp ; envp++ )
        printf("\n\t\t %s" , *envp );
    printf("\n\n");


    getch();
    return 0 ;
}



