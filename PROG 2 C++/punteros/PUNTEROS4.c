#include <stdio.h>
#include <conio.h>

struct ALUMNO {;

    char NOM[20] ;
    char SEX ;
    int NOTA ;
};

#define N 6

int main(){

    struct ALUMNO VEC[N], AUX ;
    struct ALUMNO * P ;
    int I, J ;


    for ( P = VEC , I = 0 ; I < N ; I++ ) {

        fflush(stdin);
        printf("\n\n\t\t NOMBRE : ");
        gets( (P+I)->NOM );
        printf("\n\t\t SEXO : ");
        (P+I)->SEX = getchar();
        printf("\n\t\t NOTA : ");
        scanf("%d", &((P+I)->NOTA) );
    }

    for ( P = VEC ; P < VEC+N ; P++ )
        printf("\n\n\t\t %-12s %8c %10d ", P->NOM, P->SEX, P->NOTA);

    printf("\n\n\n");
    P = VEC ;
     for ( P = VEC , I = 0 ; I < N ; I++ ) {
         printf("\n\n\t\t %-12s %8c %10d ", (P+I)->NOM, (P+I)->SEX, (P+I)->NOTA );

    }
    getchar();
     printf("\n\n\n");
    P = VEC ;
    for ( I = 0; I < N-1 ; I++ ){
        for( J = 0 ; J < N-I-1 ; J++ ){
            if ( (P+J)->NOTA  <  (P+J+1)->NOTA ) {
                    AUX = *(P + J) ;
                    *(P+J) = *(P + J +1) ;
                    *(P+J+1) = AUX ;
            }}
    }
    printf("\n\n\n VECTOR ORDENADO");
    P = VEC ;
     for (  I = 0 ; I < N ; I++ ) {
         printf("\n\n\t\t %-12s %8c %10d ", (P+I)->NOM, (P+I)->SEX, (P+I)->NOTA );

    }
    //printf ("\n\n\t\t %10d %10.2f", X.A, X.B);

   getch();
   return 0 ;
}



