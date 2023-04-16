#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include "structure.h"

using namespace std;

struct Account //Структура аккаунтов
{
	string login;
	string password;
	int role;
	
};
const string accInfo = "Accounts.txt";
//std::vector<Account> v1 = getVectorAccounts(v1);
vector<Account> changeAccount(vector<Account> a, int& user); //Изменить данные об аккаунтах
vector<Account> createNewAccount(vector<Account> a); //Создать аккаунт
vector<Account> createNewAccount1(vector<Account> a);//Создать аккаунт c выбором роли
int inAccount(vector<Account> a); //Вход в аккаунт
vector <Account> changePassowrd(vector<Account> a, int user); //Изменить пароль
vector<Account> changeRole(vector<Account> a);//Выбор индекса аккаунта для изменения роли
vector<Account> changeRole_1(vector<Account> a, int i); //Изменение роли аккаунта
vector<Account> deleteAccount_1(vector<Account> a, int i, int& user);//Удаление выбранного аккаунта
vector<Account> deleteAccount(vector<Account> a, int& user);//Выбор аккаунта для удаления
void viewAccounts(vector<Account> a);

vector<Account> getVectorAccounts(vector<Account> a);
void saveAccounts(vector<Account> v2);
vector <Account> v1 = getVectorAccounts(v1);

vector<Account> getVectorAccounts(vector<Account> a)//чтение файла
{
	ifstream fin(accInfo, ios::in);
	if (fin.is_open())
	{
		Account temp;
		while (!fin.eof())
		{
			fin >> temp.login
				>> temp.password
				>> temp.role;
			a.push_back(temp);
		}
		fin.close();
	}
	else
	{
		cout << "Fatal eror!" << endl;
	}
	return a;
}
void saveAccounts(vector<Account> v2)
{
	ofstream fout(accInfo, ios::out);
	for (int i = 0; i < v2.size(); i++)
	{
		if (i != 0) fout << endl;
		fout << v2.at(i).login
			<< " " << v2.at(i).password
			<< " " << v2.at(i).role;
	}
	fout.close();
}

string cinAccountData()
{
	int ch;
	string result;
	while (true)
	{
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >=
			48 && ch <= 57) || ch == 13 || ch == 8)
		{
			if (ch == 13)
			{
				break;
			}
			else
				if (ch == 8)
				{
					cout << (char)8 << ' ' << char(8);
					if (!result.empty())
						result.erase(result.length() - 1);
				}
				else
				{
					cout << (char)ch;
					result += (char)ch;
				}
		}
	}
	cout << endl;
	return result;
}
string cinAccountData_1()
{
	int ch;
	string result;
	while (true)
	{
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >=
			48 && ch <= 57) || ch == 13 || ch == 8)
		{
			if (ch == 13)
			{
				break;
			}
			if (ch == 8)
			{
				cout << (char)8 << ' ' << char(8);
				if (!result.empty())
					result.erase(result.length() - 1);
			}
			else
			{
				cout << '*';
				result += (char)ch;
			}
		}
	}
	cout << endl;
	return result;
}
char YesNoQuestion()
{
	char a;
	while (true)
	{
		a = _getch();
		if (a == '1' || a == '2') return a;
	}
}
void viewAccounts(vector<Account> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Номер " << i + 1 << endl
			<< "Логин " << a.at(i).login << endl
			<< "Роль " << a.at(i).role << endl << endl;
	}
}
int generateInt()
{
	int a;
	cin >> a;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка, введите целое число!" << endl;
		cin >> a;
	}
	return a;
}

