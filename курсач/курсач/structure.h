#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "accounts.h"
using namespace std;

struct Info {
	int number;
	string subject;
	string fio;
	int mark;
	int hours;
	string date;
	string offset;
};



const string InfoFile = "Info.txt";

vector <Info> deleteInfo(vector<Info> a);
vector <Info> deleteInfo1(vector<Info> a, int i);
vector <Info> changeInfo(vector<Info> a);
vector<Info> getVectorInfo(vector<Info> a);

vector<Info> getVectorInfo(vector<Info> a)
{
	ifstream fin(InfoFile, ios::in);
	if (fin.is_open())
	{
		Info temp;
		while (!fin.eof())
		{
			fin >> temp.number
				>> temp.subject
				>> temp.fio
				>> temp.mark
				>> temp.hours
				>> temp.date
				>> temp.offset;
			a.push_back(temp);
		}
		fin.close();
	}
	else
	{
		cout << "File is not found!" << endl; ///////////////////////////
	}
	return a;
}


void saveInfo(vector<Info> v1)
{
	ofstream fout(InfoFile, ios::in);
	for (int i = 0; i < v1.size(); i++)
	{
			fout << v1.at(i).number
			<< " " << v1.at(i).subject
			<< " " << v1.at(i).fio
			<< " " << v1.at(i).mark
			<< " " << v1.at(i).hours
			<< " " << v1.at(i).date
			<< " " << v1.at(i).offset;
		fout << endl;
	}
	fout.close();
}


void showAllInfo(vector<Info> a)//���� ����������
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "� " << i + 1 << endl
			<< "�������� �������� " << a.at(i).number << endl //////////////////////
			<< "�������� �������� " << a.at(i).subject << endl
			<< "���  �������� " << a.at(i).fio << endl
			<< "������ �� ������� " << a.at(i).mark << endl
			<< "���������� ����� �� ���������� " << a.at(i).hours << endl
			<< "���� �������� " << a.at(i).date << endl
			<< "��������� ������ " << a.at(i).offset << endl <<
			endl << endl;
	}
}


void AddNewInfo(vector<Info> a) {
	char answer, answer1;
	Info new_info;
	cout << "������� ��� �����?" << endl
		<< "1 - �������"<<endl
		<< "2- �����" << endl;
	answer1 = YesNoQuestion();
	if (answer1 == '1') {
		cout << "������� ����� ������ " << endl;
		cin >> new_info.number;
		cout << "������� �������" << endl;

		cin >> new_info.subject;

		cout << "������� ���" << endl;
		cin >> new_info.fio;
		system("cls");
		cout << "������� ������" << endl;
		new_info.mark = generateInt();
		system("cls");
		cout << "������� ���������� ������� �����" << endl;
		cin >> new_info.hours;
		system("cls");
		cout << "������� ����" << endl;
		cin >> new_info.date;
		system("cls");
		
		new_info.offset = '0';
		system("cls");

		cout << "����� ������ " << new_info.number << endl
			<< "������� " << new_info.subject << endl
			<< "��� " << new_info.fio << endl /////////////////////////////
			<< "������ " << new_info.mark << endl
			<< "���-�� ����� " << new_info.hours << endl
			<< "���� " << new_info.date << endl << endl << endl;

		cout << "�������� ������?" << endl << "1) ��" << endl << "2) ���"<< endl;
		answer = YesNoQuestion();

		while (true) {
			if (answer == '1')
			{
				a.push_back(new_info);
				saveInfo(a);
				return;
			}
			else if (answer == '2')
				break;
			else
			{
				cout << "Invalid input!" << endl;
			}
		} 
	}
	else if (answer1 == '2') {
		cout << "������� ����� ������ " << endl;
		cin >> new_info.number;
		cout << "������� �������" << endl;

		cin >> new_info.subject;

		cout << "������� ���" << endl;
		cin >> new_info.fio;
		std::system("cls");
		//cout << "������� ������" << endl;
		new_info.mark = -1;
		system("cls");
		cout << "������� ���������� ������� �����" << endl;
		cin >> new_info.hours;
		system("cls");
		cout << "������� ����" << endl;
		cin >> new_info.date;
		system("cls");
		cout << "������� �����" << endl;
		cin >> new_info.offset;
		system("cls");

		cout << "����� ������ " << new_info.number << endl
			<< "������� " << new_info.subject << endl
			<< "��� " << new_info.fio << endl /////////////////////////////
			//<< "������ ���������� " << new_info.mark << endl
			<< "���-�� ����� " << new_info.hours << endl
			<< "���� " << new_info.date << endl
			<< "����� " << new_info.offset << endl << endl << endl;

		cout << "�������� ������?" << endl << "1) ��" << endl << "2) ���"
			<< endl;
		answer = YesNoQuestion();

		while (true) {
			if (answer == '1')
			{
				a.push_back(new_info);
				saveInfo(a);
				return;
			}
			else if (answer == '2')
				break;
			else
			{
				cout << "Invalid input!" << endl;
			}
		}
	}
}



