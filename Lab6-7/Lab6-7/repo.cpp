#include "repo.h"
#include <string>
Repo<Carte>::Repo() {

}
void Repo<Carte>::addCarte(Carte carte)
{
	this->carti.push_back(carte);
}

void Repo<Carte>::deleteCarte(Carte carte) {
	deque<Carte>::iterator it;
	it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end()) {
		carti.erase(it);
	}
}

int Repo<Carte>::findCarte(Carte carte) {
	for (int i = 0; i < this->size(); i++)
	{
		if (carti[i] == carte)
			return i;
	}
	return -1;
}

void Repo<Carte>::updateCarte(Carte& carte) {
	for (size_t i = 0; i < carti.size(); i++)
		if (strcmp(this->carti[i].getTitlu(), carte.getTitlu()) == 0)
		{
			carti[i].setAutor(carte.getAutor());
			carti[i].setStatus(carte.getStatus());
		}
}
template<class Carte>
int Repo<Carte>::size() {
	return carti.size();
}

deque<Carte> Repo<Carte>::getAll() {
	return carti;
}
Repo<Carte>::~Repo() {}
