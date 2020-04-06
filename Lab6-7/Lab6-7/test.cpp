#include "test.h"
#include "repo.h"
#include "service.h"
#include <assert.h>
#include <string>
#include <deque>
void test() {
	Repo<Carte> rep;
	Service service;
	char titlu[100] = "Albastru";
	char autor[100] = "negru";
	char status[20] = "imprumutat";
	Carte c1(titlu, autor, status);
	service.addCarte(titlu, autor, status);
	assert(service.getSize() == 1);
	deque<Carte> carti = service.getAll();
	char autor1[100] = "Ion";
	char status1[20] = "disponibil";
	Carte c2(titlu, autor1, status1);
	service.updateCarte(c2);
	assert(service.getSize() == 1);
	service.deleteCarte(c2);
	assert(service.getSize() == 0);
}