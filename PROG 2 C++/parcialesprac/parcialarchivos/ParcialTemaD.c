/*
PARCIAL  D, SE DISPONE DEL ARCHIVO PREMIOS CON LA INFORMACION DE LA PREMIACION DE DEPORTISTAS EN DIVERSAS CATEGORIAS Y LA MEDALLA OBTENIDA (ORO, PLATA, BRONCE)
ESTE ARCHIVO ESTRUCTURADO CON REGISTROS QUE TIENEN LA SIGUIENTE FORMA: STRUCT {char NOM[20], char DEPORTE[20], char MEDALLA[20]};
Y EL ARCHIVO REPRESENTACION CON ESTRUCTURAS DE LA FORMA: STRUCT {char NOM[20]], char PAIS [20]}; CREAR UN PROGRAMA QUE PERMITA INGURESAR UN DEPORTE POR LINEA DE COMANDOS Y MUESTRE QUE PAISES LOGRARON LAS MEDALLAS DE ORO, PLATA Y BRONCE EN ESE DEPORTE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PREMIO {
	char NOMBRE[20];
	char DEPORTE[20];
	char MEDALLA [20];
};

struct REPRE {
	char NOMBRE[20];
	char PAIS[20];
};

int main (int arc, char ** argv){

	FILE * FPPRE, *FPREPRE;
	struct PREMIO X;
	struct REPRE Y;
	char DEPORTE[20];
	strcpy(DEPORTE, argv[1]);


	if ((FPPRE = fopen("PREMIOS", "rb")) == NULL){
		printf("\n\n ERROR APERTURA ARCHIVO PREMIOS");
		exit(1);
	}

	if ((FPREPRE = fopen("REPRESENTACION", "rb")) == NULL){
		printf("\n\n ERROR APERTURA ARCHIVO REPRESENTACION");
		exit(1);
	}

	fread(&X, sizeof(X), 1, FPPRE);
	while(!feof(FPPRE)){
		if (!strcmpi(DEPORTE, X.DEPORTE)){
			rewind(FPREPRE);
			fread(&Y, sizeof(Y), 1, FPREPRE);
			while(!feof(FPREPRE)){
				if (!strcmpi(X.NOMBRE, Y.NOMBRE) ){
					printf("PAIS: %s MEDALLA: %s", Y.PAIS, X.MEDALLA);
				}
			fread(&Y, sizeof(Y), 1, FPREPRE);
			}

		}
		fread(&X, sizeof(X), 1, FPPRE);
	}


	fclose(FPPRE);
	fclose(FPREPRE);

	return 0;
}
