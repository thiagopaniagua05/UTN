#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct PROFILE{
    char NAME[20];
    char EMAIL[30];
    char PASSWORD[20];
    int EDAD;
};



int main(){

    struct PROFILE P1;

    printf("\nINGRESE SU NOMBRE PARA CREAR UNA CUENTA: ");
    gets(P1.NAME);
    printf("\nEL EMAIL: ");
    gets(P1.EMAIL);
     do{
        printf("\nAHORA INGRESA TU EDAD: ");
        scanf("%d", &P1.EDAD);
        if(P1.EDAD < 18 )
            printf("\nERES MENOR DE EDAD, NO PUEDES SEGUIR");
    }while(P1.EDAD < 18);
    fflush(stdin);
    printf("\nPOR ULTIMO INGRESE LA CONTRASENIA: ");
    gets(P1.PASSWORD);
    printf("\nUSUARIO CREADO");

    printf("\n\nLOGIN");
    printf("\nINGRESE SU NOMBRE PARA LOGUEAR: ");


    getch();
    return 0 ;
};



