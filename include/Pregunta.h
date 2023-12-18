

#ifndef PREGUNTA
#define PREGUNTA
#include <chrono>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;



class Pregunta {

	private:
	
	static const char DELIMITADOR = '*';
	char * pregunta;
	char * res1;
	char * res2;
	char * res3;
	char * res4;
	char * correcta;
	
	//estos 3 metodos reservan, liberan y copian datos
	
	void ReservarMemoria(const Pregunta & preguntita);
	
	void LiberaMemoria();
	
	void CopiarDatos(const Pregunta & preguntita);
	
	
	public:
	
	//sin paramentros
	Pregunta();
	
	//constructor para la redireccion
	//tiene que ir en el orden de la declaracion de los string y por ultimo
	//la correcta
	Pregunta(string linea,char delimitador=DELIMITADOR);
	
	//destructor
	~Pregunta();
	
	//pone igual a los dos objetos si son distintos
	Pregunta & operator= (const Pregunta & otro);
	
	//todos los metodos son get y set de toda la vida
	
	string GetCorrecta()const;
	
	string GetRes4()const;
	
	string GetRes3()const;
	
	string GetRes2()const;
	
	string GetRes1()const;
	
	string GetPregunta()const;
	
	void SetPregunta(string preguntita);
	
	void SetRes1(string respuesta);
	
	void SetRes2(string respuesta);
	
	void SetRes3(string respuesta);
	
	void SetRes4(string respuesta);
	
	void SetCorrecta(string correctas);	
	

};



#endif
