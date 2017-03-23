 /**
  * @file traductor.cpp
  * @author Jesus Ruiz Castellano
  * @date 1 de Diciembre de 2016, 13:10
  * @brief Fichero .cpp con la implementacion correspondiente al fichero 
  *	   	   traductor.h  
  *
  */


#include "frases.h"
#include "traductor.h"

using namespace std;


bool Traductor :: Esta ( string frase ) const {

	// Primero compruebo que hay algo en el conjunto y que la frase es valida
	if ( ConjF.size() > 0 && frase != "" ) {
	
		/*map<string,Frase> :: */const_iterator cit;
		// Recorro todo el conjunto de frases
		for ( cit = cbegin() ; cit != cend() ; ++cit ) 
			// Compruebo que la frase origen de la posicion i, mide lo mismo que la frase que buscamos
			if ( (*cit).second.GetOrigen().size() == frase.size() ) {
				// creo variables locales para no machacar las originales
				string ori;
				string nuevaFrase;
				// Recorro toda la cadena del campo origen, de la frase iesima
				for ( unsigned int j = 0 ; j < (*cit).second.GetOrigen().size() ; j++ ) {
					// Se copia la cadena pasando a mayuscula cada caracter del campo origen, de nuestro conjunto
					ori[j] = toupper ((*cit).second.GetOrigen()[j]); 
					nuevaFrase[j] = toupper (frase[j]); // Hago lo mismo con frase
				}

				// Devuelve true la primera vez que la encuentra, y termina
				if ( nuevaFrase == ori ) 
					return true;
			}
	}

	return false;
}


vector<string> Traductor :: GetTraducciones ( string frase ) const { 
   
	Frase buscada;
	bool encontrada = false;

	const_iterator cit;

	for ( cit = cbegin() ; cit != cend() && !encontrada ; ++cit ) {

		string ori = (*cit).second.GetOrigen();
		string orinueva = frase;

		if ( ori.size() == orinueva.size() ) {	
			/* Aunque ya sabemos que frase esta en el conjunto, puede estar pasada entera en minuscula o en mayuscula
			   por eso hay que pasarlo todo al mismo formato para poder detectarla dentro de nuestro conjunto */
			for ( unsigned int j = 0 ; j < (*cit).second.GetOrigen().size() ; j++ ) {
				ori[j] = toupper ( ori[j] );
				orinueva[j] = toupper ( orinueva[j] );
			}

			if ( ori == orinueva ) {
				buscada = (*cit).second;
				encontrada = true;
			}
		}
	}

	return buscada.GetDestino();
}


Traductor Traductor :: Contenga ( string subcadena ) const {

	Traductor nuevoConjF;
	const_iterator cit;

	for ( cit = cbegin() ; cit != cend() ; ++cit ) {
		// Nos dira la posicion en la que se encuentra la subcadena. Si chivato = -1, no se encuentra.
		int chivato = (*cit).second.GetOrigen().find(subcadena); 

		if ( chivato >= 0 ) 
			nuevoConjF.Insert((*cit).second);
	}

	return nuevoConjF;
}


void Traductor :: Insert ( Frase nueva ) {

	ConjF.insert(pair<string,Frase>(nueva.GetOrigen(),nueva));

	// Compruebo que el nuevo origen no existe ya
	Traductor :: iterator it;
	bool repetida = false;

	for ( it = begin() ; it != end() && !repetida ; ++it )
		if ( (*it).first == nueva.GetOrigen() ) 
			repetida = true;
		
	if ( repetida ) {
		Frase :: iterator fit; 
		// Recorro las traducciones de nueva para insertarlas en la frase anterior
		for ( fit = nueva.begin() ; fit != nueva.end() ; ++fit ) 
			ConjF[nueva.GetOrigen()].Push_Back((*fit)); // llama a Push_Back de Frase
	}  
}


istream& operator>> ( istream& flujo, Traductor& CF ) {

	while ( flujo && flujo.peek() != EOF ) {                     
 	
		Frase nuevaLinea;
		// Como ya lo tengo hecho en frase, el flujo se pasa a una frase
	 	flujo >> nuevaLinea;
	 	CF.Insert(nuevaLinea); // Y se inserta
	}

	return flujo;
}