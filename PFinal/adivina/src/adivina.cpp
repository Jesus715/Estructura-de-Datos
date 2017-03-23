#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <utility>
#include <ctype.h>
#include "refranes.h"

using namespace std;


/** 
 * @file adivina.cpp 
 * @author Gregorio Vidoy Fajardo y Jesus Ruiz Castellano
 * @date 25/01/2017
 * @brief Fichero con la implementacion del juego Adivina Refran
 *        utilizando la representacion basada en Arbol General para
 *        almacenar los refranes
 */


// Declaracion adelantada
pair<int,string> Destaparletras ( const string& original, const string& refranJuego, const char& letra );
void ImprimeRefran ( const string& Refran ) ;


/**
 * @brief Metodo para seleccionar un refran aleatoriamente
 * @param refs : objeto refranes del que se selecciona uno
 * @return Devolvemos el refran seleccionado
 */ 
string SeleccionRefran ( Refranes refs ) {

  //Obtengo el numero de refranes leido
  int totalRefranes = refs.size();
  Refranes :: iterator it;
  it = refs.begin();

  srand (time(NULL));
  int nReframElegido = rand() % totalRefranes; // selecciona uno aleatorio

  // Nos posicionamos en el elegido
  for (int i  = 0; i < nReframElegido; i++)
    ++it;
  
  return (*it);
}


/**
 * @brief Metodo para imprimir un refran durante el juego
 * @param Refran : Es el refran a imprimir
 */
void ImprimeRefran ( const string& Refran ) {

  for ( unsigned int i = 0 ; i < Refran.size() ; i++ ) 
    cout << " " << Refran[i] << ' ';

  cout << endl;
}


/**
 * @brief Este metodo, al ser llamado, destapa la primera letra oculta que encuentre
 * @param original : el refran original
 * @param result : el refran resultado tras destapar una letra
 * @return Devuelve el numero de letras destapadas y el refran resultado de destapar
 *         esas letras
 */
pair<int,string> Ayuda ( const string& original, const string& result ) {

  char letraAdestapar = result[0]; // Inicializamos a una valida
  int pos = 0;

  while ( letraAdestapar != '_' ) {
    pos++;
    letraAdestapar = result[pos];
  }

  letraAdestapar = original[pos];

  pair<int,string> Resultado;
  Resultado = Destaparletras ( original, result, letraAdestapar );

  if ( Resultado.second != original )  
    cout << "\n (Ayuda) Boot says: ---> Letra destapada : " << letraAdestapar << endl;

  if ( Resultado.second == original ) {
    cout << "\n (Ayuda) Boot says: ¡¡¡ ERES UN PAQUETE !!!" 
         << "\n                    Solo queda una letra por descubrir..." 
         << "\n                    No querras que te lo destape entero, ¿no? " << endl;
  
    Resultado.first = 0;
    Resultado.second = result;
  }

  return Resultado;
}


/**
 * @brief Metodo para pasar un refran a minuscula
 * @param cad : Es el refran que se pasa a minuscula
 * @return El refran ya en minuscula
 */
string TodoMinuscula ( const string &cad ) {

  string caux; 

  for ( unsigned char i = 0 ; i < cad.size() ; ++i )
    caux.push_back(tolower(cad[i]));

  return caux;
}


/**
 * @brief Este metodo, al ser llamado, destapa la letra oculta que se le indica
 * @param original : el refran original
 * @param refranJuego : el refran resultado tras destapar la letra
 * @param letra : letra a destapar de refranJuego 
 * @return Devuelve el numero de letras destapadas y el refran resultado de destapar
 *         esas letras
 */
pair<int,string> Destaparletras ( const string& original, const string& refranJuego, const char& letra ) {
  
  string result = refranJuego;
  int cuentaLetras = 0;

  for ( unsigned int i = 0 ; i < result.size() ; i++ ) {

    if ( letra == original[i] ) {
      result[i] = original[i];
      cuentaLetras++;
    }
  }
  
  pair<int,string> Resultado(cuentaLetras,result);
  return Resultado;
}


/**
 * @brief Este metodo oculta el porcentaje de letras indicado en el refran dado
 * @param original : el refran a tratar
 * @param porcentaje : el porcentaje de letras que vamos a ocultar de original
 * @return Devuelve el nuevo refran, ya con un numero de letras ocultadas
 */
