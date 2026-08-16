#include <stdio.h>
#include <stdlib.h>

int main(){


    int OPC = 0;

    while ( OPC != 3 )
    {
        printf("\n 1 - OPCION");
        printf("\n 2 - OPCION");
        printf("\n 3 - OPCION (SALIR)");
        printf("\n ELIGE UNA OPCION : ");
        scanf("%d", &OPC);
    }

    getch();
    return 0 ;
}



