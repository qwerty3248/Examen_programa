
#include "Examen.h"
#include "Pregunta.h"
#include "GeneradorAleatorioEnteros.h"
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

const int num_preguntas_cargadas = 2;
const double error = 0.33;

void CargarDatos(istream & in, Examen & e){

	string cad;	
	
	getline(in,cad);
	
	while(!in.eof()){
	
		Pregunta tmp (cad);
		
		e.Aniade(tmp);
		
		getline(in,cad);
		
			
	}
	
	
}


int main (void){

	int preguntas;
	Examen tipo_examen;
	
	ifstream fi ("src/preguntas_examen.cpp");
	
	if(!fi){
		
		cerr<<"error no se puede abrir fichero"<<endl;
		exit(1);
	
	}
	
	cout<<"Buenas al usuario que va a realizar el examen, ahora se le "
	    <<"mostraran las instrucciones de este examen: "<<endl;
	cout<<"-El examen constara del numero de preguntas que usted desee, "    
	    <<"Introduzca cuantas preguntas desea tenga en cuenta que no puede"
	    <<" ser mayor que las preguntas cargadas,"<<num_preguntas_cargadas
	    <<" en este caso."<<endl;
	cout<<"Numero de preguntas para el examen: ";
	cin>>preguntas;   
	cout<<"-Las preguntas son de la a hasta la d en MINUSCULA, para dejar "
	    <<"la pregunta en blanco debes usar el guión -"<<endl
	    <<"-No tiene límite de tiempo."<<endl;
	cout<<"Perfecto, ahora procederemos a cargar las preguntas"<<endl;
	cout<<"Proceso de carga comenzado... "<<endl;    
	
	CargarDatos(fi, tipo_examen);
	
	fi.close();
	
	for(int i = 1; i <= num_preguntas_cargadas; i++){
		
		cout <<"Progreso: " <<i*100/num_preguntas_cargadas << "%\r";
        cout.flush(); // Forzar la salida en el buffer sin 
        				   //agregar un salto de línea
        
        usleep(500000);//sleep en milisegundos
		
	}
	cout<<endl;
	
	cout<<"PROCESO DE CARGA EXITOSA"<<endl;
	cout<<"Ahora empezemos con el test, SUERTE!!!"<<endl;
	GeneradorAleatorioEnteros numeros(0,num_preguntas_cargadas-1);
	int * aleatorios = new int [preguntas];
	for(int i = 0 ; i < preguntas; i++){
		aleatorios[i] = numeros.Siguiente();
	}
	//ahora comprobamos si son todos distintos
	bool repetido = false;

	for (int i = 0; i < preguntas; i++) {
		for (int k = i + 1; k < preguntas; k++) {
		    if (aleatorios[i] == aleatorios[k]) {
		        repetido = true;
		        break;
		    }
		}

		if (repetido) {
		    aleatorios[i] = numeros.Siguiente();
		    i = -1; // Reiniciamos el bucle exterior desde el principio
		    repetido = false;
		}
	}

	//ya estan todos los aleatorios distintos
	//donde se van a almacenar las respuestas
	char * respuestas = new char[preguntas];
	char aux1;
	cout<<"El examen va a comenzar en... "<<endl;
	cout<<"3"<<endl;
	sleep(1);
	cout<<"2"<<endl;
	sleep(1);
	cout<<"1"<<endl;
	sleep(1);
	cout<<"YA"<<endl;
	sleep(1);
	for (int i = 0 ; i < preguntas; i++){
		
		Pregunta aux;
		aux = tipo_examen[aleatorios[i]];
		//pregunta
		cout<<aux.GetPregunta()<<endl;
		//las 4 respuestas
		cout<<aux.GetRes1()<<endl;
		cout<<aux.GetRes2()<<endl;
		cout<<aux.GetRes3()<<endl;
		cout<<aux.GetRes4()<<endl;
		
		do{
			cout<<"Respuesta: ";
			cin>>aux1;
		}while(aux1 != 'a' && aux1 != 'b' && aux1 != 'c' && 
		       aux1 != 'd' && aux1 != '-');
		
		respuestas[i] = aux1;
		aux1 = '\0';
		     
		
	}
	int fallos[preguntas];
	int posicion_fallos = 0;
	cout<<"Perfecto ahora vamos a corregir esas respuestas JIJIJI..."<<endl;
	int aciertos=0,blancas=0,fallos2=0;
	for(int i = 0 ; i < preguntas; i++){
		Pregunta aux;
		aux = tipo_examen[aleatorios[i]];
		if(aux.GetCorrecta() == to_string(respuestas[i])){
			aciertos++;
		}else if(respuestas[i] == '-'){
			blancas++;
		}else{
			fallos2++;
			fallos[posicion_fallos] = i;
			posicion_fallos++;
		}
	
	
	}
	double nota = ((aciertos*10)/num_preguntas_cargadas)-(fallos2*error);
	
	cout<<"Sus aciertos han sido: "<<aciertos<<endl;
	cout<<"Sus fallos han sido: "<<fallos2<<endl;
	cout<<"Sus blancas han sido: "<<blancas<<endl;
	cout<<"Su nota es: "<<nota<<endl;
	cout<<"El error puesto en este examen ha sido de "<<error<<endl;
	cout<<"Para cambiar el error debe avisar al propietario del pc jiji."
	    <<endl;
	    
	if(fallos != 0){
		cout<<"Ahora vamos con esos fallos: "<<endl;
		for(int i = 0 ; i < posicion_fallos; i++ ){
			
			Pregunta aux;
			aux = tipo_examen[aleatorios[fallos[i]]];
			//pregunta 
			cout<<aux.GetPregunta()<<endl;
			//las 4 posibles respuestas
			cout<<aux.GetRes1()<<endl;
			cout<<aux.GetRes2()<<endl;
			cout<<aux.GetRes3()<<endl;
			cout<<aux.GetRes4()<<endl;	
			//respuesta correcta
			cout<<"La respuesta correcta sería la "
			    << aux.GetCorrecta()<<endl;
			sleep(4);
			
		}
	
	
	
	}    

	cout<<"Agradecimientos nuevamente a Marta Pedraza Pastor =)"<<endl
	    <<"Gracias por hacer el examen"<<endl;


	delete[] respuestas;
	delete[] aleatorios;

}



