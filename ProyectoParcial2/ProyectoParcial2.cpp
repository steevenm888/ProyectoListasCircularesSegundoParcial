/*UNIVERSIDAD DE LAAS FUERZAS ARMADAS
Integrantes: Shakira Cofre, Esteban Molina y Ismael Moreno
Fecha de creacion:02/12/2018		Fecha de modificacion:02/12/2018, 10/12/2018
Problema: Crear un programa de registro de clientes, almacenando los en listas doblemente enlazadas
circulares con distintas funciones(insertar,eliminar,buscar,imprimir)
*/

#include "pch.h"
#include <Validations.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>
#include <shellapi.h>
#include <ShellScalingApi.h>
#include "List.h"
#include "Node.h"
#include "Person.h"
#include "BankAccount.h"
using namespace std;
#pragma comment(lib, "shell32.lib")

//Funciones que van en el menu
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = 0;
	lpCursor.dwSize = 1;
	SetConsoleCursorInfo(hcon, &lpCursor);
	SetConsoleCursorPosition(hcon, dwPos);
}

void tecla()
{
	fflush(stdin);
	int letra = getchar();
	if (letra == 104)
	{
		ShellExecute(NULL, TEXT("open"), TEXT("Manual.chm"), NULL, NULL, SW_SHOWNORMAL);
	}

}

//Funciones 
List *bank = new List();
void insertIntoBank() {
	BankAccount *auxA = new BankAccount();
	Node *aux = new Node();
	auxA->getAccountData();
	auxA->generateAccountNumber();
	aux->setClient(*auxA);
	bank->insertAccount(*auxA);
}

void searchList() {
	int aux1;
	char _bankAccount1[3];
	string _bankAccount;
	Node *aux = new Node();
	cout << "Ingrese el numero de cuenta que desea buscar: ";
	aux1 = getNumber();
	_itoa_s(aux1, _bankAccount1, 10);
	_bankAccount = string(_bankAccount1);
	aux = bank->search(_bankAccount);
	if (aux == NULL) {
		cout << "No existe la cuenta!!!" << endl;
	}
	else 
	{
		aux->getClient().printAccountInformation();
	}
	
}

void erase() {
	int aux1;
	char _bankAccount1[3];
	string _bankAccount;
	Node *aux = new Node();
	cout << "Ingrese el numero de cuenta que desea eliminar: ";
	aux1 = getNumber();
	_itoa_s(aux1, _bankAccount1, 10);
	_bankAccount = string(_bankAccount1);
	bank->erase(_bankAccount);
}

// Menu

void menuBase() {

	gotoxy(57, 1);
	cout << "MENU";
	gotoxy(15, 4);
	cout << "EXTRAS";
	gotoxy(55, 4);
	cout << "BANCO";
	gotoxy(10, 5);
	for (int i = 0; i < 95; i++) {
		cout << "-";
	}
	gotoxy(100, 21);
	cout << "Exit";
	cout << endl << endl << endl;
}
void subMenuRecursividad() {
	gotoxy(57, 1);
	cout << "MENU";
	gotoxy(15, 4);
	cout << "EXTRAS";
	gotoxy(55, 4);
	cout << "BANCO";
	gotoxy(10, 5);
	for (int i = 0; i < 95; i++) {
		cout << "-";
	}
	gotoxy(15, 6);
	cout << "IMAGEN";
	gotoxy(15, 8);
	cout << "MARQUESINA";
	gotoxy(100, 21);
	cout << "Exit";
	cout << endl << endl << endl;

}
void subMenuVectores() {
	gotoxy(57, 1);
	cout << "MENU";
	gotoxy(15, 4);
	cout << "EXTRAS";
	gotoxy(55, 4);
	cout << "BANCO";
	gotoxy(10, 5);
	for (int i = 0; i < 95; i++) {
		cout << "-";
	}
	gotoxy(55, 6);
	cout << "INGRESAR CUENTA DE BANCO";
	gotoxy(55, 8);
	cout << "BUSCAR CUENTA DE BANCO";
	gotoxy(55, 10);
	cout << "ELIMINAR CUENTA DE BANCO";
	gotoxy(55, 12);
	cout << "IMPRIMIR CUENTAS DE BANCO";
	gotoxy(55, 14);
	cout << "GUARDAR CUENTAS DE BANCO";
	gotoxy(55, 16);
	cout << "VACIAR BANCO";
	gotoxy(100, 21);
	cout << "Exit";
	cout << endl << endl << endl;

}

void highlightHorizontal(int x, int y) {
	switch (y)
	{
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		if (x == 15) {
			cout << "IMAGEN";
		}
		else {
			cout << "INGRESAR CUENTA DE BANCO";
		}
		break;
	case 8:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		if (x == 15) {
			cout << "MARQUESINA";
		}
		else {
			cout << "BUSCAR CUENTA DE BANCO";
		}
		break;
	case 10:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		cout << "ELIMINAR CUENTA DE BANCO";
		break;
	case 12:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		cout << "IMPRIMIR CUENTAS DE BANCO";
		break;
	case 14:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		cout << "GUARDAR CUENTAS DE BANCO";
		break;
	case 16:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		cout << "VACIAR BANCO";
		break;
	default:
		break;
	}

}

