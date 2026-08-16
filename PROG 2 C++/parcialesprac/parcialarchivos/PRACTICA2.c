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

        if(!( FA = fopen("INGRESO.dat", "rb") )){
            printf("\n\nERROR  EN LA APERTURA DEL ARCHIVO INGRESO");
            exit(1);
        }

        if(!( FE = fopen("EXAMEN.dat", "rb"))){
            printf("\n\nERROR EN LA APERTURA DEL ARCHIVO INGRESO");
            exit(2);
        }

        printf("\n\nDATOS DEL ARCHIVO INGRESO:\n");

        fread(&Alum, sizeof(Alum), 1 , FA);
        while( !feof(FA) ){
            printf("\n\t\t LEGAJO : %-7d CARRERA : %-10s", Alum.LEG, Alum.CARRERA);
            fread(&Alum, sizeof(Alum), 1 , FA);
        }

        fseek(FA, 0L * sizeof(Alum), SEEK_END);
        printf("\n\nEL PESO EN BYTES DEL ARCHIVO INGRESO ES DE : %d", ftell(FA));
        printf("\n\nLA CANTIDAD DE INGRESOS ES DE: %d", ftell(FA)/sizeof(Alum));
        getchar();

        printf("\n\n");
        fread(&Exa, sizeof(Exa), 1 , FE);
        while( !feof(FE) ){
            printf("\n\t\t LEGAJO : %-7d NOTA : %-1d", Exa.LEG, Exa.NOTA);
            fread(&Exa, sizeof(Exa), 1, FE);
        }
        getchar();
        fseek(FE, 0L *sizeof(Exa), SEEK_END);
        printf("\n\nEL PESO EN BYTES DEL ARCHIVO INGRESO ES DE : %d", ftell(FE));
        printf("\n\nLA CANTIDAD DE ALUMNOS QUE RINDIERON EXAMENES ES DE: %d", ftell(FE)/sizeof(Exa));
        fclose(FE);
        fclose(FA);
        return 0 ;
}