string Ocultarletras ( const string& original, const int& porcentaje ) {

	string result = original;
	int tamano = 0;
	int cont = 0;
	int ocultas = 0;

  	// No usamos size, porque queremos el numero de letras (sin espacios)
	for ( unsigned int i = 0 ; i < original.size() ; i++ ) 
    	if ( original[i] != ' ' )
			tamano++;
  
  	ocultas = (tamano*porcentaje)/100;
  
  	while (cont <= ocultas && cont != tamano) {

	    bool encontrado = false;   
	    char letraAocultar = '_';

	    srand (time(NULL));
	    int pos = rand() % (tamano + 1);
	    letraAocultar = result[pos];
    
	    if ( letraAocultar == '_' || letraAocultar == ' ' ) {
	      for ( unsigned int i = 0 ; i < original.size() && !encontrado ; i++ )
	        if ( result[i] != '_' && result[i] != ' ' ) {
	          letraAocultar = result[i];
	          encontrado = true;
	        }    
	    }

		for ( unsigned int i = 0 ;  i < original.size() ; i++ )
			if ( result[i] == letraAocultar ) {
	        	result[i] = '_';
	        	cont++; 
	      	}     
  	}

  	return result;
}  



/**
 * @brief Metodo para estimar un numero de intentos en funcion del 
 *        porcentaje de letras a ocultar ( dificultad )
 * @param porcentaje : es el porcentaje de letras ocultas
 * @return El numero de intentos que tiene el jugador para adivinar
 */
int CalculaIntentos ( const int& porcentaje ) {

	int intentos = 0;

	if ( porcentaje >= 0 && porcentaje <= 25 )
		intentos = 10;
	else if ( porcentaje > 25 && porcentaje <= 50 )
		intentos = 8;
	else if ( porcentaje > 50 && porcentaje <= 75 )
		intentos = 6;
	else
		intentos = 5;

	return intentos;
}



