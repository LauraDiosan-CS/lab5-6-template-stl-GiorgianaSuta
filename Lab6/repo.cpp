#include "repo.h"
#include <iostream>

using namespace std;

Repo::Repo() {
	
}

void Repo::addProdus( Produs p)
{
	produse.push_back(p);
}

vector<Produs> Repo::getAll() {
	return produse;
}
int Repo::size() {
	return produse.size();
}
Repo::~Repo() {
	
}