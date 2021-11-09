#include "Heimatfeld.h"
#include "Farbe.h"
#include <memory>

Heimatfeld::Heimatfeld(Farbe f){
	farbe = f;
	
}

void Heimatfeld::releaseHut(Hut* hut)
{
	for (std::list<std::shared_ptr<Hut>>::iterator it = huete.begin(); it != huete.end(); ++it) {
		if (hut == it->get()) {
			it->reset();
			return;
		}
	}
}

void Heimatfeld::hueteKoppeln(std::list<std::shared_ptr<Hut>> huete) {
	this->huete = huete;
}