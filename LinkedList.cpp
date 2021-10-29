#include "LinkedList.h"
#include "strnatcmp.h"
LinkedList::LinkedList()
{
	first = NULL;
	last = NULL;
	sorted = NULL;
}

void LinkedList::create(int index, int Mes, int Dia, string Hora, string ip, string falla)
{
	//creamos una variable temporal para cambiar el link entre nodos
	node *temp1 = new node;
	temp1->mes = Mes;
	temp1->dia = Dia;
	temp1->hora = Hora;
	temp1->ip = ip;
	temp1->falla = falla;
	temp1->next = NULL;

	//en caso de que la lista esté vacía
	if (index == 0)
	{
		temp1->next = first;
		first = temp1;
		n++;
		return;
	}
	else //en el caso en que esté en medio o al final
	{
		//creamos un nodo temporal para cambiar el link entre nodos
		node *temp2 = first;
		for (int i = 0; i < index - 1; i++) //llegamos hasta el nodo antes del index que buscamos
		{
			temp2 = temp2->next;
		}

		//sustituimos el link entre el nodo temporal y el nodo a eliminar
		temp1->next = temp2->next;
		temp2->next = temp1;
		n++;
	}
}

//add añade un nodo al ultimo
void LinkedList::add(int Mes, int Dia, string Hora, string ip, string falla)
{
	if (!first)
	{
		// The list is empty
		first = new node;
		first->mes = Mes;
		first->dia = Dia;
		first->hora = Hora;
		first->ip = ip;
		first->falla = falla;
		first->next = NULL;
		last = first;
	}
	else
	{
		// The list isn't empty
		if (last == first)
		{
			// The list has one element
			last = new node;
			last->mes = Mes;
			last->dia = Dia;
			last->hora = Hora;
			last->ip = ip;
			last->falla = falla;
			last->next = NULL;
			first->next = last;
		}
		else
		{
			// The list has more than one element
			node *insdata = new node;
			insdata->hora = Hora;
			insdata->dia = Dia;
			insdata->mes = Mes;
			insdata->ip = ip;
			insdata->falla = falla;
			insdata->next = NULL;
			last->next = insdata;
			last = insdata;
		}
	}
	n++;
}

//metodo que añade nuevos nodos por medio de un nodo creado
void LinkedList::add(node *newnode)
{
	if (!first)
	{
		// The list is empty
		first = new node;
		first->mes = newnode->mes;
		first->dia = newnode->dia;
		first->hora = newnode->hora;
		first->ip = newnode->ip;
		first->falla = newnode->falla;
		first->next = NULL;
		last = first;
	}
	else
	{
		// The list isn't empty
		if (last == first)
		{
			// The list has one element
			last = new node;
			last->mes = newnode->mes;
			last->dia = newnode->dia;
			last->hora = newnode->hora;
			last->ip = newnode->ip;
			last->falla = newnode->falla;
			last->next = NULL;
			first->next = last;
		}
		else
		{
			// The list has more than one element
			node *insdata = new node;
			insdata->hora = newnode->hora;
			insdata->dia = newnode->dia;
			insdata->mes = newnode->mes;
			insdata->ip = newnode->ip;
			insdata->falla = newnode->falla;
			insdata->next = NULL;
			last->next = insdata;
			last = insdata;
		}
	}
	n++;
}

void LinkedList::printlist()
{
	node *t = first;
	while (t != NULL)
	{
		cout << " " << t->mes << " " << t->dia << " " << t->hora << " " << t->ip << " " << t->falla << endl;
		t = t->next;
	}
	std::cout << "\n";
}

int LinkedList::getLength(node *first)
{
	node *cur = first;
	int i = 0;
	for (; cur != NULL; cur = cur->next)
	{
		i++;
	}
	return i;
}

/// MERGE SORT
// REFERENCIA: https://gist.github.com/hnguyen091188/efa43431593f2370007e

void LinkedList::mergeSort(node *&first)
{
	if (first->next != NULL) //check the condition if this is the last node, do nothing
	{
		node *head1 = new node;
		node *head2 = first; //assign head to head 2. Head 2 will point to second half of the linked list
		int len = getLength(first);
		for (int i = 0; i < len / 2; i++) //use for loop to increment the pointer 2 to the mid poin in linked list
		{
			head1 = head2;		 // assign head1 to any node head2 point to,
			head2 = head2->next; //in order to put NULL terminate for the first half of the linked list
		}
		head1->next = NULL; //terminate first half of the linked list
		head1 = first;		//reposition head1 to the beginning of linked list, also the first node of the first half
		mergeSort(head1);
		mergeSort(head2);
		first = merge(head1, head2);
	}
}

