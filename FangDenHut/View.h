#pragma once
#include <string>

class View {
public:
	virtual void show() = 0;
	void printText(int text);
};