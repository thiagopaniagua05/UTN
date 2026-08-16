#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct EMPLEADOS {
    char NOMBRE [50];
    float SUELDO;
    int ANTIGUEDAD;

};

void CARGA(struct EMPLEADOS[], int);
void MUESTRA(struct EMPLEADOS[], int);
void MANTIGUEDAD(struct EMPLEADOS[], int);
void SMPROMEDIO(struct EMPLEADOS[], int);

int main() {

    struct EMPLEADOS V[5];
    CARGA(V, 5);
    MUESTRA(V, 5);
    MANTIGUEDAD(V,5);
    SMPROMEDIO(V,5);
    return 0;
}

void CARGA(struct EMPLEADOS V[], int N )
{
    int I;
    for(I = 0 ; I < N ; I ++)
    {
        printf("\nIngresa el nombre y apellido del empleado: ");
        fflush(stdin);
        gets(V[I].NOMBRE);
        printf("\nIngresa el sueldo del empleado: ");
        scanf("%f", &V[I].SUELDO);
        printf("\nIngrese la antiguedad del empleado: ");
        scanf("%d", &V[I].ANTIGUEDAD);
    }
}

void MUESTRA (struct EMPLEADOS V[], int N)
{   printf("\nEMPLEADOS");
    int I;
    for (I = 0 ; I < N ; I ++)
        printf("\nEmpleado: %s, Sueldo: %.2f, Antiguedad: %d", V[I].NOMBRE, V[I].SUELDO, V[I].ANTIGUEDAD);

}

void MANTIGUEDAD (struct EMPLEADOS V[], int N)
{
    int I, MAX_ANT = 0;
    for(I = 0 ; I < N ; I++)
    {
        if(V[I].ANTIGUEDAD > MAX_ANT)
            MAX_ANT = V[I].ANTIGUEDAD;

    }
    printf("\n\nEmpleados con mas antiguedad: ");
    for (I = 0 ; I < N ; I ++)
    {
        if(V[I].ANTIGUEDAD == MAX_ANT)
            printf("\n Empleado: %s, Sueldo: %.2f, Antiguedad: %d", V[I].NOMBRE, V[I].SUELDO, V[I].ANTIGUEDAD);
    }
}

void SMPROMEDIO(struct EMPLEADOS V[], int N) {
    int I;
    float ACUM = 0, PSUELDO;

    for (I = 0; I < N; I++) {
        ACUM += V[I].SUELDO;
    }

    PSUELDO = ACUM / N;
    printf("\n\nSueldo promedio: %.2f", PSUELDO);
    printf("\nEmpleados con sueldo igual o superior al promedio:\n");

    for (I = 0; I < N; I++) {
        if (V[I].SUELDO >= PSUELDO) {
            printf("Empleado: %s, Sueldo: %.2f, Antigüedad: %d\n",
                    V[I].NOMBRE, V[I].SUELDO, V[I].ANTIGUEDAD);
        }
    }
}
