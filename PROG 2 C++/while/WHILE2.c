#include <stdio.h>
#include <stdlib.h>

int main(){


    int PASS;

    printf("\nINGRESE LA CONTRASEÑA PARA AVANZAR : ");
    scanf("%d", &PASS);

    if(PASS != 123)
    {
      do{
            printf("\nCONTRASEÑA INCORRECTA, POR FAVOR INTENTE NUEVAMENTE");
            printf("\nCONTRASEÑA : ");
            scanf("%d", &PASS);
        }
        while( PASS != 123);
    }

    if(PASS == 123)
    {
        printf("\nCONTRASEÑA CORRECTA!");
    }

    getch();
    return 0 ;
}



