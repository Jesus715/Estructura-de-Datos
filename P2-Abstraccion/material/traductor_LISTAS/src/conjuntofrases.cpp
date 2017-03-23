 /**
  * @file conjuntofrases.cpp
  * @author Jesus Ruiz Castellano
  * @date 25 de Octubre de 2016, 21:18
  * @brief Fichero .cpp con la implementacion correspondiente al fichero 
  *	   	   conjuntofrases.h  
  *
  */


#include "frases.h"
#include "conjuntofrases.h"

using namespace std;



bool ConjuntoFrases :: Invariante () const {

	if ( ocupadas <= TAM-1 && ocupadas >= 2 ) {
		for ( int i = 0 ; i < ocupadas ; i++ ) {
			for ( int j = i+1 ; j < ocupadas ; j++ ) {
				if (!( ConjF[i] == ConjF[j] )) // Hay que ponerlo de esta manera porque el operador != no esta implementado
					return true;
			}
		}
	}
	return false;
}


void ConjuntoFrases :: MoreSize () {

	int nuevoTAM = TAM*2; 			  // Ampliamos el tamanio del vector al doble
	Frase* CF = new Frase [nuevoTAM]; // creamos un nuevo vector de frases con el nuevo tamanio

	for ( int i = 0 ; i < ocupadas ; i++ )
		CF[i] = ConjF[i];             // Hacemos una copia del ConjF antiguo, en el nuevo CF ampliado
	
	delete [] ConjF;                  // Liberamos memoria del vector 
	ConjF = CF;	                      // Hacemos que nuestro puntero privado apunte a donde apunta el nuevo creado
	TAM = nuevoTAM;		              // Asignamos el nuevo valor para el tamanio
} 
		
	
ConjuntoFrases :: ConjuntoFrases () {
	
	TAM = 50;
	ocupadas = 0;
	ConjF = new Frase [TAM];
}


ConjuntoFrases :: ConjuntoFrases ( const ConjuntoFrases& CF ) {
	
	if ( Invariante() ) {

		TAM = CF.TAM;
		ocupadas = CF.ocupadas;

		ConjF = new Frase [TAM];

		for ( int i = 0 ; i < ocupadas ; i++ )
			ConjF[i] = CF.ConjF[i];
	}
}


ConjuntoFrases& ConjuntoFrases :: operator= ( const ConjuntoFrases& CF ) {


	if ( this != &CF && Invariante() ) {

		if  ( ConjF != 0 ) 
			delete [] ConjF;
		
		TAM = CF.TAM;
		ocupadas = CF.ocupadas;
		ConjF = new Frase [TAM];
		
		for ( int i = 0 ; i < ocupadas ; i++ ) 
			ConjF[i] = CF.ConjF[i];
	}

	return *this;
}


ConjuntoFrases :: ~ConjuntoFrases () {

	if ( ocupadas != 0 ) {
		delete [] ConjF;
		ocupadas = 0;
	}
}


Frase& ConjuntoFrases :: operator[] ( int i ) { 

	assert ( i >= 0 && i < ocupadas );
	return ConjF[i]; 
}


const Frase& ConjuntoFrases :: operator[] ( int i ) const { 

	assert ( i >= 0 && i < ocupadas );
	return ConjF[i]; 
}


istream& operator>> ( istream& flujo, ConjuntoFrases& CF ) {

	bool esta = false;

	while ( flujo ) {                     
 	
 		Frase nuevaLinea;
 		flujo >> nuevaLinea;

  		if ( !CF.Esta(nuevaLinea.GetOrigen()) ) {
		 		
 			CF.ConjF[CF.ocupadas] = nuevaLinea;
 			CF.ocupadas++;
		}

		else {

			string aux;
			CF.ConjF[CF.ocupadas].AniadeTraduccion();
		}

		if ( CF.Size() == CF.TAM-1 )     
			CF.MoreSize();
		
	}
	return flujo;
}


ostream& operator<< ( ostream& flujo, ConjuntoFrases& CF ) {

	if ( CF.ocupadas == 0 )
		flujo << " ATENCION : CONJUNTO VACIO " << endl;

	else {
		for ( int i = 0 ; i < CF.Size() ; i++ )  // Recorremos todo el vector de frases ocupadas 
			flujo << CF.ConjF[i];            	 // Y se introducen en la variable flujo la iesima justo debajo de la ultima frase introducida
	}

	return flujo;
}


bool ConjuntoFrases :: Esta ( string frase ) const {

	// primero compruebo que hay algo en el conjunto y que la frase es valida
	if ( ocupadas > 0 && frase != "" ) 
		// Recorro todo el conjunto de frases
		for ( int i = 0 ; i < ocupadas ; i++ ) 
			// Compruebo que la frase origen de la posicion i, mide lo mismo que la frase que buscamos
			if ( ConjF[i].GetOrigen().size() == frase.size() ) {
				// creo variables locales para no machacar las originales
				string ori, nuevaFrase;
				// Recorro toda la cadena del campo origen de la frase iesima
				for ( unsigned int j = 0 ; j < ConjF[i].GetOrigen().size() ; j++ ) {
					// Se copia la cadena pasando a mayuscula cada caracter del campo origen, de nuestro conjunto
					ori[j] = toupper (ConjF[i].GetOrigen()[j]); 
					nuevaFrase[j] = toupper (frase[j]); // Hago lo mismo con frase
				}

				if ( ori == nuevaFrase ) 
					return true;
			}
		

	return false;
}


Frase ConjuntoFrases :: GetTraducciones ( string frase ) const { 

	string nueva;
	Frase buscada;

	for ( int i = 0 ; i < ocupadas ; i++ ) {

		string ori;

		/* Aunque ya sabemos que frase esta en el conjunto, puede estar pasada entera en minuscula o en mayuscula
		   por eso hay que pasarlo todo al mismo formato para poder detectarla dentro de nuestro conjunto */
		for ( unsigned int j = 0 ; j < ConjF[i].GetOrigen().size() ; j++ ) {
			ori[j] = toupper ( ConjF[i].GetOrigen()[j] );
			nueva[j] = toupper (frase[j]);
		}

		if ( ori == nueva )
			buscada = ConjF[i];
	}

	return buscada;
}


ConjuntoFrases ConjuntoFrases :: Contenga ( string subcadena ) const {

	ConjuntoFrases nuevoConjF;
	
	for ( int i = 0 ; i < ocupadas ; i++ ) {
		// Nos dira la posicion en la que se encuentra la subcadena. Si chivato = -1, no se encuentra.
		int chivato = ConjF[i].GetOrigen().find(subcadena); 

		if ( chivato >= 0 ) {
			// Esto puedo hacerlo, porque estoy dentro de la clase
			nuevoConjF[nuevoConjF.ocupadas] = ConjF[i];
			nuevoConjF.ocupadas++;
		}
	}

	return nuevoConjF;
}