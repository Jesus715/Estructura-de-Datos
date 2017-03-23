 /**
  * @file ArbolGeneral.cpp
  * @author Jesus Ruiz Castellano y Gregorio Vidoy Fajardo
  * @date 14 de Diciembre de 2016, 14:52
  * @brief Fichero implementacion del TDA ArbolGeneral
  *  
  */


#include <cassert>
#include <iostream>
using namespace std;



/**************************** METODOS PRIVADOS ******************************/

template <class T>
void ArbolGeneral<T> :: Destruir ( nodo* n ) {
	
  	if ( n != 0 ) {
    	Destruir (n->izqda);
		Destruir (n->drcha);
		delete n;
    	n = 0;
	}
}



template <class T>
void ArbolGeneral<T> :: Copiar ( nodo*& dest, nodo* orig ) {
	
	if ( orig == 0 )
		dest = 0;

	else {
    	if ( laraiz == 0 ) {
	      AsignaRaiz( orig->etiqueta ); 
	      Copiar(dest->izqda,orig->izqda); // Copiamos hijo izquierda
	      Copiar(dest->drcha,orig->drcha); // Copiamos hermano derecha
    	}
    	else {
			dest = new nodo;
		  	dest->etiqueta = orig->etiqueta;
	      	dest->padre = 0;
	      	dest->izqda = 0;
	      	dest->drcha = 0;
		  	Copiar( dest->izqda, orig->izqda );
		  	Copiar ( dest->drcha, orig->drcha );
    	}
		if ( dest->izqda != 0 ) {
			dest->izqda->padre = dest;
      		nodo *aux = dest->izqda;
			
			while ( aux->drcha != 0 ) {
				aux->drcha->padre = dest;
        		aux = aux->drcha;
      		}
		}
	}
}



template <class T>
int ArbolGeneral<T> :: Contar ( const nodo* n ) const {
	
	if ( n == 0 )
		return 0;
	else
		// Contamos el nodo padre + sus hijos de ambas ramas recursivamente
		return ( 1 + Contar( n->izqda ) + Contar( n->drcha ) );
}



template <class T>
bool ArbolGeneral<T> :: SonIguales ( const nodo* n1, const nodo* n2 ) const {

	if (n1 == 0 && n2 == 0)                      
		return true;                             

	else if (n1 == 0 || n2 == 0)                  
		return false;                            

	else if (n1->etiqueta != n2->etiqueta)      
		return false;                           

	else if (!SonIguales(n1->izqda, n2->izqda)) 
		return false;                            

	else if (!SonIguales(n1->drcha, n2->drcha)) 
		return false;                            

	else                                       
		return true;                             

}



template <class T>
void ArbolGeneral<T> :: Escribe_arbol ( std::ostream& out, nodo* nod ) const {

	if (nod == 0)                                //Si el nodo es nulo
		out << "x ";                           //escribimos 'x'

	else {                                       //Si el nodo no es nulo
		out << "n " << nod->etiqueta;   //escribimos su etiqueta
    
    	nodo *aux = nod->izqda;
    	while (aux != 0) {
			Escribe_arbol(out,aux);
			aux = aux->drcha;
    	}
    	out << "x ";
	}
}



template <class T>
void ArbolGeneral<T> :: Lee_arbol ( std::istream& in, nodo*& nod ) {
	
	char c;
	                     	   
	//Lectura de un carácter
	if (in.get(c))
		switch (c) {
			case 'x':
				nod = 0;
				break;

			case 'n':
				T et;
				in >> et;
				nod = new nodo;
				nod->etiqueta = et;
				nod->izqda = 0;
				nod->drcha = 0;
				nod->padre = 0;
		
				Lee_arbol(in, nod->izqda);
				Lee_arbol(in, nod->drcha);

				if ( nod->izqda != 0 ) {
					nod->izqda->padre = nod;
					nodo* aux = nod->izqda;

					while ( aux->drcha != 0 ) {
						aux->drcha->padre = nod;
						aux = aux->drcha;
					}
				}
				break;
		}
}			




/**************************** METODOS PUBLICOS ******************************/



template <class T>
ArbolGeneral<T> :: ArbolGeneral() {
	laraiz = 0; // se crea un arbol vacio
}



