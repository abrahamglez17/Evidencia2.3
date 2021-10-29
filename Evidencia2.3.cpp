/* Brenda Cristina Yépiz Moreno  - A01633793
   José Abraham González Navarro - A00369832
   Stephanie Ruiz Díaz           - A00227730

  Programación de estructuras de datos
  Prof. Carlos Ventura
  ITESM Campus Guadalajara
  10/10/2021

  "Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)"

  Realiza una aplicación en C++ en equipo donde se lea el archivo bitacora.txt y se guarde en un vector, tome un rango de IP's del usuario y registre el resultado de estas IP's en un archivo nuevo, además mostrarlo en consola.
*/

//headers, archivos y librerias 
#include "Ordenamiento.h" 
#include "Concatenacion.h"
#include "LinkedList.h"
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	string linea;
	int i = 0, j = 0, diaI, mesI, diaF, mesF, indexI, indexF, auxI, imes, idia, aux, k, p;
	vector<string> listaVieja;
	string line, output;
	int month, IPaux, day, espacios;
	LinkedList lista; //<- LISTA LINKEADA

	ifstream oldfile; //leyendo archivo existente
	ofstream myfile;  //leyendo archivo nuevo

	oldfile.open("bitacora.txt");
	myfile.open("resultadoIP.txt");
	//revisando si se abre correctamente el archivo o no se está leyendo
	if (oldfile.fail() || myfile.fail())
	{
		cout << "Input or output file failed";
	}

	while (getline(oldfile, line))
	{
		listaVieja.push_back(line);

		string m = line.substr(0, 3);
		month = Ordenamiento::mesAint(m); //convertimos a integer
		//mes.push_back(month); //ingresamos mes

		string d = line.substr(4, 2);
		day = stoi(d);
		//dia.push_back(day); //ingresamos dia

		string hour = line.substr(7, 8);
		//hora.push_back(hour);  //ingresamos hora

		//ingresamos la ip y la ordenamos por puntos
		int auts;
		for (int j = 16; j <= (16 + 25); j++)
		{
			if (line.substr(j, 1) == " ")
			{
				auts = j;
				break;
			}
		}
		auts = auts - 16;

		/*stringip nos guarda en string y será el que imprimamos, el ip longlong nos ordena*/
		string IP = line.substr(16, auts);
		//ip.push_back(IP); //vector con strings de IP

		int espacios = m.length() + 1 + d.length() + 1 + hour.length() + 1 + IP.length() + 1;
		string failure = line.substr(espacios, line.length());
		//falla.push_back(failure);

		lista.add(month, day, hour, IP, failure);
	}

	//ORDENAR LAS ENTRADAS POR DIRECCION IP
	lista.mergeSort(lista.first);
	//*********************pruebas de algoritmo de busqueda

	LinkedList nuevaLista;

	//rango de IP inicial y final 
	string IPin = "108.57.27.85:5491";
	string IPfin = "118.15.416.57:4486";
	/*
	cout<<"Digite la dirección de IP inicial del rango: ";
	cin>>IPin;
	cout<<"\nDigite la dirección de IP final del rango: ";
	cin>>IPfin; */

	nuevaLista = lista.rangoIP(lista, IPin, IPfin);
	nuevaLista.printlist();

	node* head = nuevaLista.first;

	//concatenando elementos
	for (int i = 0; i < nuevaLista.getLength(nuevaLista.first); i++) {
		output = concatenacion::concatenacionFinal(head->mes, head->dia, head->hora, head->ip, head->falla);
		myfile << output << endl;
		head = head->next;
	}
	//cerramos archivos
	oldfile.close();
	myfile.close();
}