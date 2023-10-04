/***************************************************************************/
// Clase: GeneradorAleatorioEnteros
/*
	Sirve para generar números aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	1) GeneradorAleatorioEnteros()
	   		El primero no tiene parámetros y establece que únicamente se 
			van a generar ceros y unos (este constructor llama al segundo). 
	2) GeneradorAleatorioEnteros(int min, int max)
		El segundo tiene dos parámetros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Finalmente, el método 
	
		int Siguiente()
	
	devolverá un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/
#include "GeneradorAleatorioEnteros.h"
#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla

using namespace std;

	
long long GeneradorAleatorioEnteros::Nanosec(){
       return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
     /************************************************************************/ 
	
		
	GeneradorAleatorioEnteros::GeneradorAleatorioEnteros() : 
	GeneradorAleatorioEnteros(0, 1) 
	{ }
	
    /************************************************************************/  
GeneradorAleatorioEnteros::GeneradorAleatorioEnteros(int min, int max) {
	
	       const int A_DESCARTAR = 70000;
	       // ACM TOMS Volume 32 Issue 1, March 2006
		
	       auto semilla = Nanosec();
	       generador_mersenne.seed(semilla);
	       generador_mersenne.discard(A_DESCARTAR);
	       distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
/************************************************************************/
	
	int GeneradorAleatorioEnteros::Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
/************************************************************************/


/////////////////////////////////////////////////////////////////////////////

