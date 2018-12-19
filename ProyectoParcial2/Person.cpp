/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/

#include "pch.h"
#include "Person.h"
#include <Validations.h>
#include<conio.h>


Person::Person()
{
}

void Person::getData() {
	int opc = 0;
	cout << "Ingresar los siguientes datos" << endl;
	cout << "Primer nombre: ";
	
	cin >> firstName;
	cin.ignore();
	while (!isWholeChainLetter((char *)firstName.c_str())) {
		cout << "Ingrese solo letras!!! Vuelva a ingresar: ";
		cin >> firstName;
	}
	cout << "Segundo nombre: ";
	cin >> secondName;
	cin.ignore();
	while (!isWholeChainLetter((char *)secondName.c_str())) {
		cout << "Ingrese solo letras!!! Vuelva a ingresar: ";
		cin >> secondName;
	}
	cout << "Primer apellido: ";
	cin >> lastName1;
	cin.ignore();
	while (!isWholeChainLetter((char *)lastName1.c_str())) {
		cout << "Ingrese solo letras!!! Vuelva a ingresar: ";
		cin >> lastName1;
	}
	cout << "Segundo apellido: ";
	cin >> lastName2;
	cin.ignore();
	while (!isWholeChainLetter((char *)lastName2.c_str())) {
		cout << "Ingrese solo letras!!! Vuelva a ingresar: ";
		cin >> lastName2;
	}
	cout << "Cedula de identidad: ";
	cin >> id;
	cin.ignore();
	while (!verificarCedula((char *)id.c_str()))
	{
		cout << "Cedula invalida!!! Ingrese de nuevo: ";
		cin >> id;
	}
	cout << "Dia de nacimiento: ";
	//cin.ignore();
	birthDay = getNumber();
	while (birthDay < 0 || birthDay > 30) {
		cout << "Ingrese valores del 1-30!!! Ingrese de nuevo: ";
		birthDay = getNumber();
		//cin.ignore();
	}
	cout << "Mes de nacimiento: ";
	//cin.ignore();
	birthMonth = getNumber();
	fflush(stdin);
	while (birthMonth < 0 || birthMonth > 12) {
		cout << "Ingrese valores del 1-12!!! Ingrese de nuevo: ";
		birthMonth = getNumber();
		//cin.ignore();
	}
	cout << "Year de nacimiento: ";
	//cin.ignore();
	birthYear = getNumber();
	while (birthYear < 1800 || birthYear > 2018) {
		cout << "Ingrese valores del 1800-2018!!! Ingrese de nuevo: ";
		
		birthYear = getNumber();
		//cin.ignore();
	}
	cout << "Direccion: ";
	//cin.ignore();
	getline(cin,address);
	cout << "Numero de telefono: ";
	//cin.ignore();
	cin >> phoneNumber;
	while (isWholeChainLetter((char *)phoneNumber.c_str()) || phoneNumber.length()!=10) {
		cout << "Ingrese solo numeros!!! Vuelva a ingresar: ";
		cin >> phoneNumber;
	}
	cout << "Estado civil: ";
	//cin.ignore();
	fflush(stdin);
	cin >> maritalStatus;
	cout << "Genero: " << endl << "1. Masculino" << endl << "2. Femenino"<<endl;
	//fflush(stdin);
	cin.ignore();
	opc = getNumber();
	while (opc < 1 || opc > 2) {
		cout << "Opcion invalida!!! Ingrese de nuevo: ";
		//cin.ignore();
		opc = getNumber();
	}
	if (opc == 1) {
		gender = true;
	}
	else
	{
		gender = false;
	}
	fflush(stdin);
}

Person::~Person()
{
}
