#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){


    char PASS[20];



    do{
        printf("\nINGRESE LA CONTRASEÑA PARA AVANZAR : ");
        gets(PASS);
        if(strcmp(PASS, "THIAGO") != 0)
            printf("\nCONTRASEÑA INCORRECTA, POR FAVOR INTENTE NUEVAMENTE");

    }
        while( strcmp(PASS, "THIAGO") != 0);


    if(strcmp(PASS, "THIAGO") == 0)
    {
        printf("\nCONTRASEÑA CORRECTA!");
    }

    getch();
    return 0 ;
}



