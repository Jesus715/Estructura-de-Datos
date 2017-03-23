#ifndef __REFRANES_HASH_H
#define __REFRANES_HASH_H


#include <fstream>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <functional>

using namespace std;


/** 
 * @file refranes_hash.h 
 * @author Jesus Ruiz Castellano y Gregorio Vidoy Fajardo
 * @date 24/01/2017
 * @brief Fichero cabecera del TDA Refranes, implementado
 *        a partir de una tabla hash
 */



class Refranes {

/**
 * @page T.D.A. Refranes_Hash
 *
 * @section esRefranesHash Conjunto Especificacion
 * Una instancia \e a del tipo de dato abstracto Refranes es una
 * colección de frases tipicas de un idioma, dispuestas de forma 
 * ordenada en las que no hay refranes repetidos. 
 *
 * Ejemplo : 
 *
 *    dar el beneficio de la duda 
 *    de higos a brevas
 *    de perdidos al rio
 *    de tal palo tal astilla
 * 
 * Para poder usar el tipo de dato Refranes_Hash se debe incluir el fichero 
 * <tt>\#include refranes_hash.h</tt>
 * 
 * NOTA: Su representacion esta basada en una Tabla Hash
 *
 * @section invRefranesHash Invariante de la representación
 *
 *  - No hay refranes repetidos
 *  - Los refranes estan en minuscula
 *  - No habra 2 refranes con el mismo valor my_hash como clave
 *
 *
 *
 * @section faRefranesHash Función de abstracción
 *  
 *  Siendo @e rep un objeto valido del TDA Refranes, se representa como :
 *
 *  <br>fa(rep) = rep.ab[rep.refran[rep.my_hash0]]     </br>
 *          <br>  rep.ab[rep.refran[rep.my_hash1]]     </br>
 *          <br>            ...                        </br>
 *          <br>  rep.ab[rep.refran[rep.my_hashN]]     </br>
 */

private:

    class my_hash {                   /**< Tipo de dato para obtener el valor hash */
      private:
        unsigned int len;
      public:
        my_hash (int l=3) { len= l; }
        void set_len (int l);
        size_t operator()( const string& clave )const;
    };   

    unordered_set<string,my_hash> ab; /**< Tabla hash para almacenar los refranes */
    int n_ref;                        /**< Numero de refranes */
    int caracteres_totales;           /**< Numero de caracteres totales */ 
    
    
public:
  /**
   * @brief Constructor por defecto. Inicia len_prefijo a 3
   */
  Refranes();      
  
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
    
    
    
/************************ ITERADORES ************************/

    /**
     * @page T.D.A. iterator
     *
     * @section esRefranesIterator Conjunto Especificacion
     * Una instancia \e a del tipo de dato abstracto iterator es un
     * puntero para poder movernos a traves de los refranes 
     */
    class iterator{
    private:

        unordered_set<string,my_hash>::iterator it;
      
    public:

        string operator *();
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
    class const_iterator{
    private:

        unordered_set<string,my_hash> :: const_iterator it;

    public:
        const_iterator() {};
        const_iterator(const iterator  &i);
        string operator *()const;
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