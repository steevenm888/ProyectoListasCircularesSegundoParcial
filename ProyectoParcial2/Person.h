/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/#pragma once
#include<string>
#include<iostream>

using namespace std;
class Person
{
private:
	string firstName;
	string secondName;
	string lastName1;
	string lastName2;
	string id;
	string address;
	string phoneNumber;
	char maritalStatus;
	int birthDay;
	int birthMonth;
	int birthYear;
	bool gender=false;
public:
	Person();
	~Person();
	void setFirstName(string _firstName) { firstName = _firstName; }
	void setSecondName(string _secondName) { secondName = _secondName; }
	void setLastName1(string _lastName1) { lastName1 = _lastName1; }
	void setLastName2(string _lastName2) { lastName2 = _lastName2; }
	void setId(string _id) { id = _id; }
	void setAddress(string _address) { address = _address; }
	void setPhoneNumber(string _phoneNumber) { phoneNumber = _phoneNumber; }
	void setMaritalStatus(char _maritalStatus) { maritalStatus = _maritalStatus; }
	void setBirthDay(int _birthDay) { birthDay = _birthDay; }
	void setBirthMonth(int _birthMonth) { birthMonth = _birthMonth; }
	void setBirthYear(int _birthYear) { birthYear = _birthYear; }
	void setGender(bool _gender) { gender = _gender; }
	void getData();
	void printPerson();
	string getFirstName() { return firstName; }
	string getSecondName() { return secondName; }
	string getLastName1() { return lastName1; }
	string getLastName2() { return lastName2; }
	string getId() { return id; }
	string getAddress() { return address; }
	string getPhoneNumber() { return phoneNumber; }
	char getMaritalStatus() { return maritalStatus; }
	int getBirthDay() { return birthDay; }
	int getBirthMonth() { return birthMonth; }
	int getBirthYear() { return birthYear; }
	bool getGender() { return gender; }
};

