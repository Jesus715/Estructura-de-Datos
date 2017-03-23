 /**
  * @file Lista.h
  * @author Jesus Ruiz Castellano
  * @date 10 de Noviembre de 2015, 21:30
  * @brief Fichero cabecera del TDA Lista  
  *  
  */

#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
using namespace std;

 
 /**
  * @brief Estructura para las Celdas
  *
  */
template <class T>
struct elemento {

	T d;
	T minimo;
	T maximo;
	elemento<T>* Sig;
};

 /**
  * @brief Sobrecarga del Operador<< 
  * @param os : flujo stream de salida
  * @param ele : dato de tipo elemento que pasa los valores
  * @return la referencia al ostream
  */
template <class T>
ostream& operator << ( ostream& os, const elemento<T> ele ) {
	os << "[" << ele.d << ", MAX : " << ele.maximo << ", MIN : " << ele.minimo << "]";
	return os;
}

template <class T>
class Lista;

template <class T>
class Posicion {
private:
	
	elemento<T>* punt;
	elemento<T>* primera;

public:

	Posicion() :punt(0), primera(0) {}

	bool operator== ( const Posicion<T>& op ) const {
		return punt == op.punt;
	}
	
	bool operator!= ( const Posicion<T>& op ) const {
		return punt != op.punt;
	}

	Posicion<T>& operator++ () {
		assert ( punt != 0 );
		punt = punt->Sig;	
		return *this;
	}

	Posicion<T>& operator-- () {
		if ( primera == punt )
			punt = 0;
		else {
			elemento<T>* q = primera;
			while ( q->Sig != punt )
				q = q->Sig;
			punt = q;
			return *this;
		}
	}

	T& operator* () {
		return punt->Sig->d;
	}

	friend class Lista<T>;
};

 /**
  * @brief T.D.A. Lista de celdas enlazadas con cabecera
  *
  * @page esp Conjunto Especificacion 
  * Una instancia @e v del tipo de datos abstracto @c Lista
  * es un tipo de dato lineal que contiene una secuencia de elementos 
  * {a0,a1,...,an-1}
  * Esta especialmente diseñada para realizar inserciones, borrados y consulta 
  * desde cualquier posicion.
  * El espacio requerido para el almacenamiento es O(n). Donde n es el
  * número de elementos de la Lista.
  *
  * @section rep Conjunto Rep del TDA Lista
  * Celda* Cab
  * 
  *
  * @section fa Función de Abstracción
  * Dado el objeto del tipo @e rep r, el objeto abstracto al que representa es:
  *
  * Lista = <br>{ r.Cab->Sig->d,</br>
  *    	    <br>r.Cab->Sig->Sig->d,</br>
  *         <br>...</br>
  *         <br>r.Cab->Sig-> ...(numero_elementos)... ->Sig->d }</br>
  */

template <class T>
class Lista {
private:

	elemento<T>* Cab;

 /**
  * @brief Copia los dmentos de una lista dada
  * @param const Lista<T>& L es la lista a la que se va a hacer la copia 
  */
	void Copiar ( const Lista<T>& L );

 /**
  * @brief Elimina todos los dmentos de la Lista 
  */
	void Borrar_todo ();

public:
	
 /**
  * @brief Constructor por defecto. Crea una lista vacía	    
  */
	Lista ();

 /**
  * @brief Constructor de copia.
  * @param const Lista<T>& L lista que se copia.
  */
	Lista ( const Lista<T>& L );

 /**
  * @brief Destructor 
  */
	~Lista ();

 /**
  * @brief Operador de asignacion
  * @param const Lista<T>& L es la Lista a la que se va a asignar
  * @return La referencia a la Lista asignada
  */
	Lista<T>& operator= ( const Lista<T>& L );

 /**
  * @brief Inserta un elemento en la lista.
  * @param Posicion<T> p es la posición detrás de la que se inserta. Debe ser
  *        una posición válida para el objeto lista receptor.
  * @param const T& v es el elemento que se inserta.
  */
	void Insertar ( Posicion<T> p, const T& v );

 /**
  * @brief Elimina un elemento de la lista.
  * @param Posicion<T> p es la posición del elemento que se borra. Debe ser una
  *        posición válida para el objeto lista receptor.
  *
  * @post Destruye el objeto que ocupa la posición 'p' en el objeto
  * 	    lista receptor. MODIFICA al objeto receptor.
  */
	void Borrar ( Posicion<T> p );

 /**
  * @brief Obtiene un elemento de la lista.
  * @param Posicion<T> p es la posición del elemento a obtener. Debe ser una
  *        posición válida para el objeto lista receptor.
  *        p != End().
  * @return El elemento situado en la posición p de la lista.
  * @post Dado que se devuelve una referencia al objeto, éste puede ser
  *       modificado desde fuera de la lista.
  */
	T Get ( Posicion<T> p ) const;

 /**
  * @brief Inserta un elemento en la lista.
  * @param Posicion<T> p es la posición detrás de la que se va a modificar. 
  *        Debe ser una posición válida para el objeto lista receptor.
  * @param const T& v es el elemento que se inserta.
  * @post El elemento siguiente a la posicion p pasa a tener en el campo @e d
  *       el valor @e v. MODIFICA AL OBJETO DE LA POSICION SIGUIENTE A p
  */
	void Set ( Posicion<T> p, const T& v );

 /**
  * @brief Indica el tamaño de la Lista
  * @return El valor de la variable @e contador, que es el numero de elementos
  */
	int Size () const;

 /**
  * @brief Indica la posicion de la Cabecera de la Lista
  * @return La posicion de la cabecera, que es la primera posicion de la Lista
  */
	Posicion<T> Begin () const;

 /**
  * @brief Indica la posicion del final de la Lista
  * @return La posicion del ultimo elemento de la lista
  */
	Posicion<T> End () const;
};
#include "Lista.cpp"
#endif
