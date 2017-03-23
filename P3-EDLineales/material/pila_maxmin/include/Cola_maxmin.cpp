 /**
  * @file Cola_maxmin.cpp
  * @author Jesus Ruiz Castellano
  * @date 14 de Noviembre de 2016, 14:03
  * @brief Fichero implementacion de la ED Lineal Cola con maximo y minimo, representada
  *        mediante una Pila
  *  
  */

#include <iostream>
#include <cassert>
#include "Pila_maxmin.h"
using namespace std;



template <class T>
elemento<T> Cola_maxmin<T> :: frente () {

	assert ( !datos.Vacia() ); //Si la pila está vacía, abortar

	Pila_maxmin<T> aux = datos;

	while ( aux.Size() > 1 ) 
		aux.Quitar(); // Quitamos todos los elementos hasta llegar al primero


	// Actualizamos el frente para que muestre el maximo y minimo de la cola
	elemento<T> Aux;
	elemento<T> anterior = datos.Tope();
	
	Aux.d = aux.Tope().d;
	Aux.minimo = ( aux.Tope().minimo < anterior.minimo ) ? aux.Tope().minimo : anterior.minimo; 
	Aux.maximo = ( aux.Tope().maximo > anterior.maximo ) ? aux.Tope().maximo : anterior.maximo;

	return Aux;  	   
}



template <class T>
const elemento<T> Cola_maxmin<T> :: frente () const {

	assert ( !datos.Vacia() ); //Si la pila está vacía, abortar
	
	Pila_maxmin<T> aux = datos;

	while ( aux.Size() > 1 ) 
		aux.Quitar(); // Quitamos todos los elementos hasta llegar al primero


	// Actualizamos el frente
	elemento<T> Aux;
	elemento<T> anterior = datos.Tope();
	Aux.d = aux.Tope().d;
	Aux.minimo = ( aux.Tope().minimo < anterior.minimo ) ? aux.Tope().minimo : anterior.minimo; 
	Aux.maximo = ( aux.Tope().maximo > anterior.maximo ) ? aux.Tope().maximo : anterior.maximo;

	return Aux;  	    
}



template <class T>
void Cola_maxmin<T> :: quitar () {

	assert( !datos.Vacia() ); //Si la pila está vacía, abortar

	Pila_maxmin<T> aux;
	Pila_maxmin<T> aux2;
	
	while ( datos.Size() > 1 ) {
		aux.Poner(datos.Tope().d);
		datos.Quitar();
	}

	// aux esta invertida, por eso se vuelca en aux2
	while ( !aux.Vacia() ) {
		aux2.Poner(aux.Tope().d);
		aux.Quitar();
	}
	
	datos = aux2;
}



