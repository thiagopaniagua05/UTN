#include <stdio.h>
#include <string.h>

struct premio {
    char nom[20];
    char deporte[20];
    char medalla[20];
}

struct representacion {
    char nom[20];
    char pais[20];
}

int main(int argc, char** argv){

    //declaro lugar en memoria para almacenar el deporte
    char deporte[20];
    //paso a 'deporte' lo que hay en el argv[1]
    strcpy(deporte, argv[1]);

    //abrir archivos
    FILE * fx = fpopen("PREMIOS", "rb");
    FILE * fy = fpopen("REPRESENTACION", "rb");

    if (fx == NULL || fy == NULL){
        printf("Falla en el archivo");
        return 1;
    } else {
        printf("Cargando archivo...");
    }
    //fin apertura archivos

    //estructura para leer los archivos
    struct premio x;
    struct representacion y;
    fread(&x, sizeof(x), 1, fx);
    
    //algoritmo: leo una linea de fx para despues leer todo fy
    while(!feof(fx)) {
        if (strcmpi(deporte, x.deporte)==0){
        rewind(fy);  
        fread(&y, sizeof(y), 1, fy);

    while(!feof(fy)) {  
        if(strcmpi(x.nom, y.nom)==0){
            printf("Pais: %s - Medalla: %s", y.pais, x.medalla);
        }
            fread(&y, sizeof(y), 1, fy);
        }
            fread(&x, sizeof(x), 1, fx);
        }
    }
    
    //cerrar archivos
    fclose(fx);
    fclose(fy);

    return 0;
    }
