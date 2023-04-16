#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include "structure.h"

using namespace std;

struct Account //��������� ���������
{
	string login;
	string password;
	int role;
	
};
const string accInfo = "Accounts.txt";
//std::vector<Account> v1 = getVectorAccounts(v1);
vector<Account> changeAccount(vector<Account> a, int& user); //�������� ������ �� ���������
vector<Account> createNewAccount(vector<Account> a); //������� �������
vector<Account> createNewAccount1(vector<Account> a);//������� ������� c ������� ����
int inAccount(vector<Account> a); //���� � �������
vector <Account> changePassowrd(vector<Account> a, int user); //�������� ������
vector<Account> changeRole(vector<Account> a);//����� ������� �������� ��� ��������� ����
vector<Account> changeRole_1(vector<Account> a, int i); //��������� ���� ��������
vector<Account> deleteAccount_1(vector<Account> a, int i, int& user);//�������� ���������� ��������
vector<Account> deleteAccount(vector<Account> a, int& user);//����� �������� ��� ��������
void viewAccounts(vector<Account> a);

vector<Account> getVectorAccounts(vector<Account> a);
void saveAccounts(vector<Account> v2);
vector <Account> v1 = getVectorAccounts(v1);

vector<Account> getVectorAccounts(vector<Account> a)//������ �����
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
		cout << "����� " << i + 1 << endl
			<< "����� " << a.at(i).login << endl
			<< "���� " << a.at(i).role << endl << endl;
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
		cout << "������, ������� ����� �����!" << endl;
		cin >> a;
	}
	return a;
}

vector<Account> changeAccount(vector<Account> a, int& user)
{
	char question;
	while (true)
	{
		cout << "1) �������� ����" << endl
			<< "2) ������� �������" << endl
			<< "3) �������� ��� ��������" << endl
			<< "0) �����" << endl;
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
		cout << "����� ����������!" << endl
			<< "1) ����� � �������" << endl
			<< "2) ������� ����� �������" << endl
			<< "3) �����" << endl;
		question = _getch();
		system("cls");
		if (question == '1')
		{
			string login, password;
			bool flag = false;
			do
			{
				system("cls");
				cout << "������� �����." << endl;
				login = cinAccountData();
				system("cls");
				cout << "������� ������" << endl;
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
					cout << "�������� ����� ��� ������!" << endl
						<< "��������� ����?" << endl
						<< "1) ���������" << endl << "2) �����"
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
		cout << "������� �����!" << endl;
		newUser.login = cinAccountData();
		for (int t = 0; t < a.size(); t++)
		{
			if (newUser.login == a.at(t).login)
			{
				flag = true;
				system("cls");
				cout << endl << "����� ������� ��� ����������, ������� ������!" << endl;
				break;
			}
		}
	} while (flag);
	cout << endl << "������� ������!" << endl;
	newUser.password = cinAccountData();
	char quest;
	cout << endl;
	cout << "�� ������������� ������ ������� �������?" << endl
		<< "1) ��" << endl
		<< "2) ���" << endl;
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
		cout << "������� �����!" << endl;
		newUser.login = cinAccountData();
		for (int t = 0; t < a.size(); t++)
		{
			if (newUser.login == a.at(t).login)
			{
				flag = true;
				system("cls");
				cout << endl << "����� ������� ��� ����������, ������� ������!" << endl;
				break;
			}
		}
	} while (flag);
	cout << endl << "������� ������!" << endl;
	newUser.password = cinAccountData();
	cout << "������ ���� �������� " << endl
		<< "1 - �������������" << endl
		<< "2 - ������������" << endl;
	answer = YesNoQuestion();
	if (answer == '1') {
		newUser.role = 1;
	}
	else newUser.role = 0;
	
	cout << endl;
	cout << "�� ������������� ������ ������� �������?" << endl
		<< "1) ��" << endl
		<< "2) ���" << endl;
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
	cout << "������� �������� ����?" << endl
		<< "1) ��" << endl << "2) ���" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		viewAccounts(a);
		cout << "������� ����� ����������� ��������." << endl
			<< "������� -1 ����� �����."<<endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size()) cout << "Invalid input!" << endl;
		else if (i == 0)  break;
		//else if (a.at(i).role == 1) cout << "�� �� ������ �������� ���� ����� ��������!" << endl;
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
		cout << "�������� ���� " << a.at(i).login << " �� ������?" <<
			endl
			<< "1) ��" << endl << "2) ���" << endl;
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
		cout << "�������� ���� " << a.at(i).login << " �� ������������?"
			<< endl
			<< "1) ��" << endl << "2) ���" << endl;
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
	cout << "�� ������ �������� ������?" << endl <<
		"1) ��" << endl << "2) ���" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		cout << "������� ������ ������" << endl;
		password = cinAccountData_1();
		//	password = sha1(password);
		system("cls");
		if (password == a.at(user).password) break;
		else
		{
			cout << "������ ��������! ��������� ����?" << endl
				<< "1) ��" << endl << "2) ���" << endl;
			question = YesNoQuestion();
			system("cls");
			if (question == '2') return a;
		}
	}
	cout << "������� ����� ������" << endl;
	password = cinAccountData();
	//password = sha1(password);
	cout << "�������� ������?" << endl
		<< "1) ��" << endl << "2) ���" << endl;
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
	cout << "������� ������� �������?" << endl
		<< "1) ��" << endl << "2) ���" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2')return a;
	while (true)
	{
		viewAccounts(a);
		cout << "����� ������� �������?" << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size())
		{
			cout << "Invalid input!" << endl;
		}
		else if (a.at(i).role == 1) cout << "�� �� ������ ������� ����	�������!" << endl;
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
	cout << "����� " << i + 1 << endl
		<< "����� " << a.at(i).login << endl
		<< "���� " << a.at(i).role << endl
		<< "�������?" << endl
		<< "1) ��" << endl << "2) ���" << endl;
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
