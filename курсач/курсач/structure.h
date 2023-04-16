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


void showAllInfo(vector<Info> a)//ввод информации
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "№ " << i + 1 << endl
			<< "Название предмета " << a.at(i).number << endl //////////////////////
			<< "Название предмета " << a.at(i).subject << endl
			<< "ФИО  студента " << a.at(i).fio << endl
			<< "Оценка за экзамен " << a.at(i).mark << endl
			<< "Количество часов по дисцеплине " << a.at(i).hours << endl
			<< "Дата экзаменв " << a.at(i).date << endl
			<< "Результат зачёта " << a.at(i).offset << endl <<
			endl << endl;
	}
}


void AddNewInfo(vector<Info> a) {
	char answer, answer1;
	Info new_info;
	cout << "Экзамен или зачет?" << endl
		<< "1 - Экзачем"<<endl
		<< "2- зачёт" << endl;
	answer1 = YesNoQuestion();
	if (answer1 == '1') {
		cout << "Введите номер группы " << endl;
		cin >> new_info.number;
		cout << "Введите предмет" << endl;

		cin >> new_info.subject;

		cout << "Введите ФИО" << endl;
		cin >> new_info.fio;
		system("cls");
		cout << "Введите оценка" << endl;
		new_info.mark = generateInt();
		system("cls");
		cout << "Введите количество аккадем часов" << endl;
		cin >> new_info.hours;
		system("cls");
		cout << "Введите дату" << endl;
		cin >> new_info.date;
		system("cls");
		
		new_info.offset = '0';
		system("cls");

		cout << "Номер группы " << new_info.number << endl
			<< "Предмет " << new_info.subject << endl
			<< "фио " << new_info.fio << endl /////////////////////////////
			<< "оценка " << new_info.mark << endl
			<< "Кол-во часов " << new_info.hours << endl
			<< "Дата " << new_info.date << endl << endl << endl;

		cout << "Добавить данные?" << endl << "1) Да" << endl << "2) Нет"<< endl;
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
		cout << "Введите номер группы " << endl;
		cin >> new_info.number;
		cout << "Введите предмет" << endl;

		cin >> new_info.subject;

		cout << "Введите ФИО" << endl;
		cin >> new_info.fio;
		std::system("cls");
		//cout << "Введите оценка" << endl;
		new_info.mark = -1;
		system("cls");
		cout << "Введите количество аккадем часов" << endl;
		cin >> new_info.hours;
		system("cls");
		cout << "Введите дату" << endl;
		cin >> new_info.date;
		system("cls");
		cout << "Введите зачет" << endl;
		cin >> new_info.offset;
		system("cls");

		cout << "Номер группы " << new_info.number << endl
			<< "Предмет " << new_info.subject << endl
			<< "ФИО " << new_info.fio << endl /////////////////////////////
			//<< "Модель автомобиля " << new_info.mark << endl
			<< "Кол-во часов " << new_info.hours << endl
			<< "Дата " << new_info.date << endl
			<< "Зачет " << new_info.offset << endl << endl << endl;

		cout << "Добавить данные?" << endl << "1) Да" << endl << "2) Нет"
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
		cout << "Меню взаимодействия с успеваемостью" << endl
			<< "*******************************************" << endl
			<< "1 - Добавить данные" << endl
			<< "2 - Изменить данные" << endl
			<< "3 - Удалить данные" << endl
			<< "4 - Вернуться в главное меню" << endl;
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

		default: cout << "Ошибка! Введите цифру от 1 до 4" << endl;
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
		cout << "Желаете удалить информацию?" << endl
			<< "1) Да" << endl << "2) Нет" << endl;
		question = _getch();
		system("cls");
		if (question == '1') break;
		else if (question == '2') return a;
		else cout << "Invalid input!" << endl;
	}
	while (true)
	{
		showAllInfo(a);
			cout << "Какую удалить?" << endl;
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
		cout << "№ " << i + 1 << endl
			<< "Номер группы " << a.at(i).number << endl
			<< "Предмет " << a.at(i).subject << endl
			<< "ФИО " << a.at(i).fio << endl
			<< "Оценка " << a.at(i).mark << endl //////////////////////***
			<< "Часы " << a.at(i).hours << endl
			<< "Дата " << a.at(i).date << endl
			<< "Зачет " << a.at(i).offset << endl
			<< "Удалить данные?" << endl
			<< "1) Да" << endl
			<< "2) Нет" << endl;
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
	cout << "Желаете изменить данные?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	answer = YesNoQuestion();
	system("cls");
	if (answer == '2') { i = -1; return a; };
	while (true)
	{
		showAllInfo(a);
		cout << "Введите номер " << endl;
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
			cout << "Какую информацию нужно изменить?" << endl
				<< "1)Номер группы	" << a.at(i).number << endl //////////////////////////////////
				<< "2)Предмет	" << a.at(i).subject << endl
				<< "3)ФИО	" << a.at(i).fio << endl
				<< "4)Оценка	" << a.at(i).mark << endl
				<< "5)Часы		" << a.at(i).hours << endl
				<< "6)Дата		" << a.at(i).date << endl
				<< "6)Зачет" << a.at(i).offset << endl
				<< "0) Завершить редактирование" << endl << endl;
			answer = _getch();
			system("cls");
			switch (answer) {
			case '1':

				cout << "Номер группы." << endl; ///////////////////////////
				cin >> temp.number;
				system("cls");
				break;
			case '2':
				cout << "Введите предмет." << endl;
				cin >> temp.subject;
				system("cls");
				break;
			case '3':
				cout << "Введите фио." << endl;
				cin >> temp.fio;
				system("cls");

				break;
			case '4':
				cout << "Введите оценку." << endl;
				cin >> temp.mark;
				system("cls");

				break;
			case '5':
				cout << "Введите аккадем часы." << endl;
				cin >> temp.hours;
				system("cls");

				break;
			case '6':
				cout << "Введите дату." << endl;
				cin >> temp.date;
				system("cls");

				break;
			case '7':
				cout << "Введите зачет." << endl;
				cin >> temp.offset;
				system("cls");

				break;
			case '0':
				flag = true;
				break;
			default: cout << "invalid input"; break;
			}
		}
		cout << "Сохранить изменения?" << endl << "1) Да" << endl << "2) Нет"
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








