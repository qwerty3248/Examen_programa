#include "Pregunta.h"

//metodos de reserva, libera y copia de datos

void Pregunta::ReservarMemoria(const Pregunta & preguntita){
	
	int tam_pre = (preguntita.GetPregunta()).size();
	int tam_res1 = (preguntita.GetRes1()).size();
	int tam_res2 = (preguntita.GetRes2()).size();
	int tam_res3 = (preguntita.GetRes3()).size();
	int tam_res4 = (preguntita.GetRes4()).size();
	int tam_correc = (preguntita.GetCorrecta()).size();
	
	
	
	pregunta = new char [tam_pre+1];
	res1 = new char [tam_res1+1];
	res2 = new char [tam_res2+1];
	res3 = new char [tam_res3+1];
	res4 = new char [tam_res4+1];
	correcta = new char [tam_correc+1];
	


}
	
void Pregunta::LiberaMemoria(){
	if (pregunta != nullptr){
		delete[] pregunta;
		pregunta = nullptr;
	}
	
	
	if (res1 != nullptr){
		delete[] res1;
		res1 = nullptr;
	}
	
	if (res2 != nullptr){
		delete[] res2;
		res2 = nullptr;
	}
	
	if (res3 != nullptr){
		delete[] res3;
		res3 = nullptr;
	}
	
	if (res4 != nullptr){
		delete[] res4;
		res4 = nullptr;
	}
	
	if (correcta != nullptr){
		delete[] correcta;
		correcta = nullptr;
	}
}
	
void Pregunta::CopiarDatos(const Pregunta & preguntita){

	
	int tam_pre = (preguntita.GetPregunta()).size();
	int tam_res1 = (preguntita.GetRes1()).size();
	int tam_res2 = (preguntita.GetRes2()).size();
	int tam_res3 = (preguntita.GetRes3()).size();
	int tam_res4 = (preguntita.GetRes4()).size();
	int tam_correc = (preguntita.GetCorrecta()).size();
	
	for (int i = 0; i < tam_pre;i++) {
		
		pregunta[i] = preguntita.GetPregunta()[i];
	
	
	
	}
	pregunta[tam_pre] = '\0';

	for (int i = 0;i < tam_res1;i++) {
	
		res1[i] = preguntita.GetRes1()[i];
	
	
	
	}
	res1[tam_res1] = '\0';
	
	for (int i = 0;i < tam_res2;i++) {
	
		res2[i] = preguntita.GetRes2()[i];
	
	
	
	}
	res2[tam_res2] = '\0';
	
	for (int i = 0;i < tam_res3;i++) {
	
		res3[i] = preguntita.GetRes3()[i];
	
	
	
	}
	res3[tam_res3] = '\0';
	
	for (int i = 0;i < tam_res4;i++) {
	
		res4[i] = preguntita.GetRes4()[i];
	
	
	
	}
	res4[tam_res4] = '\0';
	
	for (int i = 0;i < tam_correc;i++) {
	
	
		correcta[i] = preguntita.GetCorrecta()[i];
	
	
	}
	correcta[tam_correc] = '\0';


}

//sin paramentros
Pregunta::Pregunta(){

	pregunta = nullptr;
	res1 = nullptr;
	res2 = nullptr;
	res3 = nullptr;
	res4 = nullptr;
	correcta = nullptr;


}
	
//constructor para la redireccion
//tiene que ir en el orden de la declaracion de los string y por ultimo
//la correcta
Pregunta::Pregunta(string linea, char delimitador){
	int pos = 0;
	string aux = "", aux1 ="", aux2 ="", aux3 ="", aux4 ="", 
	       aux5 ="";
	while(linea[pos] != delimitador){
		aux += linea[pos];		
		pos++;
	}
	SetPregunta(aux);
	pos++;
	while(linea[pos] != delimitador){
		aux1+= linea[pos];		
		pos++;
	}
	SetRes1(aux1);
	pos++;
	while(linea[pos] != delimitador){
		aux2+= linea[pos];		
		pos++;
	}
	SetRes2(aux2);
	pos++;
	while(linea[pos] != delimitador){
		aux3+= linea[pos];		
		pos++;
	}
	SetRes3(aux3);
	pos++;
	while(linea[pos] != delimitador){
		aux4+= linea[pos];		
		pos++;
	}
	SetRes4(aux4);
	pos++;
	while(linea[pos] != delimitador){
		aux5+= linea[pos];		
		pos++;
	}
	SetCorrecta(aux5);


}
	
