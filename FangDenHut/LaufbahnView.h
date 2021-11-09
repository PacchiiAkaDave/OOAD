#pragma once

#include "View.h"
#include <list>
#include <memory>
#include "Feld.h"
#include "Heimatfeld.h"

class LaufbahnView : public View {
public:
	LaufbahnView(std::list<std::shared_ptr<Feld>> felder);
	void show();
	//void modelChanged();
	

private:
	std::list<std::shared_ptr<Feld>> felder;
	//std::list<std::shared_ptr<Heimatfeld>> h_felder;
};