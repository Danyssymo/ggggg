#include "AdminMenu.h"

vector<Worker> worker;
vector<Worker> forFile;

fstream dataBaseIsOpen;
ofstream dataBaseIsEmpty;
string pathFileFactory = "Factory.txt";

void AdminMenu::adminMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "Меню администратора" << endl;
		cout << "1.Создать БД" << endl;
		cout << "2.Добавить" << endl;
		cout << "3.Редактировать" << endl;
		cout << "4.Удалить" << endl;
		cout << "5.Сортировать" << endl;
		cout << "6.Поиск" << endl;
		cout << "7.Показать" << endl;
		cout << "8.Метод предпочтений" << endl;
		cout << "9.Записать данные в БД" << endl;
		cout << "0.Выход из меню" << endl;
		red cout << "(вы ввели)>>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			try
			{
				fileCreating();
			}
			catch (logic_error & le)
			{
				red cout << le.what() << endl; white
			}
			break;
		}
		case 2: {
			insert();
			break;
		}
		case 3: {
			redact();
			break;
		}
		case 4: {
			try
			{
				erase();
			}
			catch (logic_error & le)
			{
				red cout << le.what() << endl; white
			}
			break;
		}
		case 5: {
			sort();
			break;
		}
		case 6: {
			try
			{
				search();
			}
			catch (invalid_argument & ia)
			{
				red cout << ia.what() << endl; white
			}
			break;
		}
		case 7: {
			show(forFile);
			break;
		}
		case 8: {
			mainFunction();
			break;
		}
		case 9: {
			fileInsert();
			break;
		}
		default: {
			red noValue white;
			break;
		}
		}
	}
}

void AdminMenu::insert()
{
	Worker w1;
	cin >> w1;
	worker.push_back(w1);
}

void AdminMenu::redact()
{
	forFile.clear();
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		while (!dataBaseIsOpen.eof()) {
			Worker w;
			dataBaseIsOpen >> w;
			forFile.push_back(w);
		}
		int position = 0, number = 0;
		show(forFile);
		cout << "Введите номер: " << endl;
		cin >> number;
		for (auto it = forFile.begin(); it != forFile.end() - 1; it++) {
			if (number == position + 1) {
				Worker w;
				cin >> w;
				forFile.emplace(it, w);
				forFile.erase(it--);
				position--;
				break;
			}
			else position++;
		}
		if (position != forFile.size()) {
			dataBaseIsOpen.close();
			cout << "Данный номер удален!" << endl;
			dataBaseIsEmpty.open(pathFileFactory);
			dataBaseIsEmpty.close();
		}
		else throw logic_error("Такой номер не существует!");
	}
	else {
		throw logic_error("Ошибка в открытии БД!");
		dataBaseIsOpen.close();
	}
}

void AdminMenu::erase()
{
	try
	{
		forFile.clear();
		dataBaseIsOpen.open(pathFileFactory);
		if (dataBaseIsOpen.is_open()) {
			while (!dataBaseIsOpen.eof()) {
				Worker w;
				dataBaseIsOpen >> w;
				forFile.push_back(w);
			}
			int position = 0, number = 0;
			show(forFile);
			cout << "Введите номер: " << endl;
			cin >> number;
			for (auto it = forFile.begin(); it != forFile.end(); it++) {
				if (number == position + 1) {
					forFile.erase(it);
					position--;
					break;
				}
				else position++;
			}
			if (position != forFile.size()) {
				red cout << "Клиент с таким номером успешно удален!" << endl; white
				dataBaseIsEmpty.open(pathFileFactory);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				forFile.clear();
				show(forFile);
				dataBaseIsEmpty.close();
			}
			else throw logic_error("Такой номер не существует!");
		}
		else throw logic_error("Ошибка в открытии БД!");
		dataBaseIsOpen.close();
	}
	catch (logic_error & le)
	{
		red cout << le.what() << endl; white
	}
}