template <class T>
ArbolGeneral<T> :: ArbolGeneral ( const T& e ) {

	laraiz = 0;
  	AsignaRaiz(e);	
}



template <class T>
ArbolGeneral<T> :: ArbolGeneral ( const ArbolGeneral<T> &v ) {

  	laraiz = 0;
	Copiar (laraiz, v.laraiz);
}



template <class T>
ArbolGeneral<T> :: ~ArbolGeneral() {
	Destruir (laraiz);
}



template <class T>
ArbolGeneral<T>& ArbolGeneral<T> :: operator = ( const ArbolGeneral<T> &v ) {

	if ( this != &v ) {
		Destruir (laraiz);
		Copiar (laraiz, v.laraiz);
	}		
	
	return *this;
}



template <class T>
void ArbolGeneral<T> :: AsignaRaiz ( const T& e ) {

	Destruir(laraiz);        //Destruye el árbol actual
	laraiz = new nodo;    	 //Reservamos el nodo raíz
	laraiz->padre = 0;       //No tiene padre,
	laraiz->izqda = 0;       //ni hijo izquierda,
	laraiz->drcha = 0;       //ni hijo derecha.
	laraiz->etiqueta = e;    //Damos valor a la etiqueta de la raíz	
}



template <class T>
typename ArbolGeneral<T> :: Nodo ArbolGeneral<T> :: Raiz() const {
	return laraiz;
}



template <class T>
typename ArbolGeneral<T> :: Nodo ArbolGeneral<T> :: HijoMasIzquierda ( const Nodo n ) const {
	return n->izqda;
}



template <class T>
typename ArbolGeneral<T> :: Nodo ArbolGeneral<T> :: HermanoDerecha ( const Nodo n ) const {
	return n->drcha;
}



template <class T>
typename ArbolGeneral<T> :: Nodo ArbolGeneral<T> :: Padre ( const Nodo n ) const {
	return n->padre;
}
 
   

template <class T>
T& ArbolGeneral<T> :: Etiqueta ( const Nodo n ) {
	return n->etiqueta;
}



template <class T>
const T& ArbolGeneral<T> :: Etiqueta ( const Nodo n ) const {
	return n->etiqueta;
}



template <class T>
void ArbolGeneral<T> :: Asignar_subarbol ( const ArbolGeneral<T> &orig, const Nodo nod ) {

	Destruir (laraiz);         
  	Copiar (laraiz,nod);       
	if (laraiz != 0) {       	   
		laraiz->padre = 0;
    	Destruir(laraiz->drcha);
  	}
}



template <class T>
void ArbolGeneral<T> :: Podar_hijoMasIzquierda ( Nodo n, ArbolGeneral<T> &dest ) {

	if ( n->izqda != 0 ) {
		dest.laraiz = n->izqda;
    	n->izqda = n->izqda->drcha;
    	dest.laraiz->drcha = 0;
    	dest.laraiz->padre = 0;
	}
}



template <class T>
void ArbolGeneral<T> :: Podar_hermanoDerecha ( Nodo n, ArbolGeneral<T> &dest ) {

	if ( n->drcha != 0 ) {
	    dest.laraiz = n->drcha;
	    n->drcha = n->drcha->drcha;
	    dest.laraiz->drcha = 0;
	    dest.laraiz->padre = 0;
  	}
}



template <class T>
void ArbolGeneral<T> :: Insertar_hijoMasIzquierda ( Nodo n, ArbolGeneral<T> &rama ) {

	if ( !rama.Empty() ) { // Comprobamos que la rama tiene nodos
	    Nodo aux; // Nodo auxiliar
	    aux = n->izqda; // Guardamos el nodo hijo actual
	    Copiar(n->izqda,rama.Raiz()); // Copiamos el contenido y creamos un nuevo hijo más izquierda
	    n->izqda->drcha = aux; // El hermano derecho del hijo izquierda actual es el hijo izquierdo anterior
	    n->izqda->padre = n; // Le asignamos su padre
	    rama.Clear(); // Borramos los nodos de la rama.
  	}
}



