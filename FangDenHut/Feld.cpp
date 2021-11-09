#include "Feld.h"
#include "Hut.h"
#include <memory>

void Feld::hutNimmtEin(std::shared_ptr<Hut> h) {
	this->hut = h;
};

void Feld::hutLeaves() {
	hut.reset();
};