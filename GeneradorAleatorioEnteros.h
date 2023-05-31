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

#ifndef GENERADOR_ALEATORIO_ENTEROS
#define GENERADOR_ALEATORIO_ENTEROS

#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla

using namespace std;

/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec();
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros();
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max);
	
	/************************************************************************/
	
	int Siguiente();
	
	/************************************************************************/

};
/////////////////////////////////////////////////////////////////////////////
#endif
