#pragma once

#include "Spielfeld.h"
#include "Spieler.h"
#include "SpielerController.h"

class FangDenHut {
public:
	void starteSpiel(int anzahl);
	std::unique_ptr<SpielerController> controller;
	//SpielerController* erstelleSpieler(int anzahl);
	//bool hatGewonnen();
	//Spielfeld* erstelleSpielfeld();
private:
	//Spielfeld* erstelleSpielfeld(int anzahl);
};
