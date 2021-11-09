#include "StartbereichView.h"
#include "Heimatfeld.h"
#include "Farbe.h"
#include <list>
#include <iostream>


StartbereichView::StartbereichView(Farbe f) {
	this->f = f;
}


void StartbereichView::setHeimatfeld(std::shared_ptr<Heimatfeld> h)
{
	h_feld = h;
}

void StartbereichView::show() {
	std::cout << "Startbereich(" << this->f << "):\n";
	int x = 0;
	for(std::list<std::shared_ptr<Hut>>::iterator it = h_feld.get()->huete.begin(); it != h_feld.get()->huete.end(); ++it){
		if (it->get() == nullptr) continue;
		x++;
	}

	std::cout << x << "X\n\n";
}