 /**
  * @file Pila_maxmin_Cola.cpp
  * @author Jesus Ruiz Castellano
  * @date 11 de Noviembre de 2016, 12:22
  * @brief Fichero implementacion de la ED Lineal Pila con maximo y minimo, representada
  *        mediante una Cola
  *  
  */

#include <iostream>
#include <cassert>
using namespace std;



template <class T>
elemento<T> Pila_maxmin<T> :: Tope () const {

	assert ( !datos.vacia() );

	Cola< elemento<T> > aux(datos); // Hacemos una copia para no cargarnos la cola privada

	int i = datos.num_elementos(); 

	while ( i > 1 ) {

		aux.quitar(); // Vamos quitando todos los elementos hasta que solo nos quede uno
		i--;
	}

	return aux.frente(); 
}



template <class T>
void Pila_maxmin<T> :: Quitar () {

	assert ( !datos.vacia() );

	Cola< elemento<T> > aux; 

	while ( Size() != 1 ) { 
		aux.poner (datos.frente()); // copiamos el elemento que va pasando a ser el frente, al frente del auxiliar
		datos.quitar();             // eliminamos ese elemento ya copiado, para poder avanzar                         
	}

	// Al salir del bucle ya solo quedara un elemento en la Pila, el perteneciente al frente de la cola
      	// Al llamar al operador de asignacion se machaca lo que hubiese en datos, antes de asignarle aux                    
	datos = aux;                      // Actualizamos el contenido de la Cola
}



template <class T>
void Pila_maxmin<T> :: Poner ( const T& v ) {

	elemento<T> aux;
	aux.d = v;

	if ( Vacia() ) {
		aux.minimo = v;
		aux.maximo = v;
	}
	else {

		elemento<T> anterior = Tope();
		aux.minimo = ( v < anterior.minimo ) ? v : anterior.minimo; 
		aux.maximo = ( v > anterior.maximo ) ? v : anterior.maximo;

	}
	
	datos.poner (aux); 
}