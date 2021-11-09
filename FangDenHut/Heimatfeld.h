#pragma once

#include "Feld.h"
#include "Farbe.h"
#include "Hut.h"

class Hut;

class Heimatfeld {
public:
	Heimatfeld(Farbe f);
	void hueteKoppeln(std::list<std::shared_ptr<Hut>> huete);
	void releaseHut(Hut* hut);
	std::list<std::shared_ptr<Hut>> getHuete() { return huete; }
	std::list<std::shared_ptr<Hut>> huete;
	Farbe getFarbe() { return farbe; }
private:
	Farbe farbe;
	//std::list<std::shared_ptr<Hut>> huete;
};