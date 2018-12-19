/*UNIVERSIDAD DE LAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)*/
#pragma once
#include<string>
#include<iostream>
#include"Person.h"
using namespace std;
class BankAccount
{
private:
	Person accountHolder;
	string accountNumber;
	long password;
	double balance;
	string status;
public:
	BankAccount();
	void deposit(double);
	void withdrawal(double);
	void printAccountInformation();
	void changePassword();
	void generateAccountNumber();
	bool passwordVerification();
	void setAccountHolder(Person _accountHolder) { accountHolder = _accountHolder; }
	void setAccountNumber(string _accountNumber) { accountNumber = _accountNumber; }
	void setPassword(int _password) { password = _password; }
	void setBalance(double _balance) { balance = _balance; }
	void setStatus(string _status) { status = _status; }
	void getAccountData();
	Person getAccountHolder() { return accountHolder; }
	string getAccountNumber() { return accountNumber; }
	int getPassword() { return password; }
	double getBalance() { return balance; }
	string getStatus() { return status; }
	~BankAccount();

};