//destructor
Pregunta::~Pregunta(){
	LiberaMemoria();

}
	
//pone igual a los dos objetos si son distintos
Pregunta & Pregunta:: operator= (const Pregunta & otro){

	if (this != &otro){
	
		LiberaMemoria();
		ReservarMemoria(otro);
		CopiarDatos(otro);
	
	}
	
	return *this;

}
	
//todos los metodos son get y set de toda la vida
	
string Pregunta::GetCorrecta()const{
	
	string correcto = "\0";
	int elemento = 0;
	while(correcta[elemento] != '\0'){
		correcto.push_back(correcta[elemento]);
		elemento++;
	}
	
	return correcto;

}
	
string Pregunta::GetRes4()const{
	string respuesta = "\0";
	int elemento = 0;
	while(res4[elemento] != '\0'){
		respuesta.push_back(res4[elemento]);
		elemento++;
	}
	
	return respuesta;


}
	
string Pregunta::GetRes3()const{
	string respuesta = "\0";
	int elemento = 0;
	while(res3[elemento] != '\0'){
		respuesta.push_back(res3[elemento]);
		elemento++;
	}
	
	return respuesta;


}
	
string Pregunta::GetRes2()const{
	string respuesta = "\0";
	int elemento = 0;
	while(res2[elemento] != '\0'){
		respuesta.push_back(res2[elemento]);
		elemento++;
	}
	
	return respuesta;
	

}
	
string Pregunta::GetRes1()const{
	string respuesta = "\0";
	int elemento = 0;
	while(res1[elemento] != '\0'){
		respuesta.push_back(res1[elemento]);
		elemento++;
	}
	
	return respuesta;



}
	
string Pregunta::GetPregunta()const{
	string preguntas = "\0";
	int elemento = 0;
	while(pregunta[elemento] != '\0'){
		preguntas.push_back(pregunta[elemento]);
		elemento++;
	}
	
	return pregunta;



}
	
void Pregunta::SetPregunta(string preguntita){
	int tam = preguntita.size();
	pregunta = new char [tam+1];
	
	for(int i = 0; i < tam ;i++ ){
		pregunta[i] = preguntita[i];
	
	
	}
	
	pregunta[tam] = '\0';

}
	
void Pregunta::SetRes1(string respuesta){
	int tam = respuesta.size();
	res1 = new char [tam+1];
	
	for(int i = 0; i < tam;i++ ){
		res1[i] = respuesta[i];
	
	
	}
	
	res1[tam] = '\0';

}
	
void Pregunta::SetRes2(string respuesta){
	int tam = respuesta.size();
	res2 = new char [tam+1];
	
	for(int i = 0; i < tam;i++ ){
		res2[i] = respuesta[i];
	
	
	}
	
	res2[tam] = '\0';
}
	
void Pregunta::SetRes3(string respuesta){
	int tam = respuesta.size();
	res3 = new char [tam+1];
	
	for(int i = 0; i < tam;i++ ){
		res3[i] = respuesta[i];
	
	
	}
	
	res3[tam] = '\0';
}
	
void Pregunta::SetRes4(string respuesta){
	int tam = respuesta.size();
	res4 = new char [tam+1];
	
	for(int i = 0; i < tam;i++ ){
		res4[i] = respuesta[i];
	
	
	}
	
	res4[tam] = '\0';
}
	
void Pregunta::SetCorrecta(string correctas){
	int tam = correctas.size();
	correcta = new char [tam+1];
	
	for(int i = 0; i < tam;i++ ){
		correcta[i] = correctas[i];
	
	
	}
	
	correcta[tam] = '\0';

}

	
