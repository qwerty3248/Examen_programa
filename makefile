#el makefile para compilar el examen

HOME = .
SRC=$(HOME)/src
LIB=$(HOME)/lib
INCLUDE=$(HOME)/include
OBJ=$(HOME)/obj
BIN=$(HOME)/bin


all : $(BIN)/main $(BIN)/crea


$(LIB)/libExamen.a : $(OBJ)/Examen.o 
	@echo Creando objeto $(LIB)/libExamen.a
	ar -rvs  $(LIB)/libExamen.a \
	$(OBJ)/Examen.o 



$(OBJ)/Examen.o : $(SRC)/Examen.cpp $(INCLUDE)/Examen.h $(INCLUDE)/Pregunta.h  
	@echo Creando objeto $(OBJ)/FuncsVectorDinamico.o
	g++ -c -o $(OBJ)/Examen.o \
	$(SRC)/Examen.cpp -I./include -std=c++14


$(LIB)/libPregunta.a : $(OBJ)/Pregunta.o 
	@echo Creando objeto $(LIB)/libPregunta.a
	ar -rvs  $(LIB)/libPregunta.a \
	$(OBJ)/Pregunta.o 



$(OBJ)/Pregunta.o : $(SRC)/Pregunta.cpp $(INCLUDE)/Pregunta.h 
	@echo Creando objeto $(OBJ)/Pregunta.o
	g++ -c -o $(OBJ)/Pregunta.o \
	$(SRC)/Pregunta.cpp -I./include -std=c++14

$(LIB)/libGeneradorAleatorioEnteros.a : $(OBJ)/GeneradorAleatorioEnteros.o 
	@echo Creando objeto $(LIB)/libGeneradorAleatorioEnteros.a
	ar -rvs  $(LIB)/libGeneradorAleatorioEnteros.a \
	$(OBJ)/GeneradorAleatorioEnteros.o 



$(BIN)/crea:$(OBJ)/crea.o
	g++ -o $(BIN)/crea $(OBJ)/crea.o  


$(OBJ)/crea.o:$(SRC)/crea_pregunta.cpp
	g++ -c -o $(OBJ)/crea.o $(SRC)/crea_pregunta.cpp

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
$(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo Creando objeto $(OBJ)/GeneradorAleatorioEnteros.o
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
	$(SRC)/GeneradorAleatorioEnteros.cpp -I./include -std=c++14
	
	
$(BIN)/main : $(OBJ)/main.o \
$(LIB)/libGeneradorAleatorioEnteros.a $(LIB)/libExamen.a $(LIB)/libPregunta.a
	@echo Creando ejecutable $(BIN)/main 
	g++ -o $(BIN)/main $(OBJ)/main.o \
	    -L./lib -lGeneradorAleatorioEnteros -lPregunta -lExamen 


$(OBJ)/main.o : $(SRC)/main.cpp \
$(INCLUDE)/GeneradorAleatorioEnteros.h $(INCLUDE)/Pregunta.h $(INCLUDE)/Examen.h
	@echo Creando objeto $(OBJ)/main.o
	g++ -c -o $(OBJ)/main.o $(SRC)/main.cpp -I./include  -std=c++14	
	
clean:
	-rm $(OBJ)/*
	@echo Objetos borrados

mr.proper: clean 
	-rm $(BIN)/*
	-rm $(LIB)/*
	@echo Ejecutables borrados
	

