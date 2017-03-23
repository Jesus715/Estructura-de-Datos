SRC = ./src/
INC = ./include/
OBJ = ./obj/
BIN = ./bin/
LIB = ./lib/
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11 -I$(INC) 


# ************ Compilación de módulos ************
 

$(BIN)pruebatrad_test : $(OBJ)pruebatrad_test.o $(LIB)libtest.a
	$(CXX) -o $(BIN)pruebatrad_test $(OBJ)*.o -I$(INC) -L$(LIB) -ltest

$(LIB)libtest.a : $(OBJ)conjuntofrases.o $(OBJ)frases.o
	ar rvs $(LIB)libtest.a $(OBJ)conjuntofrases.o $(OBJ)frases.o

$(OBJ)frases.o : $(SRC)frases.cpp $(INC)frases.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)frases.o $(SRC)frases.cpp 

$(OBJ)conjuntofrases.o : $(SRC)conjuntofrases.cpp $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)conjuntofrases.o $(SRC)conjuntofrases.cpp $(OBJ)frases.o 
 

$(OBJ)pruebatrad_test.o : $(SRC)pruebatrad_test.cpp $(OBJ)conjuntofrases.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)pruebatrad_test.o $(SRC)pruebatrad_test.cpp $(OBJ)conjuntofrases.o $(OBJ)frases.o 



# ************ Generación de documentación ******************

documentacion:
	@echo "Generando documentacion de Doxygen..."
	doxygen doc/doxys/Doxyfile

	

# ************ Limpieza ************  

mrproper :
	@echo "Limpiando contenido basura en directorios..."
	rm $(BIN)* $(OBJ)* $(LIB)* $(SRC)*~ $(INC)*~ ./*~ doc/html/* 



# ************ Creacion ************

install:
	mkdir $(BIN) $(OBJ) $(LIB) 



# ************************* Empaquetado ****************************
# Genera el archivo .tgz de la práctica mediante la linea de comandos
# Genera el archivo en el directorio padre al que abrimos el Terminal
# Coge el nombre del directorio como nombre 

tar:  
	@echo "Empaquetando..."
	tar --exclude "*.tgz" --exclude datos --exclude "*~" -zcvf ../traductor.tgz ../traductor 


