#ifndef __REFRANES__H
#define __REFRANES__H


#include "ArbolGeneral.h"
#include <fstream>
#include <iostream>

using namespace std;


/** 
 * @file refranes.h 
 * @author Jesus Ruiz Castellano y Gregorio Vidoy Fajardo
 * @date 19/01/2017
 * @brief Fichero cabecera del TDA Refranes, implementado
 *        a partir de un Arbol General
 */
 

class Refranes {

/**
 * @page T.D.A. Refranes
 *
 * @section esRefranes Conjunto Especificacion
 * Una instancia \e a del tipo de dato abstracto Refranes es una
 * colección de frases tipicas de un idioma, dispuestas de forma 
 * ordenada en las que no hay refranes repetidos. 
 *
 * Ejemplo : 
 *
 *    <br>dar el beneficio de la duda</br> 
 *    <br>de higos a brevas</br>
 *    <br>de perdidos al rio</br>
 *    <br>de tal palo tal astilla</br>
 * 
 * Para poder usar el tipo de dato Refranes se debe incluir el fichero 
 * <tt>\#include refranes.h</tt>
 * 
 * NOTA: Su representacion esta basada en un Arbol General
 *
 * @section invRefranes Invariante de la representación
 *
 * 	- No hay refranes repetidos
 *	- Los refranes estan en minuscula
 *	- El arbol tiene tantos niveles como indique len_prefijo+1
 *	- Si len_prefijo = 1 => El primer nivel, el nivel 0, se correspondera a la primera letra de cada refran
 *	- Si 2 refranes empiezan por la misma letra, el resto de ambos refranes ira a un nodo 
 *	  independiente, ambos hermanos, e hijos del nodo con etiqueta igual a la primera letra
 *	- Para len_prefijo > 1, se procedera igual, asignando la siguiente letra del refran a los nodos
 *	  del siguiente nivel. Y asi sucesivamente.
 *	- Los nodos hoja contendran las cadenas correspondientes al resto del refran, tras haberle quitado
 *	  las letras que indique len_prefijo.
 *
 *
 * @section faRefranes Función de abstracción
 *	
 *  Siendo ArbolGeneral<T> :: iter_preorden it un iterador en preorden sobre el arbol 
 *	y siendo @e rep un objeto valido del TDA Refranes, se representa :
 *
 *	br>fa(rep) = rep.ab.            </br>
 *
 */

private:

  ArbolGeneral<string> ab;  /**< Arbol para almacenar los refranes */
  int len_prefijo;          /**< Longitud del prefijo para construir el arbol */
  int n_ref;                /**< Numero de refranes */
  int caracteres_totales;   /**< Numero de caracteres totales */
       
public:
  /**
   * @brief Constructor por defecto. Inicia len_prefijo a 3
   */
  Refranes();
  
  /**
   * @brief Constructor por parametros. Inicia len_prefijo al valor lpre 
   */
  Refranes (int lpre);
  
  /** 
   * @brief devuelve el prefijo de refranes
   * @return el prefijo
   */
  int getLen_prefijo () const { return len_prefijo; }       
  
  /** 
   * @brief devuelve el numero de refranes alamacenados
   * @return el numero de refranes
   */
  int size () const;
  
  /** 
   * @brief Inserta un refran en el conjunto 
   * @param refran : refran a insertar
   * @note el numero de refranes se incrementa en uno mas
   */
  void Insertar(const string &refran);
  
  /** 
   * @brief Borra un refrán en el conjunto 
   * @param refran : refran a borrar
   * @note el numero de refranes se decrementa en uno mas
   */
  void BorrarRefran(const string &refran);
  
  // Declaracion adelantada de los iteradores de refranes
  class iterator; 
  class const_iterator; 
  
  /** 
   * @brief Devuelve si un refran esta en el conjunto. Si esta devuelve un iterador a el
   * @param refran : refran a buscar
   * @return una pareja que contiene si el refran esta y en caso afirmativo un iterador a el
   */
  pair<bool, iterator> Esta(const string &refran);
  
  /** 
   * @brief Elimina todos los refranes 
   */
  void clear();
  
  /** 
   * @brief Lectura/Escritura de un conjunto de refranes
   */
  friend istream & operator>>(istream &is, Refranes &R);
  friend ostream & operator<<(ostream &os, Refranes &R);

  /**
   * @brief Cuenta el numero total de los caracteres en todos los refranes
   * @return Devuelve el numero total de caracteres en todos los refranes
   */  
  int Caracteres_Refranes();
  
  /**
   * @brief Cuenta el numero de caracteres usados
   * @return Devuelve el numero de caracteres usados
   * @note que no tiene que conincide con el numero de caracteres de todos los refranes almancenados
   */
  int Caracteres_Almacenados();
  
  /**
   * @brief Numero de nodos necesarios para la configuración
   * @return El numero de nodos del arbol
   */
  int Numero_Nodos() const;

  

/************************ ITERADORES ************************/

  	/**
  	 * @page T.D.A. iterator
	 *
	 * @section esRefranesIterator Conjunto Especificacion
	 * Una instancia \e a del tipo de dato abstracto iterator es un
	 * puntero para poder movernos a traves de los refranes 
  	 */
	class iterator {
  	private:

	    ArbolGeneral<string> :: iter_preorden it;
	    string cad;

  	public:
	    iterator() { cad="";}
	    string & operator *();
	    bool operator==(const iterator &i)const;
	    bool operator!=(const iterator &i)const;   
	    iterator &operator ++();
	    
	    friend class Refranes;
	    friend class const_iterator;
  	};
  
  	/**
  	 * @page T.D.A. const_iterator
	 *
	 * @section esRefranesConstIterator Conjunto Especificacion
	 * Una instancia \e a del tipo de dato abstracto const_iterator es un
	 * puntero constante para poder movernos a traves de los refranes,
	 * sin poder modificar su contenido 
  	 */
	class const_iterator {
  	private:
  
	    ArbolGeneral<string> :: const_iter_preorden it;
	    string cad;
	  
  	public:
	    const_iterator();
	    const_iterator(const iterator  &i);
	    string & operator *();
	    bool operator==(const const_iterator &i)const;
	    bool operator!=(const const_iterator &i)const;    
	    const_iterator &operator ++();

	   	friend class Refranes;
  	};	  
 


/*************** BEGIN y END *************/
    
	/**
	 * @brief Se posiciona en el primer refran
	 * @return Un iterador al primer refran 
	 */
	iterator begin();
	/**
	 * @brief Se posiciona al final, en un objeto no valido
	 * @return Un iterador a una posicion siguiente al ultimo refran
	 */
	iterator end();
	  
	/**
	 * @brief Se posiciona en el primer refran
	 * @return Un iterador constante al primer refran 
	 */      
	const_iterator Cbegin() const;
	/**
	 * @brief Se posiciona al final, en un objeto no valido
	 * @return Un iterador constante a una posicion siguiente al ultimo refran
	 */       
	const_iterator Cend() const;
};
#endif