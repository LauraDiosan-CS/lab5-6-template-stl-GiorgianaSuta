#include "service.h"

void Service::addCarte(char* titlu, char* autor, char* status)
{
	Carte carte(titlu, autor, status);
	rep.addCarte(carte);
}
void Service::deleteCarte(Carte carte) {
	this->rep.deleteCarte(carte);
}
void Service::updateCarte(Carte& carte)
{
	this->rep.updateCarte(carte);
}
deque<Carte> Service::getAll() {
	return this->rep.getAll();
}
int Service::getSize() {
	return this->rep.size();
}

int Service::findCarte(Carte carte)
{
	return this->rep.findCarte(carte);
}
Service::~Service()
{

}