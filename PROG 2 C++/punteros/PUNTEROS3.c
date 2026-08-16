#include <stdio.h>
#include <conio.h>

struct ALFA {;

    int A ;
    float B ;
};

int main(){

    struct ALFA X ;
    struct ALFA * P ;

    P = &X ;
    X.A = 654 ;
    X.B = 25.45 ;

    printf ("\n\n\t\t %10d %10.2f", X.A, X.B);
    printf ("\n\n\t\t %10d %10.2f", P->A, P->B);

    P->A = 322154 ;
    P->B = 852.654 ;


    printf ("\n\n\n\n\t\t %10d %10.2f", X.A, X.B);
    printf ("\n\n\t\t %10d %10.2f", P->A, P->B);

   getch();
   return 0 ;
}



