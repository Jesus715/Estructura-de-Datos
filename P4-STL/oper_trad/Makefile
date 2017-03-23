SRC = ./src/
INC = ./include/
OBJ = ./obj/
BIN = ./bin/
LIB = ./lib/
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11 -I$(INC) 


# ************ Compilación de módulos ************ 	

$(BIN)sumar: $(OBJ)sumar.o $(LIB)libtest.a
	$(CXX) -o $(BIN)sumar $(OBJ)*.o -I$(INC) -L$(LIB) -ltest 

$(BIN)concatenar : $(OBJ)concatenar.o $(LIB)libtest.a
	$(CXX) -o $(BIN)concatenar $(OBJ)*.o -I$(INC) -L$(LIB) -ltest

$(BIN)traductor_inverso : $(OBJ)traductor_inverso.o $(LIB)libtest.a
	$(CXX) -o $(BIN)traductor_inverso $(OBJ)*.o -I$(INC) -L$(LIB) -ltest

$(BIN)pruebatraductor : $(OBJ)pruebatraductor.o $(LIB)libtest.a
	$(CXX) -o $(BIN)pruebatraductor $(OBJ)*.o -I$(INC) -L$(LIB) -ltest
   

 

$(LIB)libtest.a : $(OBJ)traductor.o $(OBJ)frases.o
	ar rvs $(LIB)libtest.a $(OBJ)traductor.o $(OBJ)frases.o



$(OBJ)frases.o : $(SRC)frases.cpp $(INC)frases.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)frases.o $(SRC)frases.cpp 

$(OBJ)traductor.o : $(SRC)traductor.cpp $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)traductor.o $(SRC)traductor.cpp $(OBJ)frases.o 
 
$(OBJ)pruebatraductor.o : $(SRC)pruebatraductor.cpp $(OBJ)traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)pruebatraductor.o $(SRC)pruebatraductor.cpp $(OBJ)traductor.o $(OBJ)frases.o 

$(OBJ)traductor_inverso.o : $(SRC)traductor_inverso.cpp $(OBJ)traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)traductor_inverso.o $(SRC)traductor_inverso.cpp $(OBJ)traductor.o $(OBJ)frases.o

$(OBJ)sumar.o: $(INC)traductor.h $(SRC)sumar.cpp $(OBJ)traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS)  $(SRC)sumar.cpp  -o $(OBJ)sumar.o $(OBJ)traductor.o $(OBJ)frases.o

$(OBJ)concatenar.o: $(INC)traductor.h $(SRC)concatenar.cpp $(OBJ)traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS)  $(SRC)concatenar.cpp  -o $(OBJ)concatenar.o $(OBJ)traductor.o $(OBJ)frases.o


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
	tar --exclude "*.tgz" --exclude datos --exclude "*~" -zcvf ../oper_trad.tgz ../oper_trad 


