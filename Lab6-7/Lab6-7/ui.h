#pragma once
#include "service.h"
class UI {
public:
	void run();
	void setService(const Service&);
private:
	Service service;
	void addCarte();
	void deleteCarte();
	void updateCarte();
	void afisare();
	void imprumut();
	void returnare();
};