#include <memory>
#include <string>
#include <list>
#include "Hut.h"
#include "Farbe.h"
#include "Spieler.h"

Spieler::Spieler(Farbe f) {
	this->farbe = f;
	for (int i = 0; i < 4; i++) {
		huete.push_back(std::make_shared<Hut>(f));
	}
}

std::list<std::shared_ptr<Hut>> Spieler::getHuete() {
	return huete;
}

bool Spieler::hutAuswaehlen(Hut* hut) {
	return hut->isKontrollierbar();
}

/*void Spieler::hutBewegen(Hut* hut, int schritte) {
	if (hutAuswaehlen(hut) == false) {
		if (schritte == 6) {
			hut->
		}
	}
	if (hut->isZuHause() && schritte == 6) {
		//hut->aufsFeld();
		return true;
	}

	hut->bewegen(schritte);
	return true;
}*/