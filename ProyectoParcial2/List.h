/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/
#pragma once
#include "Node.h"
#include "BankAccount.h"
class List
{
private:
	
	Node *first,*last;
public:
	List();
	void insertAccount(BankAccount account);
	void erase(string accountNumber);
	Node * search(string accountNumber);
	void print();
	void emptyList();
	//void interchange(string _id1, string _id2);
	bool isEmpty();
	bool accountExists(string accountNumber);
	Node * getFirst() { return first; }
	Node * getLast() { return last; }
	void setFirst(Node *_first) { first = _first; }
	void setLast(Node *_last) { last = _last; }
	~List();
};

