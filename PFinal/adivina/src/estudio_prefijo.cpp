#include <cstdlib>
#include "refranes.h"

using namespace std;


/** 
 * @file estudio_prefijo.cpp 
 * @author Gregorio Vidoy Fajardo y Jesus Ruiz Castellano
 * @date 18 de enero de 2017, 18:15
 * @brief Fichero con la implementacion del estudio de los prefijos
 */
 

/**
 * @brief Metodo para imprimir la cabecera de la tabla
 * @param os : Variable de flujo de escritura de los nombres
 */
void cabeceraTabla ( ostream &os ) {
   
     //Prefijo
  os << "Prefijo" << ";"
     //Car.Total
     << "Car.Total" << ";"
     //Car.Arb    
     << "Car.Arb " << ";"
     //%Red    
     << "%Red" << ";"
     //# Nodos    
     << "#Nodos " << ";"
     //%Red/#Nodos    
     << "%Red/#Nodos" << endl;
}


/**
 * @brief Metodo para imprimir una fila de la tabla 
 * @param ref : Refranes de los que vamos a obtener los datos
 * @param os : Variable de flujo de escritura de los datos
 */
void sacarDatosRefranes ( Refranes &ref, ostream &os ) {
   
 	// formula para obtener el porcentaje de reduccion
  double red = 100.0 - ( (ref.Caracteres_Almacenados()*100.0) / ref.Caracteres_Refranes() );
     //Prefijo
  os << ref.getLen_prefijo() << ";"
     //Car.Total
     << ref.Caracteres_Refranes() << ";"
     //Car.Arb    
     << ref.Caracteres_Almacenados() << ";"
     //%Red    
     << red << ";"
     //# Nodos    
     << ref.Numero_Nodos() << ";"
     //%Red/#Nodos    
     << red/ref.Numero_Nodos() << endl;         
}



int main (int argc, char** argv) {
    
  if ( argc != 3 ) {
    cout << "\n Los parametros son : " << endl;
    cout << " 1.- Dime el nombre del fichero los refranes" << endl;
    cout << " 2.- Dime el nombre del fichero CSV de salida {nombreArchivo.csv}" << endl << endl;
    return 0;
  }
      
  // Creamos el fichero csv en el que vamos a sacar los datos
  ofstream salida ( argv[2] );
  
  if (!salida) {
    cout << "\n No puedo crear el fichero de salida " << argv[2] << endl;
    return 0;
  }
  
  cabeceraTabla(salida); // Imprimimos la cabecera
  
  for ( int i = 2 ; i <= 14 ; i++ ) {
   	// Lectura del fichero con los refranes
    ifstream fin ( argv[1] ); 
     
		if (!fin) {
      cout << "\n No puedo abrir el fichero " << argv[1] << endl;
      return 0;
    }

    Refranes refs(i);
    fin >> refs;
    sacarDatosRefranes (refs, salida);  
  }

	return 0;
}