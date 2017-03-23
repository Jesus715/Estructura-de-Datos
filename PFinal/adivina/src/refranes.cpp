#include "refranes.h"
#include <vector>

/** 
 * @file refranes.cpp 
 * @author Jesus Ruiz Castellano y Gregorio Vidoy Fajardo
 * @date 19/01/2017
 * @brief Fichero implementacion del TDA Refranes, implementado
 *        a partir de un Arbol General
 */



//-------------------------------------------------//
//--------------FUNCIONES PUBLICAS-----------------//
//-------------------------------------------------//

Refranes :: Refranes () {
    ab.AsignaRaiz("");      
    len_prefijo = 3;
    n_ref = 0;
    caracteres_totales = 0;
}


Refranes :: Refranes ( int lpre ) {
    ab.AsignaRaiz(""); 
    len_prefijo = lpre;
    n_ref = 0;
    caracteres_totales = 0;
}


int Refranes :: size () const {
    return n_ref;
}


void Refranes :: Insertar ( const string &refran ) {
    
    ArbolGeneral<string> :: iter_preorden itAPUNTA = ab.begin();
    ArbolGeneral<string> :: iter_preorden itUltimoEncontrado = ab.begin();
    bool bandera = false;

    if ( ab.Size() == 1 ) { // Primer caso, arbol vacio
        for ( int i = 0 ; i < len_prefijo ; i++ ) {
            string refranAUX;
            refranAUX.push_back(refran[i]);
            ArbolGeneral<string> aux(refranAUX);
            ab.Insertar_hijoMasIzquierda(itAPUNTA.GetNodo(),aux);
            ++itAPUNTA;
        }

        string resto = refran.substr(len_prefijo,refran.size()-1);
        ArbolGeneral<string> aux2(resto);
        ab.Insertar_hijoMasIzquierda(itAPUNTA.GetNodo(),aux2);
        
        n_ref++;    
    }

    else if ( !Esta(refran).first ){ // arbol con algo

        bandera = true;

        for ( int i = 0 ; i < len_prefijo ; i++ ) {
            bool encontrado = false; // bandera para salir del while
            string refranAUX;
            refranAUX.push_back(refran[i]);

            ArbolGeneral<string> :: iter_preorden itRECORRE = ab.begin();
            
            //Buscamos si esta
            while ( itRECORRE != ab.end() && !encontrado ) {
                //Si es nivel 0 y no esta no compruebo padres
                if ( (*itRECORRE) == refranAUX && itRECORRE.getLevel() == i && i == 0  ){
                    encontrado = true;
                    itUltimoEncontrado = itRECORRE;
                    itAPUNTA = itUltimoEncontrado; 
                }
                //Si no es el nivel 0 compruebo todos los padres no justo el antetior sino todos hasta el nivel 0
                else if( (*itRECORRE) == refranAUX && itRECORRE.getLevel() == i && i != 0  ){
                    string letrasAnt;
                    letrasAnt = refran.substr(0,i);
                    string letrasPadre;
                    
                    //Cojo las letras de los padres
                    ArbolGeneral<string> :: Nodo Naux = itRECORRE.GetNodo();

                    while ( Naux->padre != 0 ) {
                        string auxiliar = Naux->padre->etiqueta;
                        letrasPadre.insert(0, auxiliar);
                        Naux = Naux->padre;
                    }
                    if( letrasPadre == letrasAnt ){
                        encontrado = true;
                        itUltimoEncontrado = itRECORRE;
                        itAPUNTA = itUltimoEncontrado; 
                    }
                }

                ++itRECORRE;
            }
            
            //Si no lo encuentra lo inserto apartir del ultimo encontrado
            if ( !encontrado ) {
                ArbolGeneral<string> aux(refranAUX);
                ab.Insertar_hijoMasIzquierda(itUltimoEncontrado.GetNodo(),aux);
                ++itUltimoEncontrado;
                itAPUNTA = itUltimoEncontrado; 
            }
        }
        //Pego lo que me quede despues del prefijo
        if ( bandera == true ) {
            string resto = refran.substr(len_prefijo,refran.size()-1);
            ArbolGeneral<string> aux2(resto);
            ab.Insertar_hijoMasIzquierda(itAPUNTA.GetNodo(),aux2);
        }
        n_ref++;
    }
}


void Refranes :: BorrarRefran (const string &refran) {
    
    iterator LocalizaRefran = begin(); 
    iterator FIN = end();
    bool SITUADO = false;
    
    // Localizamos el refran
    while ( LocalizaRefran != FIN && !SITUADO ) {
        
        if ( (*LocalizaRefran) == refran )
            SITUADO = true;
        else
            ++LocalizaRefran;
    }
    // Al salir, LocalizaRefran apunta a la hoja donde termina refran. Empezamos a subir

    if ( SITUADO ) { 
    
        ArbolGeneral<string> :: Nodo actual = LocalizaRefran.it.GetNodo();
        ArbolGeneral<string> AlaHoguera; // aqui se almacena la morralla
        bool FIN = false;
                    
        while ( actual->padre != 0 && !FIN ) {
            
            string MiFinEtiqueta = actual->etiqueta;                            
            actual = actual->padre; // me posiciono en mi padre
            
            if ( actual->izqda->etiqueta == MiFinEtiqueta ) { // soy yo el hijo izquierda
                ab.Podar_hijoMasIzquierda(actual, AlaHoguera);

                if ( actual->izqda != 0 ) { // hemos terminado, lo que queda forma parte de otro refran
                    FIN = true;
                }
            } 
            else { // soy alguno de los hermanos derecha, tengo que encontrarme
                
                ArbolGeneral<string> :: Nodo hijoDerecho = actual->izqda; // es el "begin" del while
                bool finDERECHA = false;
                
                while ( !finDERECHA ) {
                                        
                    if ( hijoDerecho->drcha->etiqueta == MiFinEtiqueta ) {
                        ab.Podar_hermanoDerecha(hijoDerecho, AlaHoguera);
                        finDERECHA = true;
                    }

                    hijoDerecho = hijoDerecho->drcha;
                }
                
                FIN = true;
            }
        }
        n_ref--;
    }
}


