#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;



int main (int argc, char ** argv){



	if(argc != 3){
	
			cerr<<"argumentos mal"<<endl;
			exit(1);
	
	
	}

	ifstream fi (argv[1]);
	
	if (!fi){
		
		cerr<<"fallo arch entrada"<<endl;
		exit(1);
	
	
	}
	
	ofstream fo (argv[2]);
	
	if (!fo){
		
		cerr<<"fallo arch salida"<<endl;
		exit(1);
	
	
	}
	
	
	int contador_lineas = 0;
	
	string cad;
	
	string tmp = "";
	
	getline(fi,cad);
	
	while(!fi.eof()){
		
		contador_lineas++;
		
		tmp += cad + '*';
		
		if(contador_lineas == 6){
			
			contador_lineas = 0;
			
			fo << tmp << endl;
			
			tmp = "";
		
		}
		
		getline(fi,cad);	
	}

	fi.close();
	
	fo.close();

	

}


