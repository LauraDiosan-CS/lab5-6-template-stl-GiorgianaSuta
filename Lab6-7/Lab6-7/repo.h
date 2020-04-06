#pragma once
#include "Carte.h"
#include <deque>

using namespace std;
template<class Carte>
class Repo {
protected:
	deque<Carte> carti;

public:
	Repo();
	void addCarte(Carte);
	void deleteCarte(Carte);
	void updateCarte(Carte& c);
	int findCarte(Carte);
	deque<Carte> getAll();
	~Repo();
	int size();
};

