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


bool ConjuntoFrases :: Esta ( string frase ) const {

	// Primero compruebo que hay algo en el conjunto y que la frase es valida
	if ( ConjF.size() > 0 && frase != "" ) {
	
		// Recorro todo el conjunto de frases
		for ( unsigned int i = 0 ; i < ConjF.size() ; i++ ) 
			// Compruebo que la frase origen de la posicion i, mide lo mismo que la frase que buscamos
			if ( ConjF[i].GetOrigen().size() == frase.size() ) {
				// creo variables locales para no machacar las originales
				string ori;
				string nuevaFrase;
				// Recorro toda la cadena del campo origen, de la frase iesima
				for ( unsigned int j = 0 ; j < ConjF[i].GetOrigen().size() ; j++ ) {
					// Se copia la cadena pasando a mayuscula cada caracter del campo origen, de nuestro conjunto
					ori[j] = toupper (ConjF[i].GetOrigen()[j]); 
					nuevaFrase[j] = toupper (frase[j]); // Hago lo mismo con frase
				}

				// Devuelve true la primera vez que la encuentra, y termina
				if ( nuevaFrase == ori ) 
					return true;
			}
	}

	return false;
}


Frase ConjuntoFrases :: GetTraducciones ( string frase ) const { 

	Frase buscada;
	bool encontrada = false;


	for ( unsigned int i = 0 ; i < ConjF.size() && !encontrada ; i++ ) {

		string ori = ConjF[i].GetOrigen();
		string orinueva = frase;

		if ( ori.size() == orinueva.size() ) {	
			/* Aunque ya sabemos que frase esta en el conjunto, puede estar pasada entera en minuscula o en mayuscula
			   por eso hay que pasarlo todo al mismo formato para poder detectarla dentro de nuestro conjunto */
			for ( unsigned int j = 0 ; j < ConjF[i].GetOrigen().size() ; j++ ) {
				ori[j] = toupper ( ori[j] );
				orinueva[j] = toupper ( orinueva[j] );
			}

			if ( ori == orinueva ) {
				buscada = ConjF[i];
				encontrada = true;
			}
		}
	}

	return buscada;
}


ConjuntoFrases ConjuntoFrases :: Contenga ( string subcadena ) const {

	ConjuntoFrases nuevoConjF;
	
	for ( unsigned int i = 0 ; i < ConjF.size() ; i++ ) {
		// Nos dira la posicion en la que se encuentra la subcadena. Si chivato = -1, no se encuentra.
		int chivato = ConjF[i].GetOrigen().find(subcadena); 

		if ( chivato >= 0 ) 
			nuevoConjF.Push_Back(ConjF[i]);
	}

	return nuevoConjF;
}


void ConjuntoFrases :: Push_Back ( Frase nueva ) {

	if ( ConjF.size() == 0 ) 
		ConjF.push_back(nueva);
	
	else {
		// Comparo el nuevo origen, con el ultimo en haber sido insertado por el final
		if ( nueva.GetOrigen() != ConjF[ConjF.size()-1].GetOrigen() )  
			ConjF.push_back(nueva);
		else 
			// Recorro las traducciones de nueva para insertarlas en la frase anterior
			for ( unsigned int i = 0 ; i < nueva.GetDestino().size() ; i++ ) 
				ConjF[ConjF.size()-1].Push_Back(nueva.GetDestino()[i]); // llama a Push_Back de Frase
	}
}


istream& operator>> ( istream& flujo, ConjuntoFrases& CF ) {

	while ( flujo && flujo.peek() != EOF ) {                     
 	
		Frase nuevaLinea;
		// Como ya lo tengo hecho en frase, el flujo se pasa a una frase
	 	flujo >> nuevaLinea;
	 	CF.Push_Back(nuevaLinea); // Y se inserta
	}

	return flujo;
}


ostream& operator<< ( ostream& flujo, ConjuntoFrases& CF ) {

	if ( CF.Size() == 0 )
		flujo << " ATENCION : CONJUNTO VACIO " << endl;

	else 
		for ( int i = 0 ; i < CF.Size() ; i++ )  // Recorremos todo el vector de frases ocupadas 
			flujo << CF.ConjF[i];            	 // Y se introducen en la variable flujo la iesima justo debajo de la ultima frase introducida
	
	return flujo;
}