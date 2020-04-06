#pragma once
#include "service.h"
class UI {
public:
	void run();
private:
	Service service;
	void addCarte();
	void deleteCarte();
	void updateCarte();
	void afisare();
};