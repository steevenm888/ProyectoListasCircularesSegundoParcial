/*UNIVERSIDAD DE LAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)*/
#include "pch.h"
#include "BankAccount.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include"Person.h"
#include <stdio.h>
#include <Validations.h>

using namespace std;

BankAccount::BankAccount()
{
	accountHolder = Person();
	balance = 0;
	status = "Activo";
	//accountHolder.getData();
}

void BankAccount::deposit(double amount) {
	balance = balance + amount;
	cout << "Deposito realizado con exito!" << endl;
	cout << "Saldo actual: " << balance << endl;
}

void BankAccount::withdrawal(double amount) {
	if (balance >= amount) {
		balance = balance - amount;
		cout << "Retiro realizado con exito!" << endl;
		cout << "Saldo actual: " << balance << endl;
	}
	else {
		cout << "Fondos insuficientes" << endl;
	}
}

void BankAccount::printAccountInformation() {
	cout << " ------------------------------------------------" << endl;
	cout << "            Informacion de la cuenta            " << endl;
	cout << " ------------------------------------------------" << endl;
	cout << "Nombre del titular: " <<accountHolder.getFirstName() << " " << accountHolder.getLastName1()<<endl;
	cout << "Numero de cuenta: " << accountNumber << endl;
	cout << "Cedula de Identidad: " << accountHolder.getId() << endl;
	cout << "Saldo actual: " << balance << endl;
	cout << "Estado de cuenta: " << status << endl;
	cout << "Fecha de Nacimiento: " << accountHolder.getBirthDay() << "/ " << accountHolder.getBirthMonth() << " / " << accountHolder.getBirthYear() << endl;
	cout << "Telefono: " << accountHolder.getPhoneNumber() << endl;
	cout << "Direccion: " << accountHolder.getAddress() << endl;
	cout << " ------------------------------------------------" << endl;
}
void BankAccount::changePassword() {
	int pin, cont=0,pass1,pass2;
	cout << "Cambio Contrasena" << endl;
	cout << "Ingrese su contrasena actual: " << endl;
	cin >> pin;
	while (pin != password && cont<=3) {
		cout << "Contrasena incorrecta, digite de nuevo" << endl;
		cin >> pin;
	}
	if (cont == 3) {
		cout << "Excedio su numero de intentos!" << endl;
	}
	else {
		cout << "Ingrese su nueva contrasena" << endl;
		cin >> pass1;
		cout << "Ingrese su nueva contrasena" << endl;
		cin >> pass2;
		while (pass1 != pass2) {
			cout << "Las contrasenas no coinciden, digite de nuevo!" << endl;
			cout << "Ingrese su nueva contrasena" << endl;
			cin >> pass1;
			cout << "Ingrese su nueva contrasena" << endl;
			cin >> pass2;
		}
		password = pass1;
		cout << "Contrasena cambiada con exito" << endl;
	}
}

void BankAccount::generateAccountNumber() {
	long _accountNumber;
	srand(time(NULL));
	_accountNumber = 11 + rand() % 99;
	char aux[3];
	_itoa_s(_accountNumber,aux,10);
	accountNumber = string(aux);
	cout<<"Numero de cuenta: "<<accountNumber<<endl;
}

void BankAccount::getAccountData() {
	bool flag = false;
	accountHolder.getData();
	cout << "Ingrese los datos para su cuenta" << endl;
	do{
		cout << "Contrasena (4 digitos): ";
		//cin.ignore();
		password = getNumber();
		cout << password<<endl;
		cout << flag << endl;
		//cin >> password;
		//cin.ignore();
		//fflush(stdin);
		flag = passwordVerification();
	} while (flag);
	
}

bool BankAccount::passwordVerification() {
	int cont = 1;
	long num;
	bool flag = false;
	num = password;
	while (num / 10 > 0)
	{
		num = num / 10;
		cont++;
	}
	if (cont > 4 || cont < 4) {
		flag = true;
		return flag;
	}
}

BankAccount::~BankAccount()
{
}
