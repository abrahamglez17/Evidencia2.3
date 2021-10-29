#ifndef NATRUAL_SORT_HPP
#define NATURAL_SORT_HPP
#endif

#ifndef STRNATCMP_HPP
#define STRNATCMP_HPP
#endif

#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

struct node
{
	node *next;
	int mes, dia;
	string hora, ip, falla;
};

class LinkedList
{
public:
	node *first; //primer nodo de la lista
	node *last;
	node *ref1;
	node *ref2;
	node *sorted;
	int n = 0;

	//metodos
	LinkedList();

	//CREAR NODOS
	void create(int index, int Mes, int Dia, string Hora, string ip, string falla);
	void add(int Mes, int Dia, string Hora, string ip, string falla);
	void add(node *newnode);

	void read();   //LEE LOS DATOS DEL
	void update(); //UPDATE DE INFO DEL NODO
	void del();	   //ELIMINAR NODOS
  void saveTxt();

	void printlist();

	int getLength(node *first);

	//METODOS MERGE SORT
	void mergeSort(node *&first);
	node *merge(node *&head1, node *&head2);

	//METODOS BUSQUEDA BINARIA (NO IMPLEMENTADO EN MAIN)
	node *binarySearch(node *head, string value);
	node *middle(node *start, node *last);

	//METODO QUE GENERA UNA LISTA A CON RANGO DE IP SOLICITADO
	LinkedList rangoIP(LinkedList bitacora, string ip1, string ip2);
};