#pragma once

#include "Wuerfel.h"
#include <memory>
#include <vector>
#include "Spieler.h"
#include "Spielfeld.h"


class SpielerController {
public:
	SpielerController(const int spieleranzahl);
	void hutAuswaehlen(std::shared_ptr<Hut> hut);
	//void setFeld();
	//void hutBewegen(Hut* hut);
	void wuerfel();
	int getWuerfelergebnis() { return wuerfelergebnis; }
	//void connectToField(Spielfeld* spielbrett);
	//bool bewegen();
	std::unique_ptr<Spielfeld> Spielbrett;
	std::vector<std::unique_ptr<Spieler>> spieler;
private:
	std::unique_ptr<Wuerfel> dice;
	//std::vector<std::unique_ptr<Spieler>> spieler;
	//std::unique_ptr<Spielfeld> Spielbrett;
	int anzahl; //wie viele Spieler
	int wuerfelergebnis;
};