pair<bool, Refranes :: iterator> Refranes :: Esta (const string &refran) {
    
    size_t sizeT = -1;
    bool bandera = false;
    iterator it = end();
    pair<bool, iterator> aux(bandera,it);
    

    for ( it = begin() ; it != end() && !bandera ; ++it )
        if ( (*it).find(refran) != sizeT ) {
            bandera = true;
            aux.first = bandera;
            aux.second = it;
        }

    return aux; 
}


void Refranes :: clear () {
    ab.Clear();
    len_prefijo = 0;
    n_ref = 0;
    caracteres_totales = 0;
}



//----------------------------------------------------//
//-------------- FUNCIONES AMIGAS --------------------//
//----------------------------------------------------//

istream& operator>> (istream &is, Refranes &R) {

    while (!is.eof()) {
        string refran;
        getline(is,refran);
        
        // Elimina posibles caracteres ' ' al final de los refranes
        if (refran[refran.size()-1] == ' ')
            refran.pop_back();
        
        R.Insertar(refran);
    }

    return is;
}


ostream& operator<< (ostream &os, Refranes &R) {
        
   Refranes :: iterator itrr; 
   itrr = R.begin();

    while ( itrr != R.end() ) {
        os << (*itrr) << endl;
        ++itrr;
    }

    return os;
}

int Refranes :: Caracteres_Refranes () {
    
    int contador = 0;

    iterator it = begin();
    iterator itF = end(); 

    while ( it != itF ) { 
        contador += (*it).size(); 
        ++it;
    }
    
    return contador;
}


int Refranes :: Caracteres_Almacenados () {
    
    int contador = 0;

    ArbolGeneral<string> :: iter_preorden it = ab.begin();
    ArbolGeneral<string> :: iter_preorden itF = ab.end(); 

    while ( it != itF ) { 
        contador += (*it).size(); 
        ++it;
    }
    contador--; // para no contar la raiz
    
    return contador; 
}

int Refranes :: Numero_Nodos () const {
    return ab.Size(); 
}



//-------------------------------------------------//
//------------- FUNCIONES iterador ----------------//
//-------------------------------------------------//       

string& Refranes :: iterator :: operator* () {

    string mi_cadena = "";
    
    if ( it.GetNodo() != 0 ) {

        ArbolGeneral<string> :: Nodo aux = it.GetNodo();
        
        while ( aux->padre != 0 ) {
            string auxiliar = aux->etiqueta;
            mi_cadena.insert(0, auxiliar);
            aux = aux->padre;
        }

        cad = mi_cadena;
    }
    return cad;
}

bool Refranes :: iterator :: operator== ( const iterator &i ) const {
    return it == i.it && cad == i.cad;        
}

bool Refranes :: iterator :: operator!= ( const iterator &i ) const {
    return it != i.it; 
}

Refranes :: iterator & Refranes :: iterator :: operator ++ () {

    if ( it.GetNodo() != 0 ) {
        
        ++it;

        if ( it.GetNodo() != 0 ) 
            while ( !it.Hoja() ) 
                ++it;      
    }

    return *this;
}



//-------------------------------------------------//
//------------- FUNCIONES const_iterator ----------//
//-------------------------------------------------//   

Refranes :: const_iterator :: const_iterator () {
    cad = "";
}

Refranes :: const_iterator :: const_iterator (const iterator  &i) {
    it = i.it;
    cad = i.cad;
}

string & Refranes :: const_iterator :: operator *() {
    return cad;
}

bool Refranes :: const_iterator :: operator== (const const_iterator &i) const {
    return it == i.it && cad == i.cad; 
}

bool Refranes :: const_iterator :: operator!= ( const const_iterator &i ) const {
    return it != i.it; 
}

Refranes :: const_iterator & Refranes :: const_iterator :: operator ++ () { 
    
    if ( it.GetNodo() != 0 ) {
        
        ++it;

        if ( it.GetNodo() != 0 ) 
            while ( !it.Hoja() ) 
                ++it;      
    }

    return *this;
}



//-------------------------------------------------//
//------------- BEGIN y END -----------------------//
//-------------------------------------------------//

Refranes :: iterator Refranes :: begin () {

    iterator itb;
    ArbolGeneral<string> :: iter_preorden it;
    it = ab.begin();

    while ( !it.Hoja() ) 
        ++it;
    
    itb.it = it;
    return itb;
}

Refranes :: iterator Refranes :: end () {
    iterator ite;
    ite.it = ab.end();
    ite.cad = "";
    return ite;
}
  
Refranes :: const_iterator Refranes :: Cbegin () const {

    const_iterator itb;
    ArbolGeneral<string> :: const_iter_preorden it;
    it = ab.cbegin();

    while ( !it.Hoja() ) 
        ++it;
    
    itb.it = it;
    return itb;
}

Refranes :: const_iterator Refranes :: Cend () const {
    const_iterator ite;
    ite.it = ab.cend();
    return ite;
}