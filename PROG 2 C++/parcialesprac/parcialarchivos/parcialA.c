/*  EL ARCHIVO "INGRESO" TIENE LOS DATOS DE LEGAJOS DE ALUMNOS */
/*  QUE SE INSCRIBIERON EN 4 CARRERAS                        */

/*  EL ARCHIVO "EXAMEN" TIENE LOS DATOS DE LOS ALUMNOS INSCRIPTOS  */
/*  QUE SE PRESENTARON AL EXAMEN DE INGRESO, Y LA NOTA QUE OBTUVIERON */

/*  SE DESEA SABER CUANTOS ALUMNOS DE INGENIERIA RINDIERON EL INGRESO */
/*  Y CUANTOS DE ESTOS APROBARON                                      */



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

