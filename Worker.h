#pragma once
#include "Factory.h"

class Worker
	:public Factory
{
protected:
	string name, surname;
	double experience;
	int age, detailsNumber;
public:
	Worker() {
		name = surname = "";
		experience = age = detailsNumber = 0;
	}
	string getSurname();
	string getName();
	double getExperience();
	int getDetailsNumber();
	int getAge();
	friend ostream& operator >> (fstream & stream, Worker&worker);
	friend istream& operator >> (istream & stream, Worker&worker);
	friend ostream& operator << (ostream & stream, Worker&worker);
	friend ostream& operator << (fstream & stream, Worker&worker);
};