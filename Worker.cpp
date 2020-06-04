#include "Worker.h"
#include "Bools.h"

ostream & operator>>(fstream & stream, Worker & worker)
{
	stream >> worker.factoryName >> worker.surname >> worker.name >> worker.personPosition >> worker.age >> worker.experience >> worker.detailsNumber;
	return stream;
}

istream & operator>>(istream & stream, Worker & worker)
{
	while (1) {
		cout << "Название тренажера" << endl;
		stream >> worker.factoryName;
		if (checkString(worker.factoryName)) break;
		else worker.factoryName = "";
	}
	while (1) {
		cout << "Введите фамилию клиента" << endl;
		stream >> worker.surname;
		if (checkString(worker.surname)) break;
		else worker.surname = "";
	}
	while (1) {
		cout << "Введите имя клиента" << endl;
		stream >> worker.name;
		if (checkString(worker.name)) break;
		else worker.name = "";
	}
	while (1) {
		cout << "Отчество клиента" << endl;
		stream >> worker.personPosition;
		if (checkString(worker.personPosition)) break;
		else worker.personPosition = "";
	}
	while (1) {
		cout << "Возраст клиента" << endl;
		stream >> worker.age;
		if (checkNumber(worker.age)) break;
		else worker.age = 0;
	}
	while (1) {
		cout << "Стаж (кол-во посещенных дней) клиента" << endl;
		stream >> worker.experience;
		if (checkNumber(worker.experience)) break;
		else worker.experience = 0;
	}
	while (1) {
		cout << "Оценка клиента" << endl;
		stream >> worker.detailsNumber;
		if (checkNumber(worker.detailsNumber)) break;
		else worker.detailsNumber = 0;
	}
	return stream;
}

ostream & operator<<(ostream & stream, Worker & worker)
{
	stream << "|" << setw(25) << worker.getFactoryName() << "|" << setw(25) << worker.getSurname() << "|" << setw(25) << worker.getName() << "|" << setw(25) << worker.getPersonPosition() << "|" << setw(25) << worker.getAge() << "|" << setw(25) << worker.getExperience() << "|" << setw(25) << worker.getDetailsNumber() << "|";
	return stream;
}

ostream & operator<<(fstream & stream, Worker & worker)
{
	stream << worker.getFactoryName() << " " << worker.getSurname() << " " << worker.getName() << " " << worker.getPersonPosition() << " " << worker.getAge() << " " << worker.getExperience() << " " << worker.getDetailsNumber();
	return stream;
}

string Worker::getSurname()
{
	return surname;
}

string Worker::getName()
{
	return name;
}

double Worker::getExperience()
{
	return experience;
}

int Worker::getDetailsNumber()
{
	return detailsNumber;
}

int Worker::getAge()
{
	return age;
}
