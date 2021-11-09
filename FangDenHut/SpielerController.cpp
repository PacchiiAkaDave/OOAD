#include "SpielerController.h"
#include <memory>
#include <vector>
#include "Spieler.h"
#include "Farbe.h"


SpielerController::SpielerController(int anzahl) {
	this->dice = std::make_unique<Wuerfel>();
	this->anzahl = anzahl;
	for (int i = 0; i < anzahl; i++) {
		spieler.push_back(std::make_unique<Spieler>(Spieler(static_cast<Farbe>(i))));
	}

}


void SpielerController::wuerfel() {
	wuerfelergebnis = this->dice->wuerfeln();
}

void SpielerController::hutAuswaehlen(std::shared_ptr<Hut> hut) {
	if (hut->isKontrollierbar() == false) {
		if (wuerfelergebnis == 6) {
			hut->aufsFeld(Spielbrett.get()->getFeldPerIndex(0));
			hut->getPosition()->hutNimmtEin(hut);
			hut->getPosition()->setBesetzt(true);
			hut->setKontrollierbar(true);
			
			hut->home->releaseHut(hut.get());

			hut->leaveHome();
			return;
		} 
		return;
	}
	int tmp = hut->getPosition()->koordinate;
	Spielbrett.get()->getFeldPerIndex(tmp)->hutLeaves();
	Spielbrett.get()->getFeldPerIndex(tmp)->setBesetzt(false);
	tmp += wuerfelergebnis;
	while (Spielbrett.get()->getFeldPerIndex(tmp)->isBesetzt()) {
		tmp--;
	}
	hut->aufsFeld(Spielbrett.get()->getFeldPerIndex(tmp));
	Spielbrett.get()->getFeldPerIndex(tmp).get()->setBesetzt(true);
	hut->getPosition()->hutNimmtEin(hut);
}

/*void SpielerController::connectToField(Spielfeld* spielfeld) {
	this->Spielbrett = std::make_unique<Spielfeld>(spielfeld);
}*/

