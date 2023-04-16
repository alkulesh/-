#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include "structure.h"
#include "accounts.h"


using namespace std;
//vector <Account> v1 = getVectorAccounts(v1);
void Menu_Admin(vector <Account> v1, vector <Info> v2, int &user);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int AccNum;
	vector <Account> v1 = getVectorAccounts(v1);
	vector <Info> v2 = getVectorInfo(v2);

	while (true)
	{
		AccNum = inAccount(v1); //Вход в аккаунт
		if (AccNum == -2) v1 = createNewAccount(v1); //Если в inAccount выбрали создать аккаунт
		else
			if (AccNum >= 0 && v1.at(AccNum).role == 1)
			{
				system("cls");
				cout << "Здравствуйте, " << v1.at(AccNum).login <<
					"!" << endl;
				Menu_Admin(v1, v2, AccNum);
			}
			else
				if (AccNum >= 0 && v1.at(AccNum).role == 0)
				{
						system("cls");
					cout << "Здравствуйте, " << v1.at(AccNum).login <<
						"!" << endl;

				}
	}

}
void Menu_Admin(vector <Account> v1,vector <Info> v2, int &user) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char answer;
	while (true) {
		cout << "Меню" << endl
			<< "1. Создать новый аккаунт" << endl
			<< "2. Удалить аккаунт" << endl
			<< "3. Изменить данные об аккаунтaх" << endl
			<< "4. Изменить свой пароль" << endl
			<< "5. Добавить данные об успеваимости" << endl
			<< "6. Изменить данные об успеваемости" << endl
			<< "7. Удалить данные об успеваемости"  << endl
			<< "0. Выйти" <<endl;
		answer = _getch();
		switch (answer) {
		case '1': createNewAccount1(v1);
			break;
		case '2': deleteAccount(v1, user);
			break;
		case '3':
			v1 = changeAccount(v1, user);
			break;
		case '4':
			v1 = changePassword(v1, user);
			break;
		case '5':
			 AddNewInfo(v2);
			break;
		case '6': 
			v2 = changeInfo(v2);
			break;
		case '7':
			v2 = deleteInfo(v2);
			break;
		case '0': return;
		default: cout << "Неверный ввод"; break;
		}


	}


}