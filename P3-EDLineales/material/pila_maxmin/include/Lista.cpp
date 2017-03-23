 /**
  * @file Lista.cpp
  * @author Jesus Ruiz Castellano
  * @date 10 de Noviembre de 2015, 22:07
  * @brief Fichero implementacion del TDA Lista
  *  
  */

#include <cassert>
using namespace std;


 /**
  * @brief Copia los elementos de una lista dada
  * @param const Lista<T>& L es la lista a la que se va a hacer la copia 
  */
template <class T>
void Lista<T> :: Copiar ( const Lista<T>& L ) {
	
	if ( L.Cab->Sig == 0 ) {
		Cab = new elemento<T>;
		Cab->Sig = 0;
	}
	else {
		Cab = new elemento<T>;
		elemento<T>* p = Cab;
		elemento<T>* q = L.Cab;

		while ( q->Sig != 0 ) {

			p->Sig = new elemento<T>;
			p->Sig->d = q->Sig->d;
			p = p->Sig;
			q = q->Sig;
		}
		p->Sig = 0;
	}
}


 /**
  * @brief Elimina todos los elementos de la Lista 
  */
template <class T>
void Lista<T> :: Borrar_todo () {

	while ( Cab->Sig != 0 ) {
		elemento<T>* aux = Cab->Sig;
		Cab->Sig = Cab->Sig->Sig;
		delete aux;
	}
	delete Cab;
}


 /**
  * @brief Constructor por defecto. Crea una lista vacía	    
  */
template <class T>
Lista<T> :: Lista () {
	Cab = new elemento<T>;
	Cab->Sig = 0;
}


 /**
  * @brief Constructor de copia.
  * @param const Lista<T>& L lista que se copia.
  */
template <class T>
Lista<T> :: Lista ( const Lista<T>& L ) {

	Copiar (L);
}


 /**
  * @brief Destructor 
  */
template <class T>
Lista<T> :: ~Lista () {
	
	Borrar_todo ();
}


 /**
  * @brief Operador de asignacion
  * @param const Lista<T>& L es la Lista a la que se va a asignar
  * @return La referencia a la Lista asignada
  */
template <class T>
Lista<T>& Lista<T> :: operator= ( const Lista<T>& L ) {

	if ( this != &L ) {
		Borrar_todo ();
		Copiar (L);
	}
	return *this;
}


 /**
  * @brief Inserta un elemento en la lista.
  * @param Posicion<T> p es la posición detrás de la que se inserta. Debe ser
  *        una posición válida para el objeto lista receptor.
  * @param const T& v es el elemento que se inserta.
  */
template <class T>
void Lista<T> :: Insertar ( Posicion<T> p, const T& v ) {

	elemento<T>* aux = p.punt->Sig;
	p.punt->Sig = new elemento<T>;
	p.punt->Sig->d = v;
	p.punt->Sig->Sig = aux;
}


 /**
  * @brief Elimina un elemento de la lista.
  * @param Posicion<T> p es la posición del elemento que se borra. Debe ser una
  *        posición válida para el objeto lista receptor.
  *
  * @post Destruye el objeto que ocupa la posición 'p' en el objeto
  * 	    lista receptor. MODIFICA al objeto receptor.
  */
template <class T>
void Lista<T> :: Borrar ( Posicion<T> p ) {

	assert ( p.punt->Sig != 0 );
	elemento<T>* aux = p.punt->Sig;
	p.punt->Sig = p.punt->Sig->Sig;
	delete aux;
}


 /**
  * @brief Obtiene un elemento de la lista.
  * @param Posicion<T> p es la posición del elemento a obtener. Debe ser una
  *        posición válida para el objeto lista receptor.
  *        p != End().
  * @return El elemento situado en la posición p de la lista.
  * @post Dado que se devuelve una referencia al objeto, éste puede ser
  *       modificado desde fuera de la lista.
  */
template <class T>
T Lista<T> :: Get ( Posicion<T> p ) const {
	
	assert ( p != End() );
	return p.punt->Sig->d;
}


 /**
  * @brief Inserta un elemento en la lista.
  * @param Posicion<T> p es la posición detrás de la que se va a modificar. 
  *        Debe ser una posición válida para el objeto lista receptor.
  * @param const T& v es el elemento que se inserta.
  * @post El elemento siguiente a la posicion p pasa a tener en el campo @e d
  *       el valor @e v. MODIFICA AL OBJETO DE LA POSICION SIGUIENTE A p
  */
template <class T>
void Lista<T> :: Set ( Posicion<T> p, const T& v ) {

	p.punt->Sig->d = v;
}


 /**
  * @brief Indica el tamaño de la Lista
  * @return El valor de la variable @e contador, que es el numero de elementos
  */
template <class T>
int Lista<T> :: Size () const {
	
	int contador = 0;

	for ( elemento<T>* aux = Cab->Sig ; aux != 0 ; aux = aux->Sig )
		contador++;

	return contador;
}


 /**
  * @brief Indica la posicion de la Cabecera de la Lista
  * @return La posicion de la cabecera, que es la primera posicion de la Lista
  */
template <class T>
Posicion<T> Lista<T> :: Begin () const {

	Posicion<T> p;
	p.punt = Cab;
	p.primera = Cab;
	return p;
}


 /**
  * @brief Indica la posicion del final de la Lista
  * @return La posicion del ultimo elemento de la lista
  */
template <class T>
Posicion<T> Lista<T> :: End () const {

	Posicion<T> p;
	elemento<T>* aux = Cab;
	while ( aux->Sig != 0 )
		aux = aux->Sig;
	p.punt = aux;
	p.primera = Cab;
	return p;
}


