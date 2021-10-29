#include "Concatenacion.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
using namespace std;

std::string concatenacion::concatenacionFinal(int mes, int dia, std::string hora, std::string ip, std::string falla){
  
  std::string lineaFinal = to_string(mes) + " " + to_string(dia) + " " + hora + " " + ip + " " + falla;
  return lineaFinal;
}

int concatenacion::strSinpunto(std::string cadena){
std::string cadenaAux;
	int i=0;
	int count=0;
	while(count < 9){

		if((cadena[i]=='.') || (cadena[i]==':') ){
			i++;	
		}	
		else{
			cadenaAux += cadena[i];
			i++;
			count++;
		}
	}
	cadena=cadenaAux;
  int aux2;
  aux2= stoi(cadena);
  return aux2; 
}
  