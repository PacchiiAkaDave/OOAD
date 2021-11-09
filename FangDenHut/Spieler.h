#pragma once
#include <memory>
#include <string>
#include <list>
#include "Hut.h"
#include "Farbe.h"

class Spieler {
public:
	Spieler(Farbe f);
	//void hutBewegen(Hut* hut , int schritte); // neuer Para
	bool hutAuswaehlen(Hut* hut);
	std::list<std::shared_ptr<Hut>> getHuete();
	std::list<std::shared_ptr<Hut>> huete;
	Farbe getFarbe() {
		return farbe;
	};
private:
	std::string name;
	Farbe farbe;
	//std::list<std::shared_ptr<Hut>> huete;
	//std::list<std::shared_ptr<Hut>> eroberteHuete;
	//aktuelles huetchen
};