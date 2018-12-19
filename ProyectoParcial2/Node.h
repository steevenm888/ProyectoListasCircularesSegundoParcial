/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/
#pragma once
#include "BankAccount.h"
#include <iostream>
class Node
{
private:
	BankAccount account;
	Node *last;
	Node *next;
public:
	Node();
	Node(BankAccount, Node *, Node *);
	void setClient(BankAccount _client) { account = _client; }
	void setLast(Node *_last) { last = _last; }
	void setNext(Node *_next) { next = _next; }
	BankAccount getClient() { return account; }
	Node * getLast() { return last; }
	Node * getNext() { return next; }
	~Node();
};

