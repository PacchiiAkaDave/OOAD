#pragma once

#include "Hut.h"
#include <memory>
#include <list>

class Hut;

class Feld {
public:
	Feld() {
		this->koordinate = -1;
		this->besetzt = true;
	}
	Feld(int koordinate) {
		this->koordinate = koordinate;
		this->besetzt = false;
	}
	bool isBesetzt() {
		return besetzt;
	}
	void setBesetzt(bool b) { besetzt = b; };
	void hutLeaves();
	void hutNimmtEin(std::shared_ptr<Hut> h);

	Hut* getHut() {
		return hut.get();
	}

	int getKoordinate() {
		return koordinate;
	}
	//bool hasEnemyHut(Hut* hut);

	int koordinate;
private:
	bool besetzt = false; //neu
	std::shared_ptr<Hut> hut;
};
