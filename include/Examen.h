
#include "Pregunta.h"
#ifndef EXAMEN
#define EXAMEN
#include <chrono>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//solo va a ver un tipo de redimension, en bloque 




class Examen{

	private:
	static const int BLOQUE = 100;
	static const int CAPACIDAD_BASE = 100;
	Pregunta * preguntas;
	int utilizados;
	int capacidad;
	
	//metodo que reserva memoria
	void ReservarMemoria(const Examen & otro);
	
	//metodo que libera memoria
	void LiberaMemoria();
	
	//metodo que copia datos
	void CopiarDatos(const Examen & otro);
	
	//metodo para el operador corchetes []
	Pregunta & preguntita(const int elemento)const;

	public:
	
	//constructor sin parametros
	Examen();
	
	
	//constructor para una cadena con capacidad inicial
	Examen(int capacida_ini);
	
	//destructor
	~Examen();
	
	//aniade al vector el elemento pregunta en el elemento que se diga,
	//si esta lleno se redimensiona por bloques
	//pos es la posicion donde se va a aniadir y p la pregunta que se 
	//va a aniadir
	void Aniade(const Pregunta &p);
	
	//operador de asignacion
	Examen & operator= (const Examen & otro);
	
	//saca un elemento pregunta en el elemento que s le diga
	Pregunta & operator [] (const int elemento);
	Pregunta & operator [] (const int elemento)const;
	
	//funcion que pone la cap del vector al mismo nivel que los utiles
	void Ecualiza_util();
	
	//pone el utilizados del vector
	void SetUtilizados(int util);
	
	//pone la capacidad del vector
	void SetCapacidad(int capacidades);
	
	//te devuelve los utlizaddos del vector
	int GetUtilizados(void)const;
	
	//te devuelve la capacida maxima del vector
	int GetCapacidad(void)const;
	

};


#endif 


