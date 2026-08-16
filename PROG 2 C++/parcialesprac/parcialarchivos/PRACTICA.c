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
        struct EXAMEN E ;
		//struct ALUMNO X ;
		FILE * FP ;

        if(!(FP = fopen ( "EXAMEN.dat" , "rb"))) {
            printf(" ERROR EN CREACION DE BD ");
            exit(1) ;

        }

		printf("DATOS DEL  ARCHIVO \n\n");


		fread( &E, sizeof(E), 1 , FP);
		while( ! feof(FP) ){
            printf("\n\t\t %d %-1d", E.LEG, E.NOTA);
            fread( &E, sizeof(E), 1 , FP);
		}

		fseek( FP , 0L * sizeof(E) , SEEK_END);
		getchar();
		printf("\n\t\t EL ARCHIVO MIDE %d BYTES" , ftell(FP) );
		printf("\n\t\t EL ARCHIVO TIENE %d REGISTROS" , ftell(FP)/sizeof(E) );
		fclose(FP) ;

        return 0 ;
}


