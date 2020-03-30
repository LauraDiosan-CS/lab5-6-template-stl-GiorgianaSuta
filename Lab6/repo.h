#pragma once
#include "produs.h"
#include <vector>
using namespace std;
class Repo {
private:
	vector<Produs> produse;;
	
public:
	Repo();
	void addProdus( Produs);
	vector<Produs> getAll();
	~Repo();
	int size();
};