 /**
  * @file VD.h
  * @author Jesus Ruiz Castellano
  * @date 10 de Noviembre de 2015, 19:46
  * @brief Fichero cabecera del TDA Vector Dinamico
  *  
  */

#ifndef _VD_H_
#define _VD_H_

#include <iostream>
using namespace std;

 /**
  * @brief T.D.A. Vector Dinamico
  *
  * @page esp Conjunto Especificacion 
  * Una instancia @e v del tipo de datos abstracto @c Vector Dinamico
  * es un array 1-dimensional de un determinado tamaño @e reservado, que
  * puede crecer y decrecer a petición del usuario. Lo podemos representar como
  *
  * {v[0],v[1],...,v[n-1]}
  *
  * donde  v[i] es el valor almacenado en la posición  i-esima del vector
  *
  * La eficiencia en espacio es @e O(n).
  *
  *
  * @section rep Conjunto Rep del TDA VD
  * T* datos
  * int n
  * int reservado
  * 
  *
  * @section fa Función de Abstracción
  *
  * Un objeto válido @e rep del TDA Vector Dinamico representa al vector de
  * tamaño @e n
  *
  * {v.datos[0],v.datos[1],...,v.datos[v.n-1]}
  *
  *
  * @section inv Invariante de la Representación
  *
  * Un objeto válido @e v del TDA Vector Dinamico debe cumplir :
  * - v.n >= 0
  * - v.n <= v.reservado
  * - v.datos apunta a una zona de memoria con capacidad para albergar
  *   n elementos de tipo de dato T 
  * 
  */

template <class T>

class VD {
private:

	T* datos;
	int n;       				// numero de datos almacenado
	int reservado;				// espacio asignado a datos

 /**
  * @brief Funcion para redimensionar el vector dinamico
  * @param int nuevotam es el tamaño nuevo que va a tener el vector
  * @post Los valores almacenados antes de la redimensión no se pierden
  *       (excepto los que se salen del nuevo rango de índices).
  *       El vector es modificado
  */
	void Resize ( int nuevotam );

 /**
  * @brief Funcion para Copiar un vector dinamico
  * @param const VD<T>& v es el vector al que se le va a hacer la copia 
  */
	void Copiar ( const VD<T> &v );

 /**
  * @brief Funcion para liberar la memoria dinamica 
  */
	void Liberar ();

public:

 /**
  * @brief Constructor por defecto
  * @param tam indica el número de casillas ocupadas 
  */
	VD ( int tam=10 );

 /**
  * @brief Constructor de copia
  * @param const VD<T>& original es el VD de tipo T que se va a copiar
  */
	VD ( const VD<T>& original ); 

 /**
  * @brief Destructor 
  */	
	~VD ();

 /**
  * @brief Operador de asignacion
  * @param const VD<T> &P es el VD de tipo T que se va a asignar en la nueva variable
  * @return La referencia al VD que se va a asignar
  * @pre this debe apuntar a zona de memoria diferente a donde apunte v
  */
	VD<T>& operator= ( const VD<T>& v );

 /**
  * @brief Número de componentes del vector
  * @return Devuelve el número de componentes que puede almacenar en este
  *         instante el vector
  */
	int Size () const { return n; }

 /**
  * @brief Operador de indexacion
  * @param int i es la posición del vector donde está el componente
  * @return La referencia al elemento. Por tanto, se puede usar para almacenar
  *         un valor en esa posición.
  */
	T& operator[] ( int i ) { return datos[i]; }

 /**
  * @brief Operador de indexacion
  * @param int i es la posición del vector donde está el componente
  * @return La referencia constante al elemento. Por tanto, no se puede modificar el elemento
  */
	const T& operator[] ( int i ) const { return datos[i]; }

 /**
  * @brief Agrega un elemento de tipo T al vector en la posicion pos
  * @param d es el elemento a insertar
  * @param pos es la posicion en la que se inserta el elemento
  * @post El vector es modificado
  */
	void Insertar ( const T& d, int pos );

 /**
  * @brief Elimina el elemento del vector dinámico en la posicion elegida
  * @param pos es la posicion en la que borramos el elemento
  * @param El vector es modificado
  */
	void Borrar ( int pos );

};
#include "VD.cpp"
#endif