node *LinkedList::merge(node *&head1, node *&head2)
{
	node *newHead;
	//Base case: return the other half if  one of them is NULL
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	//compare the value
	bool comprueba = compareNat(head1->ip, head2->ip);
	if (comprueba == true)
	{											   //si es menor el h1 que h2
		newHead = head1;						   //assign the newHead to the Node has smaller value
		newHead->next = merge(head1->next, head2); //recall the function to find the next Node
	}
	else
	{
		newHead = head2;
		newHead->next = merge(head1, head2->next);
	}

	return newHead;
}

/// BUSQUEDA SECUENCIAL DE UN RANGO DE ENTRADAS DE IP
LinkedList LinkedList::rangoIP(LinkedList bitacora, string ip1, string ip2) 
{
	//creamos una nueva lista en donde guardaremos el rango de entradas solicitado
	LinkedList nuevaLista;
	node *current = bitacora.first; //agarra el head
	//for loop que pasa por la lista actual verificando que la ip está en el nodo actual
	while (current->next != NULL)
	{
		if (current->ip == ip1) //encontramos la ip1 en el nodo actual
		{
			//instrucciones a partir de que encuentra la primer ip
			while (current->ip != ip2) //añadimos la informacion de los nodos hasta que encuentre la nueva ip
			{
				nuevaLista.add(current); //va pal texto
        current = current->next;
			}
			//al encontrar el nodo con ip2 regresamos la lista con el rango solicitado
			nuevaLista.add(current); //va pal texto
			return nuevaLista;
		}
		else //si no se encuentra la ip1 en el nodo actual entonces seguimos buscando
		{
			current = current->next;
		}
	}
	return nuevaLista;
}

////////////////////////////////////////////////////////////////////////////////////
//*************************METODOS NO IMPLEMENTADOS***************************
////////////////////////////////////////////////////////////////////////////////////

/// BINARY SEARCH (NO IMPLEMENTADA EN MAIN)
/*
// function to find out middle element
node* LinkedList::middle(node* start, node* last)
{
    if (start == NULL)
        return NULL;
 
    node* slow = start;
    node* fast = start -> next;
 
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
   return slow;
}
 
// Function for implementing the Binary GEEKSFORGEEKS
// Search on linked list
node* LinkedList::binarySearch(node *head, string value)
{
    node* start = head;
    node* last = NULL;
    const int len = value.length() + 1;
    // declaring character array
    char char_array[len];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, value.c_str());
 
    do
    {
        // Find middle
        node* mid = middle(start, last);

        //convertimos a char arr la ip actual para comparar
        const int len = mid->ip.length()+ 1;
        char char_arraycur[len];
        strcpy(char_arraycur, mid->ip.c_str());
        
        //sale 1 si char_array es MAYOR a char_arraycur
        //sale 0 si char_array es IGUAL a char_arraycur
        //sale -1 si char_array es MENOR a char_arraycur
        int result = strcmp(char_array, char_arraycur);

        // If middle is empty
        if (mid == NULL)
            return NULL;
 
        // If value is present at middle
        // regresamos el nodo
        if (mid->ip == value)
            return mid;
 
        // If value is more than mid
        else if (result == 1)
            start = mid -> next;
 
        // If the value is less than mid.
        else
            last = mid;
 
    } while (last == NULL ||
             last != start);
 
    // value not present
    return NULL;
} 

*/

//metodo para obtener el ultimo nodo
/*
void LinkedList::getLastNode(node* first) {
  node* current = first; // Initialize current
  while (current->next != NULL)
  {
      current = current->next;
  }
  last = current;
}
*/
/*
//función que obtiene los datos del nodo en la posición indicada
T read(int index)
{
	if (index == 0)
	{
		// Get the first element
		return this->first->data;
	}
	else
	{
		// Get the index'th element
		node* curr = this->first;
		for (int i = 0; i < index; ++i)
		{
			curr = curr->next;
		}
		return curr->data;
	}
}

T operator[](int index)
{
	return read(index);
}
};*/