int InfoMenu(vector<Info> a) {
	char answer;
	bool flag = true;
	while (flag == true) {
		cout << "���� �������������� � �������������" << endl
			<< "*******************************************" << endl
			<< "1 - �������� ������" << endl
			<< "2 - �������� ������" << endl
			<< "3 - ������� ������" << endl
			<< "4 - ��������� � ������� ����" << endl;
		answer = _getch();
		switch (answer) {
		case '1':
			AddNewInfo(a);
			break;
		case '2':
			 a=changeInfo(a);
			break;
		case '3':
			a = deleteInfo(a);
			break;
		case '4': system("cls");
			return 1;

		default: cout << "������! ������� ����� �� 1 �� 4" << endl;
		}
	}

	return 1;


}

vector <Info> deleteInfo(vector<Info> a)
{
	char question;
	int i;
	while (true)
	{
		showAllInfo(a);
		cout << "������� ������� ����������?" << endl
			<< "1) ��" << endl << "2) ���" << endl;
		question = _getch();
		system("cls");
		if (question == '1') break;
		else if (question == '2') return a;
		else cout << "Invalid input!" << endl;
	}
	while (true)
	{
		showAllInfo(a);
			cout << "����� �������?" << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size()) cout << "Invalid input!" << endl;
		else
		{
			a = deleteInfo1(a, i);
			return a;
		}
	}
}

vector <Info> deleteInfo1(vector<Info> a, int i)
{
	char question;
	while (true)
	{
		cout << "� " << i + 1 << endl
			<< "����� ������ " << a.at(i).number << endl
			<< "������� " << a.at(i).subject << endl
			<< "��� " << a.at(i).fio << endl
			<< "������ " << a.at(i).mark << endl //////////////////////***
			<< "���� " << a.at(i).hours << endl
			<< "���� " << a.at(i).date << endl
			<< "����� " << a.at(i).offset << endl
			<< "������� ������?" << endl
			<< "1) ��" << endl
			<< "2) ���" << endl;
		question = _getch();
		system("cls");
		if (question == '1')
		{
			for (i; i < a.size() - 1; i++) a.at(i) = a.at(i + 1);
			a.pop_back();
			saveInfo(a);
			return a;
		}
		else if (question == '2') return a;
		else cout << "Invalid input!" << endl;
	}
}



vector <Info> changeInfo(vector<Info> a)
{
	int i;
	char answer;
	showAllInfo(a);
	cout << "������� �������� ������?" << endl
		<< "1) ��" << endl << "2) ���" << endl;
	answer = YesNoQuestion();
	system("cls");
	if (answer == '2') { i = -1; return a; };
	while (true)
	{
		showAllInfo(a);
		cout << "������� ����� " << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size())
			cout << "Invalid input!" << endl;
		else;

		Info temp = a.at(i);
		bool flag = false;
		//bool flag1;
		int k;
		while (!flag)
		{
			cout << "����� ���������� ����� ��������?" << endl
				<< "1)����� ������	" << a.at(i).number << endl //////////////////////////////////
				<< "2)�������	" << a.at(i).subject << endl
				<< "3)���	" << a.at(i).fio << endl
				<< "4)������	" << a.at(i).mark << endl
				<< "5)����		" << a.at(i).hours << endl
				<< "6)����		" << a.at(i).date << endl
				<< "6)�����" << a.at(i).offset << endl
				<< "0) ��������� ��������������" << endl << endl;
			answer = _getch();
			system("cls");
			switch (answer) {
			case '1':

				cout << "����� ������." << endl; ///////////////////////////
				cin >> temp.number;
				system("cls");
				break;
			case '2':
				cout << "������� �������." << endl;
				cin >> temp.subject;
				system("cls");
				break;
			case '3':
				cout << "������� ���." << endl;
				cin >> temp.fio;
				system("cls");

				break;
			case '4':
				cout << "������� ������." << endl;
				cin >> temp.mark;
				system("cls");

				break;
			case '5':
				cout << "������� ������� ����." << endl;
				cin >> temp.hours;
				system("cls");

				break;
			case '6':
				cout << "������� ����." << endl;
				cin >> temp.date;
				system("cls");

				break;
			case '7':
				cout << "������� �����." << endl;
				cin >> temp.offset;
				system("cls");

				break;
			case '0':
				flag = true;
				break;
			default: cout << "invalid input"; break;
			}
		}
		cout << "��������� ���������?" << endl << "1) ��" << endl << "2) ���"
			<< endl;
		answer = YesNoQuestion();
		if (answer == '1')
		{
			// sailAll(d, c, a.at(i), temp);
			a.at(i) = temp;
			saveInfo(a); return a;
		}
		else return a;
	}
}








