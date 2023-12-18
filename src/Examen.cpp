
#include "Examen.h"

//metodo que reserva memoria
void Examen::ReservarMemoria(const Examen & otro){
	
	preguntas = new Pregunta [otro.GetCapacidad()];
	
}
	
//metodo que libera memoria
void Examen::LiberaMemoria(){
	if (preguntas != nullptr){
		delete[] preguntas;	
		preguntas = nullptr;
	}
	utilizados = 0;
	capacidad = 0;
}

//metodo que copia datos
void Examen::CopiarDatos(const Examen & otro){
	utilizados = otro.GetUtilizados();
	capacidad = otro.GetCapacidad();
	for(int i = 0; i < otro.GetUtilizados(); i++){
		preguntas[i] = otro[i];
	
	}

}
	
//metodo para el operador corchetes []
Pregunta & Examen::preguntita(const int elemento)const{

	return preguntas[elemento];



}
	
//constructor sin parametros
Examen::Examen(){
	
	preguntas = nullptr;
	utilizados = 0;
	capacidad = 0;


}

//operador de asignacion
Examen & Examen::operator= (const Examen & otro){
	if (this != &otro){
		LiberaMemoria();
		ReservarMemoria(otro);
		CopiarDatos(otro);	
	}
	return *this;


}

//constructor para una cadena con capacidad inicial
Examen::Examen(int capacida_ini){

	preguntas = new Pregunta [capacida_ini];
	utilizados = 0;
	capacidad = capacida_ini;


}
	
//destructor
Examen::~Examen(){

	LiberaMemoria();
	

}
	
//aniade al vector el elemento pregunta en el elemento que se diga,
//si esta lleno se redimensiona por bloques
//pos es la posicion donde se va a aniadir y p la pregunta que se 
//va a aniadir
void Examen::Aniade(const Pregunta & p){
	if (utilizados == capacidad){
		Examen aux (capacidad + BLOQUE);
		for(int i = 0 ; i < utilizados ; i++){
			aux[i] = preguntas[i];
		
		}
		
		*this = aux;	
		
	}
	preguntas[utilizados] = p;
	utilizados++;
}

//saca un elemento pregunta en el elemento que s le diga	
Pregunta & Examen::operator [] (const int elemento){

	return(preguntita(elemento));
	
}
Pregunta & Examen::operator [] (const int elemento)const{

	return(preguntita(elemento));

}
	
//funcion que pone la cap del vector al mismo nivel que los utiles
void Examen::Ecualiza_util(){
	while(utilizados > capacidad){
		Examen aux (utilizados);
			
			for(int i = 0; i < utilizados ; i++){
				aux[i] = preguntas[i];
			
			}
			
			*this = aux;
	}
}
	
//pone el utilizados del vector
void Examen::SetUtilizados(int util){
	utilizados = util;
}
	
//pone la capacidad del vector
void Examen::SetCapacidad(int capacidades){
	capacidad = capacidades;
}
	
//te devuelve los utlizaddos del vector
int Examen::GetUtilizados(void)const{
	return utilizados;
}
	
//te devuelve la capacida maxima del vector
int Examen::GetCapacidad(void)const{
	return capacidad;

}



