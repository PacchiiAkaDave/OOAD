#include "View.h"
#include <list>
#include <memory>
#include "Feld.h"
#include "LaufbahnView.h"
#include <iostream>

LaufbahnView::LaufbahnView(std::list<std::shared_ptr<Feld>> felder) {
	this->felder = felder;
}

void LaufbahnView::show() {
	
	std::cout << "Laufbahn" << std::endl;
	for (std::list<std::shared_ptr<Feld>>::iterator it = felder.begin(); it != felder.end(); ++it) {
		std::cout << it->get()->getKoordinate();
		if (it->get()->isBesetzt()) {
			std::cout << "(" << it->get()->getHut()->getFarbe() << ")";
		}
		std::cout << "\t";
	}
	std::cout << "\n\n";
}