template <class T>
void ArbolGeneral<T> :: Insertar_hermanoDerecha ( Nodo n, ArbolGeneral<T> &rama ) {

	assert ( n->padre != 0 ); // Para que la raiz no tenga hermano a la derecha
  	if ( !rama.Empty() ){ // Comprobamos que la rama no esté vacia
	    Nodo aux; // Nodo auxiliar
	    aux = n->drcha; // aux contiene el hermano a la derecha actual
	    Copiar ( n->drcha ,rama.Raiz() ); // Copiamos la rama en el hermano a la derecha de n
	    n->drcha->drcha = aux; // Su hermano a la derecha de nodo apunta al hermano a la derecha anterior
	    n->drcha->padre = n->padre; // Su padre es el mismo que el de sus hermanos
	    rama.Clear();
  	}
}



template <class T>
void ArbolGeneral<T> :: Clear () {

	Destruir ( laraiz );
	laraiz = 0;
} 
  
  

template <class T>
int ArbolGeneral<T> :: Size () const {
	return Contar ( laraiz );
}



template <class T>
bool ArbolGeneral<T> :: Empty () const {
	return laraiz == 0;
}



template <class T>
bool ArbolGeneral<T> :: operator == ( const ArbolGeneral<T> &v ) const {
	return SonIguales ( laraiz, v.laraiz );
}
    


template <class T>
bool ArbolGeneral<T> :: operator != ( const ArbolGeneral<T> &v ) const {
	return !(SonIguales(laraiz, v.laraiz));
}



template <class T> 
std :: istream& operator>> ( std :: istream &in, ArbolGeneral<T> &v ) {
	
	if ( !v.Empty() ) 
		v.Clear();

	v.Lee_arbol ( in, v.laraiz );
	return in;
}



template <class T>
std :: ostream& operator<< ( std :: ostream &out, const ArbolGeneral<T> &v ) {

	if ( v.laraiz != 0 )
		v.Escribe_arbol ( out, v.laraiz );

	return out;
}



/***************************** ITERADOR PREORDEN ******************************/



template <class T>
ArbolGeneral<T> :: iter_preorden :: iter_preorden () {

	it = 0;
	raiz = 0;
	level = -1;
}



template <class T>
T& ArbolGeneral<T> :: iter_preorden :: operator* () {
	return (*it).etiqueta;
}



template <class T>
int ArbolGeneral<T> :: iter_preorden :: getLevel () const {
	return level;
}



 /**
  * @brief Compara si es un nodo hoja
  * @return true si no tiene hijo a la izquierda. False en caso contrario
  */
template <class T>
bool ArbolGeneral<T> :: iter_preorden :: Hoja () const {
	return it->izqda == 0;
}


 /**
  * @brief Compara dos iteradores
  * @param i: iterador con el  que se compara
  * @return true si los dos iteradores son iguales (la raiz y el nodo son iguales). False en caso contrario
  */
template <class T>
bool ArbolGeneral<T> :: iter_preorden :: operator == (const iter_preorden &i) const {
	return i.raiz == raiz && i.it == it && i.level == level;
}

	 	    
 /**
  * @brief Compara dos iteradores
  * @param i: iterador con el  que se compara
  * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
  */
template <class T>
bool ArbolGeneral<T> :: iter_preorden :: operator != (const iter_preorden &i) const {
  	return i.raiz != raiz || i.it != it || i.level != level;
}



/*************************** CONST ITER PREORDEN  *****************************/



template <class T>
ArbolGeneral<T> :: const_iter_preorden :: const_iter_preorden () {

	it = 0;
	raiz = 0;
	level = -1;
}



template <class T>
const T& ArbolGeneral<T> :: const_iter_preorden :: operator* () {
	return (*it).etiqueta;
}



template <class T>
int ArbolGeneral<T> :: const_iter_preorden :: getLevel () const {
	return level;
}



template <class T>
bool ArbolGeneral<T> :: const_iter_preorden :: Hoja () const {
  	return it->izqda == 0;
}



template <class T>
bool ArbolGeneral<T> :: const_iter_preorden :: operator == (const const_iter_preorden &i) const {
	return i.raiz == raiz && i.it == it && i.level == level;
}
	 	    
 /**
  * @brief Compara dos iteradores
  * @param i: iterador con el con que se comparación
  * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
  */
template <class T>
bool ArbolGeneral<T> :: const_iter_preorden :: operator != (const const_iter_preorden &i) const {
	return i.raiz != raiz || i.it != it || i.level != level;
}












