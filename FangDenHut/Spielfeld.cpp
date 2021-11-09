#include "Spielfeld.h"
#include "LaufbahnView.h"
#include "StartbereichView.h"
#include <memory>
#include "Farbe.h"
#include "Feld.h"
#include <list>
#include <iostream>

Spielfeld::Spielfeld(int n) {
	spieleranzahl = n;
	
	for (int i = 0; i < n; i++) {
		h_felder.push_back(std::make_shared<Heimatfeld>(static_cast<Farbe>(i)));
		s_view.push_back(std::make_unique<StartbereichView>(static_cast<Farbe>(i)));
		std::list<std::shared_ptr<Heimatfeld>>::iterator it = h_felder.begin();
		std::list<std::unique_ptr<StartbereichView>>::iterator sv = s_view.begin();
		std::advance(it, i);
		std::advance(sv, i);
		sv->get()->setHeimatfeld(*it);
	}



	//**** NEEDS TO BE FIXED ****//
	/*for (std::list<std::shared_ptr<Heimatfeld>>::iterator it = h_felder.begin(); it != h_felder.end(); ++it) {
		s_view.push_back(std::make_unique<StartbereichView>(it->get()->getFarbe()));
		std::shared_ptr<Heimatfeld> tmp = *it;
		s_view.begin()->get()->setHeimatfeld(tmp);
	}*/


	for (int i = 0; i < 50; i++) {
		felder.push_back(std::make_shared<Feld>(Feld(i)));
	}

	l_view = std::make_unique<LaufbahnView>(LaufbahnView(felder));

}


std::shared_ptr<Feld> Spielfeld::getFeldPerIndex(int x) {
	auto tmp = felder.begin();

	std::advance(tmp, x);

	return *tmp;
}


void Spielfeld::showSpielbrett() {
	l_view.get()->show();

	for (std::list<std::unique_ptr<StartbereichView>>::iterator it = s_view.begin(); it != s_view.end(); ++it) {
		it->get()->show();
	}
}