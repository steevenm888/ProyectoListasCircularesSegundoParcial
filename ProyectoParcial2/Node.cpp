/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/
#include "pch.h"
#include "Node.h"
#include "BankAccount.h"


Node::Node()
{
	account = BankAccount();
	last = NULL;
	next = NULL;
	
}
Node::Node(BankAccount _account, Node *_last, Node *_next) {
	account = _account;
	last = _last;
	next = _next;
}

Node::~Node()
{
}
