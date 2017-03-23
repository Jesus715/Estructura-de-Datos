#include "refranes_hash.h"
#include <vector>

/** 
 * @file refranes_hash.cpp 
 * @author Jesus Ruiz Castellano y Gregorio Vidoy Fajardo
 * @date 24/01/2017
 * @brief Fichero implementacion del TDA Refranes, implementado
 *        a partir de una tabla hash
 */



//---------------------------------------------------//
//-------------- FUNCIONES my_hash ------------------//
//---------------------------------------------------//

void Refranes :: my_hash :: set_len (int l) {
    len = l;
}


size_t Refranes :: my_hash :: operator() (const string & clave) const {

    size_t valor = 0;
    int exp = 2;
    
    for ( int i = 0 ; i < 3 ; i++ ) {
        valor += clave[0] * (pow(28,exp));
        exp--;
    }
    
    return valor;
}



//---------------------------------------------------//
//-------------- FUNCIONES PUBLICAS -----------------//
//---------------------------------------------------//

Refranes :: Refranes () {     

    n_ref = 0;
    caracteres_totales = 0;
}


int Refranes :: size () const {
    return ab.size();
}


void Refranes :: Insertar ( const string &refran ) {
    ab.insert(refran);
}


void Refranes :: BorrarRefran ( const string &refran) {
    ab.erase(refran);
}


pair<bool,Refranes ::iterator> Refranes :: Esta (const string &refran) {

    bool esta = false;
    iterator encontrado;

    unordered_set<string,my_hash> :: iterator got = ab.find(refran);
    unordered_set<string,my_hash> :: iterator itF = ab.end();

    encontrado.it = got;
    pair<bool, Refranes :: iterator> aux(esta, encontrado ) ;

    if ( got != itF ) {
        esta = true;
        aux.first = esta;
        aux.second = encontrado;
    }

    return aux; 
}


void Refranes :: clear () {
    ab.clear();
}



//----------------------------------------------------//
//-------------- FUNCIONES AMIGAS --------------------//
//----------------------------------------------------//

istream& operator>> (istream &is, Refranes &R) {

    while ( !is.eof() ) {
        string refran;
        getline(is,refran);

        if (refran[refran.size()-1] == ' ') 
            refran.pop_back();

        R.Insertar(refran);
    }

    return is;
}


ostream& operator<< (ostream &os, Refranes &R) {

    Refranes :: iterator itrr = R.begin(); 

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



//-------------------------------------------------//
//------------- FUNCIONES iterador ----------------//
//-------------------------------------------------//       

string Refranes :: iterator :: operator* () {               
    return (*it); 
}

bool Refranes :: iterator :: operator== ( const iterator &i ) const {
    return it == i.it;        
}

bool Refranes :: iterator :: operator!= ( const iterator &i ) const {
    return it != i.it; 
}

Refranes :: iterator & Refranes :: iterator :: operator ++ () {
    ++it;
    return *this;
}



//-------------------------------------------------//
//------------- FUNCIONES const_iterator ----------//
//-------------------------------------------------//   

Refranes :: const_iterator :: const_iterator (const iterator  &i) {
    it = i.it;
}

string Refranes :: const_iterator :: operator *() const {
    return (*it);
}

bool Refranes :: const_iterator :: operator== (const const_iterator &i) const {
    return it == i.it; 
}

bool Refranes :: const_iterator :: operator!= ( const const_iterator &i ) const {
    return it != i.it; 
}

Refranes :: const_iterator& Refranes :: const_iterator :: operator ++() { 
    ++it;
    return *this;
}



//-------------------------------------------------//
//------------- BEGIN y END -----------------------//
//-------------------------------------------------//

   Refranes :: iterator Refranes :: begin () {

        iterator itb;
        itb.it = ab.begin();
        return itb;
    }
    
    Refranes :: iterator Refranes :: end () {

        iterator ite;
        ite.it = ab.end();
        return ite;
    }
      

    Refranes :: const_iterator Refranes :: Cbegin () const {
        
        const_iterator itb;
        itb.it = ab.cbegin();
        return itb;
    }
    
    Refranes :: const_iterator Refranes :: Cend () const {

        const_iterator ite;
        ite.it = ab.cend();
        return ite;
    }