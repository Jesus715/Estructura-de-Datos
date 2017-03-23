SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin

CXX = g++
CPPFLAGS = -Wall -g -std=c++11 -I$(INC) -c


# ************* Ejecutable ***********************************   
all: $(BIN)/orden $(BIN)/usopilas_max $(BIN)/usocolas


$(BIN)/orden: $(OBJ)/orden.o
	$(CXX) -o $(BIN)/orden $(OBJ)/orden.o 

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o $(INC)/Pila_maxmin.h
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o

$(BIN)/usocolas: $(OBJ)/usocolas.o $(INC)/Cola_maxmin.h
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o


$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/Pila_maxmin.h $(INC)/Pila_maxmin_Cola.h $(INC)/Pila_maxmin_Cola.cpp $(INC)/Pila_maxmin_List.h $(INC)/Pila_maxmin_List.cpp $(INC)/Pila_maxmin_VD.h $(INC)/Pila_maxmin_VD.cpp  $(INC)/Pila_maxmin.h
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o -I$(INC) 

$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)

$(OBJ)/orden.o: $(INC)/Pila_maxmin.h $(SRC)/orden.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/orden.cpp  -o $(OBJ)/orden.o -I$(INC)


# ************* Generación de documentación ******************
documentacion:
	@echo "Generando documentacion de Doxygen..."
	doxygen doc/doxys/Doxyfile


# ************* Limpieza *************************************
clean:
	@echo "Limpiando y actualizando contenido de los directorios"
	rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: 
	@echo "Limpiando ejecutables y documentacion"
	rm $(BIN)/* doc/html/*


# ********************* Empaquetamiento *********************
tar: 
	@echo "Empaquetando..."
	tar --exclude "*.tgz" --exclude datos --exclude "*~" -zcvf ../pila_maxmin.tgz ../pila_maxmin




