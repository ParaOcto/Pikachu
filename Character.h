#pragma once
#include<iostream>
#include"Button.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>

struct Pokemon{
	int x, y;
	std::string k;
	Button Char;

	void GenRanDomChar(std::string &k) {
		char tmp = ('A' + rand() % 26);
		k += tmp;
	}

	void setText(Button Char,std::string k) {
		Char.text.setString(k);
	}
};