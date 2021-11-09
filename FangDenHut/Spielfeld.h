#pragma once
#include "Feld.h"
#include "Heimatfeld.h"
#include "LaufbahnView.h"
#include "StartbereichView.h"
#include <list>
#include <memory>

class Spielfeld {
public:
	Spielfeld(int n);
	std::list<std::shared_ptr<Feld>> getFelder() { return felder; }
	std::list<std::shared_ptr<Heimatfeld>> getHeimatfelder() { return h_felder; }
	std::shared_ptr<Feld> getFeldPerIndex(int x);
	void showSpielbrett();
	std::list<std::shared_ptr<Heimatfeld>> h_felder;
private:
	//std::list<std::shared_ptr<Heimatfeld>> h_felder;
	std::list<std::shared_ptr<Feld>> felder;
	int spieleranzahl;
	std::list<std::unique_ptr<StartbereichView>> s_view;
	std::unique_ptr<LaufbahnView> l_view;
};