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

struct ALUMNO {
		int LEG ;
		char CARRERA[20];
};

struct EXAMEN {
		int LEG ;
		int NOTA ;
};


int main( )
{
        FILE *FA, *FE ;

        struct ALUMNO Alum ;
        struct EXAMEN Exa  ;

        int RINDIERON = 0 ;
        int APROBARON = 0 ;
        char ING[20] = "INGENIERIA" ;

        if(!( FA = fopen("INGRESO.dat", "rb") )){
            printf("\n\nERROR  EN LA APERTURA DEL ARCHIVO INGRESO");
            exit(1);
        }

        if(!( FE = fopen("EXAMEN.dat", "rb"))){
            printf("\n\nERROR EN LA APERTURA DEL ARCHIVO INGRESO");
            exit(2);
        }

        printf("\n\nDATOS DEL ARCHIVO INGRESO:\n");



        fread(&Alum, sizeof(Alum), 1, FA);
        while( !feof(FA) ){
            rewind(FE);
            if(strcmpi(Alum.CARRERA, ING) == 0){
                fread(&Exa, sizeof(Exa), 1, FE);
                while( !feof(FE) ){
                    if(Alum.LEG == Exa.LEG){
                        RINDIERON++;
                        if( Exa.NOTA >= 6 ){
                            APROBARON++;
                        }
                    }
                    fread(&Exa, sizeof(Exa), 1 , FE);
                }

            }
            fread(&Alum, sizeof(Alum), 1 , FA);
        }

        fclose(FE);
        fclose(FA);
         printf("\n\n\tRINDIERON EL EXAMEN %d, APROBARON EL EXAMEN %d", RINDIERON, APROBARON);
        return 0 ;
}

