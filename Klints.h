#pragma once
#include "Libraries.h"

class Factory
{
protected:
	string factoryName;
	string personPosition;
public:
	string getFactoryName();
	string getPersonPosition();
};