void AdminMenu::fileCreating()
{
	try
	{
		dataBaseIsOpen.open(pathFileFactory);
		if (!dataBaseIsOpen.is_open()) {
			dataBaseIsEmpty.open(pathFileFactory);
			green cout << "БД успешно создана!" << endl; white
			dataBaseIsEmpty.close();
		}
		else {
			throw logic_error("БД уже существует!");
		}
	}
	catch (logic_error & le)
	{
		red cout << le.what() << endl; white
	}
	dataBaseIsOpen.close();
}

void AdminMenu::fileInsert()
{
	if (worker.empty()) {
		throw range_error("Отсутствуют данные в векторе!");
	}
	else {
		dataBaseIsOpen.open(pathFileFactory);
		if (dataBaseIsOpen.is_open()) {
			dataBaseIsOpen.close();
			dataBaseIsOpen.open(pathFileFactory, fstream::app);
			for (auto it = worker.begin(); it != worker.end(); it++) {
				dataBaseIsOpen << *it << endl;
			}

			green cout << "Данные успешно записаны в БД!" << endl; white
		}
		else {
			red cout << "Отсутствует доступ к БД!" << endl; white
		}
		dataBaseIsOpen.close();
	}
}

void UserMenu::userMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "Меню администратора" << endl;
		cout << "1.Сортировать" << endl;
		cout << "2.Поиск" << endl;
		cout << "3.Показать" << endl;
		cout << "4.Метод предпочтений" << endl;
		cout << "0.Выход из меню" << endl;
		red cout << "(вы ввели)>>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			sort();
			break;
		}
		case 2: {
			try
			{
				search();
			}
			catch (invalid_argument & ia)
			{
				red cout << ia.what() << endl; white
			}
			break;
		}
		case 3: {
			show(forFile);
			break;
		}
		case 4: {
			mainFunction();
			break;
		}
		default: {
			red noValue white;
			break;
		}
		}
	}
}

void UserMenu::show(vector<Worker> w)
{
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		while (!dataBaseIsOpen.eof()) {
			Worker workerObject;
			dataBaseIsOpen >> workerObject;
			w.push_back(workerObject);
		}
		int count = 1;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|" << setw(4) << "№" << "|" << setw(25) << "Название тренажера" << "|" << setw(25) << "Фамилия клиента" << "|" << setw(25) << "Имя клиента" << "|" << setw(25) << "Отчество клиента"   << "|" << setw(25) << "Возраст клиента" << "|" << setw(25) << "Стаж клиента (дней посещено)" << "|" << setw(25) << "Оценка клиента" << "|" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (auto it = w.begin(); it != w.end() - 1; it++) {
			cout << setw(3) << count++ << ")." << *it << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else throw logic_error("Ошибка в открытии БД!");
	w.clear();
	dataBaseIsOpen.close();
}

