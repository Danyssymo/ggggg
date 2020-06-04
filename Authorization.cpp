#include "Authorization.h"

bool Authorization::authorization(SOCKET S, Authorization * autho, string pathFile, string value)
{
	string log, pass;
	cin.get();
	cout << "Введите логин: "; getline(cin, log);
	send(S, log.c_str(), log.length(), 0);
	cout << "Введите пароль: "; getline(cin, pass);
	send(S, pass.c_str(), log.length(), 0);
	char resultMSG[256];
	for (int i = 0; i < 256; i++) {
		resultMSG[i] = '\0';
	}
	recv(S, resultMSG, sizeof(resultMSG), 0);
	string res=(string)resultMSG;
	if (res == "true") {
		green cout << "Авторизация прошла успешно!" << value << endl; white
		return true;
	}
	else {
		red cout << "Неверно введен логин либо пароль!" << endl; white
		return false;
	}
}

void Authorization::registration(Authorization * autho, string pathFile, string value)
{
	ofstream theFileIsNotCreated;
	fstream theFileIsCreated;
	theFileIsCreated.open(pathFile);
	if (theFileIsCreated.is_open()) {
		autho = new Authorization[100];
		int count = 0, position = 0;
		while (!theFileIsCreated.eof()) {
			theFileIsCreated >> autho[count].login;
			theFileIsCreated >> autho[count].password;
			count++;
		}
		string log, pass;
		cin.get();
		cout << "Введите логин: "; getline(cin,log);
		cout << "Введите пароль: "; getline(cin, pass);
		for (int i = 0; i < count; i++) {
			if (log == autho[i].login && pass == autho[i].password) {
				position = i;
				break;
			}
		}
		if (autho[position].login == log && autho[position].password == pass) {
			cout << "Такой " << value << " уже существует!" << endl;
		}
		else {
			green theFileIsCreated.close();
			theFileIsCreated.open(pathFile, fstream::app);
			theFileIsCreated << log << " " << pass << endl;
			cout << "Регистрация прошла успешно!" << endl; white
		}
		delete[] autho;
	}
	else {
		red theFileIsNotCreated.open(pathFile);
		cout << "База данных не найдена!\nИдет создание...\nБаза данных создана!" << endl;
		theFileIsNotCreated.close(); white
	}
	theFileIsCreated.close();
}

void Authorization::forgotPassword(Authorization * autho, string pathFile)
{
	ofstream theFileIsNotCreated;
	fstream theFileIsCreated;
	int count = 0, position = 0;
	theFileIsCreated.open(pathFile);
	if (theFileIsCreated.is_open()) {
		autho = new Authorization[100];
		while (!theFileIsCreated.eof()) {
			theFileIsCreated >> autho[count].login;
			theFileIsCreated >> autho[count].password;
			count++;
		}
		string log;
		cin.get();
		cout << "Введите логин: "; getline(cin, log);
		for (int i = 0; i < count - 1; i++) {
			if (log == autho[i].login) {
				position = i;
				break;
			}
		}
		if (log == autho[position].login) {
			green cout << "Ваш пароль: " << autho[position].login << endl; white
		}
		else {
			red cout << "Такой логин отсутствует!" << endl; white
		}
	}
	else {
		red theFileIsNotCreated.open(pathFile);
		cout << "База данных не найдена!\nИдет создание...\nБаза данных создана!" << endl;
		theFileIsNotCreated.close(); white
	}
	theFileIsCreated.close();
}