void highlightVertical(int x, int y) {
	switch (x)
	{
	case 15:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		cout << "EXTRAS";
		break;
	case 55:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);
		cout << "BANCO";
		break;
	default:
		break;
	}
}
//Mover arriba y abajo en cada una de las posiciones dependiendo de x
void upDown(int posCursor, int *x, int *y) {
	switch (*x)
	{
	case 15:
		if (posCursor == 80 && *y <= 7) {
			subMenuRecursividad();
			gotoxy(*x, *y + 2);
			*y = (*y + 2) % 14;
			highlightHorizontal(*x, *y);

		}
		break;
	case 55:
		if (posCursor == 80 && *y <= 15) {
			subMenuVectores();
			gotoxy(*x, *y + 2);
			*y = (*y + 2) % 30;
			highlightHorizontal(*x, *y);

		}
		break;
	default:
		break;
	}

}
void downUp(int posCursor, int *x, int *y) {
	switch (*x)
	{
	case 15:
		if (posCursor == 72 && *y > 4) {
			subMenuRecursividad();
			gotoxy(*x, *y - 2);
			*y = (*y % 14) - 2;
			*x = 15;
			//gotoxy(*x, *y);
			highlightHorizontal(*x, *y);

		}
		break;
	case 55:
		if (posCursor == 72 && *y > 4) {
			subMenuVectores();
			*y -= 2;
			*x = 55;
			gotoxy(*x, *y);
			highlightHorizontal(*x, *y);

		}
		break;
	default:
		break;
	}

}
void leftRight(int posCursor, int *x, int *y) {

	switch (*x) {
	case 15:
		if (posCursor == 77 && *y == 4) {
			system("cls");
			subMenuVectores();
			*x = 55;
			gotoxy(*x, *y);
			highlightVertical(*x, *y);

		}
		break;
	}
}
void rightLeft(int posCursor, int *x, int *y) {

	switch (*x) {
	case 93:
		if (posCursor == 75 && *y == 4) {
			system("cls");
			subMenuVectores();
			*x = 55;
			gotoxy(*x, *y);
			highlightVertical(*x, *y);
		}
		break;
	case 55:
		if (posCursor == 75 && *y == 4) {
			system("cls");
			subMenuRecursividad();
			*x = 15;
			gotoxy(*x, *y);
			highlightVertical(*x, *y);

		}
		break;
	}
}

void asigneFunctionY(int cursor, int *x, int *y) {
	switch (*y)
	{
	case 6:
		if (*x == 15) {
			int pid;
			system("cls");
			CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
			ShellExecuteA(NULL, "open", "intento2.exe", NULL, NULL, SW_SHOW);
			//system("PAUSE");
			Sleep(5000);
			system("taskkill /IM intento2.exe /F");
			system("cls");
			subMenuRecursividad();
		}
		else {
			if (*x == 55) {
				system("cls");
				//funcion de insertar
				insertIntoBank();
				system("cls");
				subMenuVectores();
			}
		}

		break;
	case 8:
		if (*x == 15) {
			system("cls");
			CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
			ShellExecuteA(NULL, "open", "Marquesina.exe", NULL, NULL, SW_SHOW);
			//system("PAUSE");
			Sleep(15000);
			system("taskkill /IM Marquesina.exe /F");
			system("cls");
			subMenuRecursividad();
		}
		else {
			if (*x == 55) {
				system("cls");
				//funcion de buscar
				searchList();
				system("PAUSE");
				system("cls");
				subMenuVectores();
			}
		}
		break;
	case 10:
		if (*x == 55) {
			system("cls");
			//funcion de eliminar
			erase();
			system("cls");
			subMenuVectores();
		}
		break;
	case 12:
		if (*x == 55) {
			system("cls");
			//funcion de imprimir
			bank->print();
			system("PAUSE");
			system("cls");
			subMenuVectores();
		}
		break;
	case 14:
		if (*x == 55) {
			system("cls");
			//funcion de guardar
			system("cls");
			subMenuVectores();
		}
		break;
	case 16:
		if (*x == 55) {
			system("cls");
			//funcion de vaciar
			bank->emptyList();
			system("cls");
			subMenuVectores();
		}
		break;
	default:
		break;
	}
}


//Main 
int main()
{
	system("cls");
	bool exit = true;
	int auxX = 15, auxY = 4, getc = 0;
	subMenuRecursividad();
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		switch (getc)
		{
		case 80:
			upDown(80, &auxX, &auxY);
			break;
		case 72:
			downUp(72, &auxX, &auxY);
			break;
		case 75:
			rightLeft(75, &auxX, &auxY);
			break;
		case 77:
			leftRight(77, &auxX, &auxY);
			break;
		case 13:
			asigneFunctionY(getc, &auxX, &auxY);
			break;
		case 27:
			gotoxy(100, 21);
			exit = false;
			break;
		case 59:
			CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
			ShellExecuteA(NULL, "open", "Manual.chm", NULL, NULL, SW_SHOW);
			break;
		default:
			break;
		}
		getc = _getch();
	} while (exit);

	return 0;

}