void UserMenu::search()
{
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << left << "Поиск по" << endl;
			cout << "1.Названию тренажеров" << endl;
			cout << "2.Фамилии клиентов" << endl;
			cout << "3.Имени клиентов" << endl;
			cout << "4.Отчествy клиента" << endl;
			cout << "5.Возрасту клиентов" << endl;
			cout << "6.Стажу (сколько дней посещено) занятий клиентов" << endl;
			cout << "7.Оценке клиента" << endl;
			cout << "8.Перезаписать в файл отсортированные данные" << endl;
			cout << "0.Выход" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				forFile.clear();
				while(!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string factoryName;
				cin.get();
				getline(cin, factoryName);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getFactoryName().c_str(), factoryName.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 2: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string surname;
				cin.get();
				getline(cin, surname);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getSurname().c_str(), surname.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 3: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string name;
				cin.get();
				getline(cin, name);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getName().c_str(), name.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 4: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string personPosition;
				cin.get();
				getline(cin, personPosition);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getPersonPosition().c_str(), personPosition.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 5: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string age;
				cin.get();
				getline(cin, age);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getAge()).c_str(), age.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 6: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string experience;
				cin.get();
				getline(cin, experience);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getExperience()).c_str(), experience.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 7: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string detailsNumber;
				cin.get();
				getline(cin, detailsNumber);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getDetailsNumber()).c_str(), detailsNumber.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 8: {
				dataBaseIsEmpty.open(pathFileFactory);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				green cout << "отсортирвоанные данные перезаписаны в файл!" << endl; white
					dataBaseIsEmpty.close();
				break;
			}
			default: {
				red noValue white;
				break;
			}
			}
		}
	}
	else {
		red cout << "Отсутствует доступ к БД!" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::sort()
{
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << "Сортировка по" << endl;
			cout << "1.Названию тренажеров" << endl;
			cout << "2.Фамилии клиентов" << endl;
			cout << "3.Имени клиентов" << endl;
			cout << "4.Отчествy клиентов" << endl;
			cout << "5.Возрасту клиентов" << endl;
			cout << "6.Стажу (кол-во посещенных дней) клиентов" << endl;
			cout << "7.Оценке клиента" << endl;
			cout << "8.Перезаписать в файл отсортированные данные" << endl;
			cout << "0.Выход" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getFactoryName().c_str(), it2->getFactoryName().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 2: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getSurname().c_str(), it2->getSurname().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 3: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getName().c_str(), it2->getName().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 4: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getPersonPosition().c_str(), it2->getPersonPosition().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 5: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getAge() < it2->getAge()) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 6: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getExperience() < it2->getExperience()) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 7: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getDetailsNumber() < it2->getDetailsNumber()) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 8: {
				if (forFile.empty()) {
					red cout << "Данные не были отсортированы!" << endl; white
				}
				else {
					dataBaseIsEmpty.open(pathFileFactory);
					for (auto it = forFile.begin(); it != forFile.end(); it++) {
						dataBaseIsEmpty << *it << endl;
					}
					green cout << "отсортирвоанные данные перезаписаны в файл!" << endl; white
						dataBaseIsEmpty.close();
				}
				break;
			}
			default: {
				red noValue white;
				break;
			}
			}
		}
	}
	else {
		red cout << "Отсутствует доступ к БД!" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::mainFunction()
{
	forFile.clear();
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		int count = 0;
		while (!dataBaseIsOpen.eof()) {
			Worker w;
			dataBaseIsOpen >> w;
			forFile.push_back(w);
			count++;
		}
		double **matrix = new double*[count];
		for (int i = 0; i < count; i++) {
			matrix[i] = new double[3];
		}
		double criteriasArray[] = { 0.7,0.4,0.2 }, sumCriterias = 0.0, *weights = new double[count];
		for (int i = 0; i < count; i++) {
			weights[i] = 0;
		}
		for (int i = 0; i < 3; i++) {
			sumCriterias += criteriasArray[i]; //сумма оценок компетентности экспертов	
		}
		int rows = 0, columns = 0;
		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getAge();
			rows++;
		}
		columns++;
		rows = 0;
		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getExperience();
			rows++;
		}
		rows = 0;
		columns++;
		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getDetailsNumber();
			rows++;
		}
		columns++;
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				matrix[i][j] /= 100;
			}
		}
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows-1; j++) {
				weights[i] += matrix[i][j] * criteriasArray[j];
			}
		}
		cout << "Матрица предпочтений" << endl;
		cout << "K/Z ";
		int point = 0;
		while (point != columns) {
			cout << " Z" << point + 1<< " ";
			point++;
		}
		cout << endl;
		for (int i = 0; i < columns; i++) {
			cout << "K" << i + 1 << " ";
			for (int j = 0; j < rows; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "К1 - Возраст" << endl;
		cout << "К2 - Стаж" << endl;
		cout << "К3 - Оценка" << endl;
		cout << "Предпочтение целей : \n";
		for (int i = 0; i < columns; i++) {
			cout << weights[i] << " ";
		}
		cout << endl;
		delete[] matrix;
		delete weights;
	}
	else cout << "Ошибка в открытии БД!" << endl;
	dataBaseIsOpen.close();
}
