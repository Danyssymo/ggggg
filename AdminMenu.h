#pragma once
#include "UserMenu.h"
#include "Worker.h"
class AdminMenu : public UserMenu,public Worker {
public:
	void adminMenu();
	void insert();
	void redact();
	void erase();
	void fileCreating();
	void fileInsert();
};