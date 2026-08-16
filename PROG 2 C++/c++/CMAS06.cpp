			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  DE CONSTRUCTORES Y DESTRUCTORES */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std ;

class ALFA {
	private :
		int MAX ;
		char NOMBRE[20];
	public :
		ALFA(int = 8);     /*  CONSTRUCTOR  */
		~ALFA() ;			/*  DESTRUCTOR  */
		void CARGAR ( char *) ; 
		void MIRAR();	
};


ALFA::ALFA(int A)
{
		MAX = A ;
		printf("\n\n\n    CONSTRUCTOR EN ACCION \n\n") ;
		getch();
}

ALFA::~ALFA()
{
		printf("\n\n\n    DESTRUCTOR EN ACCION \n\n") ;
		getch();
}

void ALFA::CARGAR ( char * S )
{
		strcpy ( NOMBRE , S ) ;
}


void ALFA::MIRAR()
{
		int I ;
		for ( I = 0 ; I < MAX ; I++ )
				cout << "\n\n\t\t" << NOMBRE ;
		getchar();
}

int main( )
{
		ALFA X(25) ;
			
		X.CARGAR ("ALGUIEN") ;
		X.MIRAR () ;
		  
		cout  << "\n\n\n\n";
		getch();
		 
		ALFA Y ;
			
		Y.CARGAR ("CUALQUIERA") ;
		Y.MIRAR () ;  
		  
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}


