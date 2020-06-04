#include "Bools.h"
#pragma once

bool checkString(string str)
{
	string acceptedSymbolsToUpperCase = "јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
	string acceptedSymbolsToLowerCase = "абвгдеЄжзийклмнопрстуфхцчшщъыьэю€";
	string symbols = "`~@#$%^&*(),+-=/{}|\<>?:' ";
	if (str.length() >= 2) {
		int count1 = 0, count2 = 0;
		for (int i = 0; i < symbols.length(); i++) {
			if (symbols[i] == str[0]) {
				red cout << "ѕерва€ буква не может быть символом!" << endl; white
					return false;
			}
		}
		if (str[0] >= '0' && str[0] <= '9') {
			red cout << "ѕерва€ буква не может быть числом!" << endl; white
				return false;
		}
		if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')) {
			red cout << "ѕерва€ буква должна быть из кириллицы!" << endl; white
				return false;
		}
		for (int i = 0; i < acceptedSymbolsToUpperCase.length(); i++) {
			if (acceptedSymbolsToUpperCase[i] != str[0]) count1++;
			else break;
		}
		if (str[0] == acceptedSymbolsToUpperCase[count1]) {
			for (int i = 1; i < str.length(); i++) {
				for (int j = 0; j < symbols.length(); j++) {
					if (symbols[j] == str[i]) {
						red cout << i << "-€ буква не может быть символом!" << endl; white
							return false;
					}
				}
				if (str[i] >= '0' && str[i] <= '9') {
					red cout << i << "-€ буква не может быть числом!" << endl; white
						return false;
				}
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
					cout << i << "-€ буква должна быть из кириллицы!" << endl;
					return false;
				}
				for (int j = 0; j < acceptedSymbolsToLowerCase.length(); j++) {
					if (str[i] == acceptedSymbolsToLowerCase[j]) count2++;
					else break;
				}
			}
			if (count2 != str.length() - 1) return true;
			else {
				red cout << "¬тора€ и далее буквы должны быть в нижнем регистре" << endl; white
					return false;
			}
		}
		else {
			red cout << "ѕерва€ буква должна быть в верхнем регистре" << endl; white
				return false;
		}
	}
	else {
		cout << "ѕоле должно состо€ть не менее, чем из 2-х символов" << endl;
		return false;
	}
}

bool checkNumber(double number)
{
	string acceptedSymbolsToUpperCase = "јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
	string acceptedSymbolsToLowerCase = "абвгдеЄжзийклмнопрстуфхцчшщъыьэю€";
	string symbols = "`~@#$%^&*(),+-=/{}|\<>?:' ";
	return true;
}
