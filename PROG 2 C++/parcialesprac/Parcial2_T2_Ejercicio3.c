/*Dado un texto de máximo 1000 caracteres.
Realizar solamente la función que calcule el porcentaje de letras vocales contenidas en el texto*/

#include <stdio.h>
#include <string.h>
#define N 1001

void VOCALES(char[]);

main(){
    char texto[N];
    printf("\nIngrese texto (Max 1000 Caracteres): ");
    fflush(stdin);
    gets(texto);
    VOCALES(texto);
}

void VOCALES(char T[]){
    int i, cont=0;
	T = strupr (T);
	for (i=0 ; i<=strlen(T) ; i++)
		if(T[i] == 'A' || T[i] == 'E' ||T[i] == 'I' ||T[i] == 'O' ||T[i] == 'U')
		cont++;
printf("\nEl porcentaje de vocales es %.2f %%", (float) cont * 100 / strlen(T));
}




