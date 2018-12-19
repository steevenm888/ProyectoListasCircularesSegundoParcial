/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/
#pragma once
#include"List.h"
#include<iostream>
#include<string>
using namespace std;
class Bank
{
private:
	List *accounts;
public:
	Bank();
	void deposit(string, double);
	void withdrawal(string, double);
	void transaction(string, string, double);
	~Bank();
};

