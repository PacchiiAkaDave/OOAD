#include "Wuerfel.h"
#include <random>


int Wuerfel::wuerfeln() {
	return rand() % this->augenzahl + 1;
}
