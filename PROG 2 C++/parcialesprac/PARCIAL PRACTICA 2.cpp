#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



struct PRODUCTOS
{
    int CODIGO;
    char DESCRIPCION [50];
    float CANTIDAD;
    float VALOR;
    char ZONA;
    char ULTIMA_REC[10];
};

void CARGA (struct PRODUCTOS [], int );
int VALIDACION(char);
void MUESTRA (struct PRODUCTOS [], int );
void ULTIMARECEPCION (struct PRODUCTOS [], int );
void ZONAG(struct PRODUCTOS [], int );


int main() {
    struct PRODUCTOS V[3];
    CARGA(V,3);
    MUESTRA(V,3);
    ULTIMARECEPCION(V,3);
    ZONAG(V,3);

    return 0;
}

void CARGA (struct PRODUCTOS V[], int N)
{
    int I;
    for(I = 0 ; I < N ; I++)
    {
        printf("\nCodigo del producto (correlativo) : %d", I + 1);
        V[I].CODIGO = I + 1;
        printf("\nDescripcion del producto : ");
        fflush(stdin);
        gets(V[I].DESCRIPCION);
        printf("\nIngrese la cantidad en KG : ");
        scanf("%f", &V[I].CANTIDAD);
        printf("\nIngrese el valor por KG: ");
        scanf("%f", &V[I].VALOR);
        do{
        printf("\nIngrese la zona ( C-(CABA) G-(GBA) O-(OTRO) : ");
        scanf(" %c", &V[I].ZONA);
        V[I].ZONA = toupper(V[I].ZONA);
        }while(!VALIDACION(V[I].ZONA));
        printf("\nIngrese el dia de la ultima recepcion: ");
        fflush(stdin);
        gets(V[I].ULTIMA_REC);
    }
}

int VALIDACION(char ZONA)
{
    if (ZONA == 'C' || ZONA == 'G' || ZONA == 'O') {
        return 1;
    }else
    {
        printf("Zona inválida. Debe ser 'C', 'G' o 'O'.\n");
    return 0;
    }
}

void MUESTRA (struct PRODUCTOS V[], int N)
{
    int I;
    for(I = 0 ; I < N ; I++)
    {
         printf("\n\nProducto %d", V[I].CODIGO);
         printf("\n\t%s", V[I].DESCRIPCION);
         printf("\n\t%.2f KG", V[I].CANTIDAD);
         printf("\n\t$%.2f ", V[I].VALOR);
         printf("\n\t%c", V[I].ZONA);
         printf("\n\t%s", V[I].ULTIMA_REC);
    }
}

void ULTIMARECEPCION (struct PRODUCTOS V[], int N)
{   printf("\n\nProductos que ultima recepcion fue el dia VIERNES:");
    int I;
    char VIERNES [8];
    strcpy(VIERNES,"VIERNES");
    for(I = 0 ; I < N ; I++)
    {
        if(strcmpi(VIERNES,V[I].ULTIMA_REC) == 0)
        {
            printf("\n\n\tCodigo: %d", V[I].CODIGO);
            printf("\n\tDscripcion: %s", V[I].DESCRIPCION);
        }
    }
}
void ZONAG(struct PRODUCTOS V[], int N)
{   printf("\n\n Cantidad de existencia minima por KG de la zona G");
    int I;
    float CANTIDAD_MINIMA = 0;

    for (I = 0 ; I < N ; I++)
    {
        if(V[I].ZONA == 'G' && CANTIDAD_MINIMA == 0)
            CANTIDAD_MINIMA = V[I].CANTIDAD;

        if(V[I].ZONA == 'G' && CANTIDAD_MINIMA > V[I].CANTIDAD)
                CANTIDAD_MINIMA = V[I].CANTIDAD;
    }
    for (I = 0  ; I < N ; I++)
    {
        if(CANTIDAD_MINIMA == V[I].CANTIDAD && V[I].ZONA == 'G')
        {
            printf("\n\t Codigo: %d", V[I].CODIGO);
            printf("\n\t Valor por KG: %.2f", V[I].VALOR);
        }
    }
}
