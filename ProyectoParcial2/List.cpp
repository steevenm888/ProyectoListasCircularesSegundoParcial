/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/
#include "pch.h"
#include "List.h"
#include "BankAccount.h"
#include "Node.h"


List::List()
{
	first = new Node();
	last = new Node();
	first = NULL;
	last = NULL;
}

void List::insertAccount(BankAccount account) {
	Node *nuevo = new Node(account, NULL, NULL);
	//account.generateAccountNumber();
	if (first == NULL && last == NULL) {
		first = nuevo;
		last = nuevo;
		first->setNext(first);
		first->setLast(last);
	}
	else {
		/*while (accountExists(account.getAccountNumber())) {
			account.generateAccountNumber();
		}*/
		last->setNext(nuevo);
		nuevo->setLast(last);
		nuevo->setNext(first);
		//first->setNext(nuevo);
		last = nuevo;
	}
}

Node * List::search(string accountNumber) {
	Node *aux = new Node();
	aux = first;
	bool flag = false;
	do {
		if (accountNumber.compare(aux->getClient().getAccountNumber())==0) {
			cout << "Se encontro la cunta!" << endl;
			flag = true;
			break;
		}
		aux = aux->getNext();
	} while (aux != first);
	if (flag) {
		return aux;
	}
	else {
		return NULL;
	}
}

bool List::accountExists(string _accountNumber) {
	bool flag = false;
	Node *aux;
	aux = first;
	while (aux->getNext() != first) {
		if (_accountNumber.compare(aux->getClient().getAccountNumber()) == 0) {
			flag = true;
			break;
		}
		aux->setNext(aux->getNext());
	}
	return flag;
}

void List::erase(string accountNumber) {
	Node *aux1, *aux2, *aux3;
	aux1 = search(accountNumber);
	aux2 = aux1->getNext();
	aux3 = aux1->getLast();
	aux3->setNext(aux1->getNext());
	aux2->setLast(aux1->getLast());
	aux1->~Node();
}
void List::print() {
	Node *aux = new Node();
	aux = first;
	//cout << "Lista" << endl;
	if (first != NULL) {
		//cout << "Lista" << endl;
		 do{
			
			aux->getClient().printAccountInformation();
			//aux->setNext(aux->getNext());
			aux = aux->getNext();
		 } while (aux != first);
	}
	else {
		cout << "Lista Vacia" << endl;
	}
}

bool List::isEmpty() {
	if (first == NULL && last == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void List::emptyList() {
	Node *aux = new Node();
	aux = first;
	//cout << "Lista" << endl;
	if (first != NULL) {
		//cout << "Lista" << endl;
		do {
			aux->~Node();
			//aux->setNext(aux->getNext());
			aux = aux->getNext();
		} while (aux != first);
		first = NULL;
		last = NULL;
	}
	else {
		cout << "Lista Vacia" << endl;
	}
}

List::~List()
{
}
