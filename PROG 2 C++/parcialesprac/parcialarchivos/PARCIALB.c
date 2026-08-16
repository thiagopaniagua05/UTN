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

struct PRECIO_HOTEL {
		char HOTEL[20];
		char CATEGORIA[20];
		int PRECIO_DIARIO[20];
};

int main(int arc, char **argv )
{
    FILE *FP;
    struct PRECIO_HOTEL H;
    char *NOM_HOTEL = argv[1];
    char *NOM_CAT = argv[2];
    int PREC_DIARIO = atoi(argv[3]);
    int COST_TOTAL = 0;

    if( !(FP = fopen( "PRECIOS", "rb" )) ){
        printf("\n\nERROR EN LA APERTURA PRECIOS");
        exit(1);

    }


    fread(&H, sizeof(H), 1, FP);
    while(!feof(FP)){
        if(!strcmpi(NOM_HOTEL, H.HOTEL) && !strcmpi(NOM_CAT, H.CATEGORIA)){
            COST_TOTAL = H.PRECIO_DIARIO * PREC_DIARIO;

            }
        }
      fread(&H, sizeof(H), 1, FP);


    printf("\n\n\tEL HOTEL TIENE UN VALOR DE %d PESOS",CONT_TOTAL);
    fclose(FP)
    return 0 ;
}

