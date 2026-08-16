			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  CONSTRUCTORES PARAMETRIZADOS CON DEFAULT */

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
		void CARGAR ( char *) ; 
		void MIRAR();	
};


ALFA::ALFA(int A)
{
		MAX = A ;
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
		  
		  
		getch();
		return 0 ;
}


