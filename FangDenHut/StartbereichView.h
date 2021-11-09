#pragma once

#include "View.h"
#include "Farbe.h"
#include "Heimatfeld.h"

class StartbereichView : public View {
public:
	StartbereichView(Farbe f);
	void show();
	//void modelChanged();
	void setHeimatfeld(std::shared_ptr<Heimatfeld> h);
private:
	Farbe f;
	std::shared_ptr<Heimatfeld> h_feld;
};
