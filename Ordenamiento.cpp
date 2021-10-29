#include "Ordenamiento.h"
#include "LinkedList.h"
using namespace std;

int Ordenamiento::mesAint(string Mes)
{
	int result = (Mes == "Jun") ? 6 : (Mes == "Jul") ? 7 : (Mes == "Aug") ? 8 : 	(Mes == "Sep") ? 9 : (Mes == "Oct") ? 10 :  (Mes == "Nov") ? 11 : (Mes == "Dec") ? 12 : 0;

	return result;  
}

