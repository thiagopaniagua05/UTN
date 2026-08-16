/*Se dispone del archivo PREMIOS con la información de la premiación de deportistas
en diversas categorías y la medalla obtenida (ORO, PLATA, BRONCE).
Este archivo está estructurado con registros que tienen la siguiente forma:
struct { char NOM[20]; char DEPORTE[20]; char MEDALLA[20]; };
Y el archivo REPRESENTACION con estructuras de la forma:
struct { char NOM[20]; char PAIS[20]; };
Crear un programa que permita ingresar un PAIS por línea de comandos y muestre cuántas medallas de ORO obtuvo
*/

#include <stdio.h>
#include <string.h>

struct MEDALLAS
{
    char nom[20];
    char deporte[20];
    char medalla[20];
};

struct REPRESENTACION
{
    char nom[20];
    char pais[20];
};

int main(int argc, char **argv[])
{
    char pais[20];
    int medallaOro = 0;

    FILE *fx = fopen("medallas", "rb");
    FILE *fy = fopen("representacion", "rb");

    // ingresa el pais a traves de linea de comando, struct 'REPRESENTACION',
    strcpy(pais, argv[1]);

    // valido que se haya abierto bien el archivo
    if (fx == NULL || fy == NULL)
    {
        printf("Error al cargar el archivo");
        return 1;
    }
    else
    {
        printf("Cargando archivo...");
    }

    // declaro las structs
    struct MEDALLAS x;
    struct REPRESENTACION y;

    // leo
    fread(&y, sizeof(y), 1, fy);

    while (!feof(fy))
    {
        if (strcmpi(y.pais, pais) == 0)
        {
            rewind(fx);
            fread(&x, sizeof(x), 1, fx);

            while (!feof(fx))
            {
                if (strcmpi(y.nom, x.nom) == 0)
                {
                    if (strcmpi(x.medalla, "ORO") == 0)
                    {
                        medallaOro++;
                    }
                }
                fread(&x, sizeof(x), 1, fx);
            }
        }
        fread(&y, sizeof(y), 1, fy);
    }
    printf("La cantidad de medallas de oro de su pais es: %d", medallaOro);
    fclose(fx);
    fclose(fy);
    return 0;
}
