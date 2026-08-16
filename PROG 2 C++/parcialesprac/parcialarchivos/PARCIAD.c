/*
PARCIAL  D, SE DISPONE DEL ARCHIVO PREMIOS CON LA INFORMACION DE LA PREMIACION DE DEPORTISTAS EN DIVERSAS CATEGORIAS Y LA MEDALLA OBTENIDA (ORO, PLATA, BRONCE)
ESTE ARCHIVO ESTRUCTURADO CON REGISTROS QUE TIENEN LA SIGUIENTE FORMA: STRUCT {char NOM[20], char DEPORTE[20], char MEDALLA[20]};
Y EL ARCHIVO REPRESENTACION CON ESTRUCTURAS DE LA FORMA: STRUCT {char NOM[20]], char PAIS [20]}; CREAR UN PROGRAMA QUE PERMITA INGURESAR UN DEPORTE POR LINEA DE COMANDOS Y MUESTRE QUE PAISES LOGRARON LAS MEDALLAS DE ORO, PLATA Y BRONCE EN ESE DEPORTE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct PREMIO {
		char NOM[20];
		char DEPORTE[20];
		char MEDALLA[20];
};

struct REPRESENTACION {
		char NOM[20];
		char PAIS[20];
};


int main(int arc, char **argv )
{
    FILE *FP1, *FP2;
    struct PREMIO PREM;
    struct REPRESENTACION REPRE;
    char *BUSQUEDA = argv[1];
    int CONT_ORO = 0;

    if( !(FP1 = fopen( "PREMIOS", "rb" )) ){
        printf("\n\nERROR EN LA APERTURA PREMIOS");
        exit(1);

    }
    if( !(FP2 = fopen("REPRESENTACION", "rb"))){
        printf("\n\nERROR EN LA APERTURA PREMIOS");
        exit(1);
    }

    fread(&REPRE, sizeof(REPRE), 1, FP2);
    while(!feof(FP2)){
        if(!strcmpi(BUSQUEDA, REPRE.PAIS)){
            rewind(FP1);
            fread(&PREM, sizeof(PREM), 1, FP1);
            while(!feof(FP1)){
                if(!strcmpi(PREMIO.NOM,REPRE.NOM) && strcmpi(PREMIO.MEDALLA, "ORO")){
                    CONT_ORO++;
                }
                fread(&PREM, sizeof(PREM), 1, FP1);
            }
        }
      fread(&REPRE, sizeof(REPRE), 1, FP2);

    }
    printf("\n\n\tEL PAIS %s OBTUVO %d MEDALLAS DE ORO", BUSQUEDA, CONT_ORO);
    return 0 ;
}

