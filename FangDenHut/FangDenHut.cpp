#include "FangDenHut.h"
#include "SpielerController.h"
#include <list>
#include <vector>
#include <memory>
#include "Heimatfeld.h"
#include <iostream>

void FangDenHut::starteSpiel(int anzahl) {
	controller = std::make_unique<SpielerController>(anzahl);
	controller->Spielbrett = std::make_unique<Spielfeld>(anzahl);

	//std::cout << &controller.get()->Spielbrett.get()->getHeimatfelder() << std::endl;

	std::vector<std::unique_ptr<Spieler>>::iterator sp = controller.get()->spieler.begin();

	for (std::list<std::shared_ptr<Heimatfeld>>::iterator it = controller.get()->Spielbrett.get()->h_felder.begin(); it != controller.get()->Spielbrett.get()->h_felder.end(); ++it) {
		it->get()->hueteKoppeln(sp->get()->huete);
		for (std::list<std::shared_ptr<Hut>>::iterator hut = sp->get()->huete.begin(); hut != sp->get()->huete.end(); ++hut) {
			hut->get()->setHome(*it);
		}
		++sp;
	}

	int hutNo = 0;
	

	while (true) {
		for (std::vector<std::unique_ptr<Spieler>>::iterator player = controller.get()->spieler.begin(); player != controller.get()->spieler.end(); ++player) {

			//std::cout << "Spieler " << player->get()->getFarbe() << " ist dran!\n";
			controller.get()->Spielbrett.get()->showSpielbrett();

			controller.get()->wuerfel();
			std::cout << "Spieler " << player->get()->getFarbe() << " ist dran!\n";
			std::cout << controller.get()->getWuerfelergebnis() << std::endl;


			do {
				std::cin >> hutNo;
			} while (hutNo < 1 || hutNo > 4);
			--hutNo;


			std::list<std::shared_ptr<Hut>>::iterator hut = player->get()->huete.begin();

			std::advance(hut, hutNo);

			controller.get()->hutAuswaehlen(*hut);

		}
	}
	
}