vector<Account> changeAccount(vector<Account> a, int& user)
{
	char question;
	while (true)
	{
		cout << "1) Изменить роль" << endl
			<< "2) Удалить аккаунт" << endl
			<< "3) Показать все аккаунты" << endl
			<< "0) Выйти" << endl;
		question = _getch();
		system("cls");
		switch (question)
		{
		case '1':
		{
			a = changeRole(a);
			break;
		}
		case '2':
		{
			a = deleteAccount(a, user);
			break;
		}
		case '3':
		{
			viewAccounts(a);
			system("pause");
			break;
		}
		case '0': return a;
		default: cout << "Invalid input!" << endl;
		}
		system("cls");
	}
}
int inAccount(vector<Account> a)
{
	char question, ch;
	int i;
	while (true)
	{
		cout << "Добро пожаловать!" << endl
			<< "1) Войти в аккаунт" << endl
			<< "2) Создать новый аккаунт" << endl
			<< "3) Выйти" << endl;
		question = _getch();
		system("cls");
		if (question == '1')
		{
			string login, password;
			bool flag = false;
			do
			{
				system("cls");
				cout << "Введите логин." << endl;
				login = cinAccountData();
				system("cls");
				cout << "Введите пароль" << endl;
				password = cinAccountData_1();
				system("cls");
				//password = sha1(password);
				for (i = 0; i < a.size(); i++)
					if (login == a.at(i).login && password ==
						a.at(i).password)
					{
						flag = true;
						return i;
					}
				if (!flag)
				{
					cout << "Неверный логин или пароль!" << endl
						<< "Повторить ввод?" << endl
						<< "1) Повторить" << endl << "2) Выйти"
						<< endl;
					question = YesNoQuestion();
					system("cls");
					if (question == '2') exit(0);
				}
			} while (!flag);
		}
		else
			if (question == '2') v1 = createNewAccount(v1);
			else if (question == '3') exit(0);
			else
			{
				system("cls");
				cout << "Invalid input!" << endl;
			}
	}
}
vector<Account> createNewAccount(vector<Account> a)
{
	Account newUser;
	bool flag;
	do
	{
		flag = false;
		cout << "Введите логин!" << endl;
		newUser.login = cinAccountData();
		for (int t = 0; t < a.size(); t++)
		{
			if (newUser.login == a.at(t).login)
			{
				flag = true;
				system("cls");
				cout << endl << "Такой аккаунт уже существует, введите другой!" << endl;
				break;
			}
		}
	} while (flag);
	cout << endl << "Введите пароль!" << endl;
	newUser.password = cinAccountData();
	char quest;
	cout << endl;
	cout << "Вы действительно хотите создать аккаунт?" << endl
		<< "1) да" << endl
		<< "2) нет" << endl;
	quest = YesNoQuestion();
	if (quest == '2') return a;
	newUser.role = 0;
	a.push_back(newUser);
	saveAccounts(a);
	return a;
}
vector<Account> createNewAccount1(vector<Account> a)
{
	Account newUser;
	bool flag;
	char quest, answer;
	do
	{
		flag = false;
		cout << "Введите логин!" << endl;
		newUser.login = cinAccountData();
		for (int t = 0; t < a.size(); t++)
		{
			if (newUser.login == a.at(t).login)
			{
				flag = true;
				system("cls");
				cout << endl << "Такой аккаунт уже существует, введите другой!" << endl;
				break;
			}
		}
	} while (flag);
	cout << endl << "Введите пароль!" << endl;
	newUser.password = cinAccountData();
	cout << "Какова роль аккаунта " << endl
		<< "1 - Администратор" << endl
		<< "2 - Пользователь" << endl;
	answer = YesNoQuestion();
	if (answer == '1') {
		newUser.role = 1;
	}
	else newUser.role = 0;
	
	cout << endl;
	cout << "Вы действительно хотите создать аккаунт?" << endl
		<< "1) да" << endl
		<< "2) нет" << endl;
	quest = YesNoQuestion();
	if (quest == '2') return a;
	
	a.push_back(newUser);
	saveAccounts(a);
	return a;
}
vector<Account> changeRole(vector<Account> a)
{
	char question;
	int i;
	viewAccounts(a);
	cout << "Желаете изменить роль?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		viewAccounts(a);
		cout << "Введите номер изменяемого аккаунта." << endl
			<< "Нажмите -1 чтобы выйти."<<endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size()) cout << "Invalid input!" << endl;
		else if (i == 0)  break;
		//else if (a.at(i).role == 1) cout << "Вы не можете изменить роль этого аккаунта!" << endl;
		else
		{
			a = changeRole_1(a, i);
			return a;
		}
	}
}
vector<Account> changeRole_1(vector<Account> a, int i)
{
	char question;
	if (a.at(i).role == 0)
	{
		cout << "Изменить роль " << a.at(i).login << " на админа?" <<
			endl
			<< "1) Да" << endl << "2) Нет" << endl;
		question = YesNoQuestion();
		system("cls");
		if (question == '1')
		{
			a.at(i).role = 1;
			saveAccounts(a);
			return a;
		}
		else return a;
	}
	else
	{
		cout << "Изменить роль " << a.at(i).login << " на пользователя?"
			<< endl
			<< "1) Да" << endl << "2) Нет" << endl;
		question = YesNoQuestion();
		system("cls");
		if (question == '1')
		{
			a.at(i).role = 0;
			saveAccounts(a);
			return a;
		}
		else return a;
	}
}
vector <Account> changePassword(vector<Account> a, int user)
{
	char question;
	string password;
	cout << "Вы хотите изменить пароль?" << endl <<
		"1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		cout << "Введите старый пароль" << endl;
		password = cinAccountData_1();
		//	password = sha1(password);
		system("cls");
		if (password == a.at(user).password) break;
		else
		{
			cout << "Пароль неверный! Повторить ввод?" << endl
				<< "1) Да" << endl << "2) Нет" << endl;
			question = YesNoQuestion();
			system("cls");
			if (question == '2') return a;
		}
	}
	cout << "Введите новый пароль" << endl;
	password = cinAccountData();
	//password = sha1(password);
	cout << "Изменить пароль?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '1')
	{
		a.at(user).password = password;
		saveAccounts(a);
		return a;
	}
	else return a;
}
vector<Account> deleteAccount(vector<Account> a, int& user)
{
	char question;
	int i;
	viewAccounts(a);
	cout << "Желаете удалить аккаунт?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2')return a;
	while (true)
	{
		viewAccounts(a);
		cout << "Какой аккаунт удалить?" << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size())
		{
			cout << "Invalid input!" << endl;
		}
		else if (a.at(i).role == 1) cout << "Вы не можете удалить этот	аккаунт!" << endl;
		else
		{
			a = deleteAccount_1(a, i, user);
			return a;
		}
	}
}
vector<Account> deleteAccount_1(vector<Account> a, int i, int& user)
{
	char question;
	cout << "Номер " << i + 1 << endl
		<< "Логин " << a.at(i).login << endl
		<< "Роль " << a.at(i).role << endl
		<< "Удалить?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	string temp = a.at(user).login;
	for (i; i + 1 < a.size(); i++) a.at(i) = a.at(i + 1);
	a.pop_back();
	saveAccounts(a);
	for (i = 0; i < a.size(); i++) if (a.at(i).login == temp) break;
	user = i;
	return a;
}
