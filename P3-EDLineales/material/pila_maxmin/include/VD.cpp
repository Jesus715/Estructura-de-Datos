 /**
  * @file VD.cpp
  * @author Jesus Ruiz Castellano
  * @date 10 de Noviembre de 2015, 20:04
  * @brief Fichero implementacion del TDA Vector Dinamico
  *  
  */

#include <iostream>
using namespace std;

 /**
  * @brief Funcion para redimensionar el vector dinamico
  * @param int nuevotam es el tamaño nuevo que va a tener el vector
  * @post Los valores almacenados antes de la redimensión no se pierden
  *       (excepto los que se salen del nuevo rango de índices).
  *       El vector es modificado
  */
template <class T>
void VD<T> :: Resize ( int nuevotam ) {

	T* aux = new T [nuevotam];
	int minimo = ( n < nuevotam ) ? n:nuevotam;
	
	for ( int i = 0 ; i < minimo ; i++ )
		aux[i] = datos[i];

	reservado = nuevotam;
	n = minimo;
	delete [] datos;
	datos = aux;
}

 /**
  * @brief Funcion para Copiar un vector dinamico
  * @param const VD<T>& v es el vector al que se le va a hacer la copia 
  */
template <class T>
void VD<T> :: Copiar ( const VD<T>& v ) {

	reservado = v.reservado;
	n = v.n;

	datos = new T [reservado];
	for ( int i = 0 ; i < n ; i++ )
		datos[i] = v.datos[i];
}

 /**
  * @brief Funcion para liberar la memoria dinamica 
  */
template <class T>
void VD<T> :: Liberar () {

	delete [] datos;
}

 /**
  * @brief Constructor por defecto
  * @param tam indica el número de casillas ocupadas 
  */
template <class T>
VD<T> :: VD ( int tam ) {

	reservado = tam;
	datos = new T [reservado];
	n = 0;
}

 /**
  * @brief Constructor de copia
  * @param const VD<T>& original es el VD de tipo T que se va a copiar
  */
template <class T>
VD<T> :: VD ( const VD<T>& original ) {

	Copiar (original);
}

 /**
  * @brief Destructor 
  */
template <class T>
VD<T> :: ~VD () {

	Liberar();
}

 /**
  * @brief Operador de asignacion
  * @param const VD<T> &P es el VD de tipo T que se va a asignar en la nueva variable
  * @return La referencia al VD que se va a asignar
  * @pre this debe apuntar a zona de memoria diferente a donde apunte v
  */
template <class T>
VD<T>& VD<T> :: operator= ( const VD<T>& v ) {

	if ( this != &v ) {
		Liberar();
		Copiar (v);
	}

	return *this;
}

 /**
  * @brief Agrega un elemento de tipo T al vector en la posicion pos
  * @param d es el elemento a insertar
  * @param pos es la posicion en la que se inserta el elemento
  * @param El vector es modificado
  */
template <class T>
void VD<T> :: Insertar ( const T& d, int pos ) {

	if ( n >= (reservado/2) )
		Resize (2*reservado);

	for ( int i = n ; i > pos ; i-- )
		datos[i] = datos[i-1];

	datos[pos] = d;
	n++;
}

 /**
  * @brief Elimina el elemento del vector dinámico en la posicion elegida
  * @param pos es la posicion en la que borramos el elemento
  * @param El vector es modificado
  */
template <class T>
void VD<T> :: Borrar ( int pos ) {

	for ( int i = pos ; i < n-1 ; i++ )
		datos[i] = datos[i+1];

	n--;

	if ( n < (reservado/4) )
		Resize (reservado/2);
}
