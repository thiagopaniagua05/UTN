/* PARCIAL TEMA A */

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
	char * BUSQUEDA = argv[1];
	int CONT_ORO;
	
	if ((FPPRE = fopen("PREMIOS", "rb")) == NULL){
		printf("\n\n ERROR APERTURA ARCHIVO PREMIOS");
		exit(1);
	}
	
	if ((FPREPRE = fopen("REPRESENTACION", "rb")) == NULL){
		printf("\n\n ERROR APERTURA ARCHIVO REPRESENTACION");
		exit(1);
	}	
	
	CONT_ORO = 0;
	fread(&Y, sizeof(Y), 1, FPREPRE);
	while(!feof(FPREPRE)){
		if (!strcmpi(BUSQUEDA, Y.PAIS)){
			rewind(FPPRE);
			fread(&X, sizeof(X), 1, FPPRE);
			while(!feof(FPPRE)){
				if (!strcmpi(X.NOMBRE, Y.NOMBRE) && !strcmpi(X.MEDALLA, "ORO")){
					CONT_ORO++;
				}
			fread(&X, sizeof(X),1 , FPPRE);	
			}
		}
		fread(&Y, sizeof(Y), 1, FPREPRE);	
	}
	
	printf("EL PAIS %s OBTUVO %d MEDALLAS DE ORO", BUSQUEDA, CONT_ORO);
	
	fclose(FPPRE);
	fclose(FPREPRE);
	
	return 0;
}
