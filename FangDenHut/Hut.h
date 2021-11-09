#pragma once

#include "Farbe.h"
#include <list>
#include <memory>
#include "Feld.h"
#include "Heimatfeld.h"

class Feld;
class Heimatfeld;

class Hut {
public:
	Hut(Farbe farbe);
	Feld* getPosition() { 
		return pos.get();
	};
	//void bewegen(int schritte); //erstmal ohne Richtung
	//bool hutEinnehmen(); 
	//void feldEinnehmen(Feld* pos);
	bool isKontrollierbar() { return kontrollierbar; }
	void setKontrollierbar(bool b) { kontrollierbar = b; }
	void leaveHome() { home.reset(); }
	void aufsFeld(std::shared_ptr<Feld> feld);
	Farbe getFarbe() { return farbe; }
	void setHome(std::shared_ptr<Heimatfeld> hf);
	std::shared_ptr<Heimatfeld> home;
private:
	Farbe farbe;
	bool kontrollierbar = false; //noch nicht modelliert
	//std::list<std::shared_ptr<Hut>> turm;
	std::shared_ptr<Feld> pos;
	//std::shared_ptr<Heimatfeld> home;
	//bool eingenommen;

};
