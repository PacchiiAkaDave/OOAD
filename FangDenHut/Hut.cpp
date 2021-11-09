#include "Hut.h"
#include "Farbe.h"


Hut::Hut(Farbe f) {
	this->farbe = f;
}

void Hut::aufsFeld(std::shared_ptr<Feld> feld) {
	pos.reset();
	pos = feld;
}

void Hut::setHome(std::shared_ptr<Heimatfeld> hf) {
	home.reset();
	home = hf;
}