int main ( int argc, char * argv[] ) {

	if ( argc != 3 && argc != 2 ) {
		cout << " Los parametros son:" << endl;
		cout << " 1.Dime el nombre del fichero los refranes" << endl;
		cout << " 2.-[Opcional] porcentaje de letras sin ocultar" << endl;
		return 0;
	}    
  
	ifstream fin (argv[1]);
	if (!fin) {
		cout << " No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

  	int porcentaje = 50;
  
	if (argc == 3)
    	porcentaje = atoi(argv[2]);

  	Refranes refs(3);
  
	int rondas = 1; // Inicializamos las rondas
	// Estimamos el numero de intentos en funcion del porcentaje tendremos mas o menos intentos
	int IntentosTotales = CalculaIntentos(porcentaje); 
	int cuentaIntentos = 0; // Contador para saber cuantos intentos lleva el jugador
	int cuentaAyuda = 0; 	// Contador para la ayuda

	fin >> refs;
	string Refran = SeleccionRefran(refs); // Selecciona un refran aleatorio


	cout << "\n\n ************************** QUE COMIENCE EL JUEGO ***************************" 
         << endl << "\n\t\t\t   ¡¡¡ ADIVINA REFRAN !!!"
	     << endl << endl << " ********************************* RONDA ["<< rondas << "] ********************************" << endl;
	cout << "\n Ocultando refrán... "
	     << "\n Tienes " << IntentosTotales << " intentos para acertar..." << endl << endl;

	string refranOculto = Ocultarletras ( Refran, porcentaje );

	char continuar = 's';
	char letra;
	string eleccion;
	int encontradas = 0;

  	while ( continuar == 's' ) {

		ImprimeRefran(refranOculto);

		cout << "\n (Ayuda) Boot says: ---> Pulsa 0 para obtener ayuda" << endl;
		cout << " Dime un caracter (o el refran para resolver): ";

		getline(cin,eleccion);

		eleccion = TodoMinuscula(eleccion);

    	if ( eleccion.size() == 1 ) { // El jugador ha introducido una letra
      
			cuentaIntentos++;    
	      	pair<int,string> destapa;
	      	letra = eleccion[0];

      		if ( letra != '0' ) { 

        		destapa = Destaparletras(Refran, refranOculto, letra);

        		if ( destapa.second == refranOculto ) {
          
	          		destapa.first = 0;    

	          		// Le hago un casting para evitar un Warning en la comparacion
	          		if ( (signed int)Refran.find(letra) != -1  ) 
	            		cout << "\n (Ayuda) Boot says: ---> Letra ya destapada " << endl; 
	          		else 
		            	cout << "\n (Ayuda) Boot says: ---> FRIO FRIO... Esa letra no esta!!" << endl;
	        	}
      		} 
      		else { 
      			// El jugador como maximo dispone de 3 ayudas
        		if ( cuentaAyuda < 3 ) {
	        		destapa = Ayuda(Refran, refranOculto);
	        		cuentaAyuda++;
	        	}
				else {
					cout << "\n (Ayuda) Boot says: ---> Calientate mas el coco... Lo dejo en tus manos!!" << endl;        
					destapa.first = 0;
					destapa.second = refranOculto;
					cuentaIntentos--;
				}
      		}
    
			refranOculto = destapa.second;
			encontradas = destapa.first;
			cout << " Encontradas : " << encontradas << endl; 
      
      		if ( (IntentosTotales - cuentaIntentos) != 1 )
        		cout << " Te quedan " << IntentosTotales - cuentaIntentos << " intentos..." << endl << endl;
      		else
        		cout << " ¡¡¡ ATENCION : ULTIMO INTENTO !!! *** Resuelve o muere *** : " << endl << endl;

      		if ( refranOculto == Refran ) {
        		cout << "\n ¡¡¡¡¡ LO HAS ADIVINADO !!!!! : " << Refran << endl;
        
	       	 	do { // Por si el jugador es algo travieso e introduce algo distinto
	          		cout << "\n\n ¿ Quieres seguir jugando [S/N] ? ";
					cin >> continuar;
					cin.ignore(256,'\n');
					continuar = tolower(continuar);
				} while ( continuar != 's' && continuar != 'n' );

        		cout << endl << endl;

	        	if ( continuar == 's' ) {
					cuentaIntentos = 0;
					cuentaAyuda = 0;
					Refran = SeleccionRefran(refs);
					refranOculto = Ocultarletras ( Refran, porcentaje );
					rondas++;
					cout << "\n\n ************************** QUE COMIENCE EL JUEGO ***************************" 
               			 << endl << "\n\t\t\t   ¡¡¡ ADIVINA REFRAN !!!"
					     << endl << endl << " ********************************* RONDA ["<< rondas << "] ********************************" << endl;
					cout << "\n Ocultando refrán... "
					     << "\n Tienes " << IntentosTotales << " intentos para acertar..." << endl << endl;
				}
      		}
    	}	
    	else { // El jugador ha probado con un refran completo
      
      		if ( eleccion == Refran ) {
        	
        		cout << "\n\n ¡¡¡¡¡ LO HAS ADIVINADO !!!!! : " << Refran << endl;

	        	do { // Por si el jugador es algo travieso e introduce algo distinto
	          		cout << "\n\n ¿ Quieres seguir jugando [S/N] ? ";
		          	cin >> continuar;
		          	cin.ignore(256,'\n');
		          	continuar = tolower(continuar);
		        } while ( continuar != 's' && continuar != 'n' );

	        	cout << endl << endl;

	        	if ( continuar == 's' ) {
	          		cuentaIntentos = 0; 
	          		cuentaAyuda = 0;
	          		Refran = SeleccionRefran(refs);
	          		refranOculto = Ocultarletras ( Refran, porcentaje );
	          		rondas++;
	          		cout << "\n\n ************************** QUE COMIENCE EL JUEGO ***************************" 
               			 << endl << "\n\t\t\t   ¡¡¡ ADIVINA REFRAN !!!"
	               		 << endl << endl << " ********************************* RONDA ["<< rondas << "] ********************************" << endl;
	          		cout << "\n Ocultando refrán... "
	                	 << "\n Tienes " << IntentosTotales << " intentos para acertar..." << endl << endl;
	        	}
      		}
      		else {
        
        		cuentaIntentos++;
        		cout << "\n ¡¡¡¡¡¡¡¡¡ MEEEEEECCCCCC !!!!!!!!! EEEEEEERROOOOOORRRRR " << endl << endl;
        
        		if ( (IntentosTotales - cuentaIntentos) != 1 )
          			cout << " Te quedan " << IntentosTotales - cuentaIntentos << " intentos..." << endl << endl;
        		else
  					cout << " ¡¡¡ ATENCION : ULTIMO INTENTO !!! *** Resuelve o muere *** : " << endl << endl;
      		}
    	}

    	if ( cuentaIntentos == IntentosTotales ) { // El jugador ha perdido
      
      		ImprimeRefran(refranOculto); // Muestra hasta donde ha conseguido destapar el jugador	
      		cout << "\n (Ayuda) Boot says: ---> El Refran que buscabas era : \"" << Refran << "\""<< endl;
      		cout << "\n\n \t\t\t\t G  A  M  E    O  V  E  R" << endl << endl;

      		do { // Por si el jugador es algo travieso e introduce algo distinto
          		cout << "\n\n ¿ Quieres seguir jugando [S/N] ? ";
          		cin >> continuar;
          		cin.ignore(256,'\n');
          		continuar = tolower(continuar);
        	} while ( continuar != 's' && continuar != 'n' );

        	cout << endl << endl;

        	if ( continuar == 's' ) {
          		cuentaIntentos = 0; 
          		cuentaAyuda = 0;
          		Refran = SeleccionRefran(refs);
          		refranOculto = Ocultarletras ( Refran, porcentaje );
          		rondas++;
          		cout << "\n\n ************************** QUE COMIENCE EL JUEGO ***************************" 
               		 << endl << "\n\t\t\t   ¡¡¡ ADIVINA REFRAN !!!"
               		 << endl << endl << " ********************************* RONDA ["<< rondas << "] ********************************" << endl;
          		cout << "\n Ocultando refrán... "
               		 << "\n Tienes " << IntentosTotales << " intentos para acertar..." << endl << endl;
        	}
   		}
  	} // FIN WHILE
  	return 0;
}