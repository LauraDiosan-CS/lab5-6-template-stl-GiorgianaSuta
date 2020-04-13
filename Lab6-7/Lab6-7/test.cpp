#include "test.h"

#include "RepoFile.h"
#include "service.h"
#include <assert.h>
#include <string>
#include <deque>
void testService() {
	RepoFile<Carte> rep;
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
	service.updateCarte(c1,c2);
	assert(service.getSize() == 1);
	service.deleteCarte(c2);
	assert(service.getSize() == 0);
}
void testImprumutRetur() {
	RepoFile<Carte> rep;
	deque<Carte> carti;
	Service service;
	const char* fileIn = "carti.txt";
	const char* fileOut = "cartiOut.txt";
	rep.setFileIn(fileIn);
	rep.load_from_file();
	rep.setFileOut(fileOut);
	char titlu[50] = "ion";
	char autor[50] = "pavel";
	Carte c(titlu, autor, "");
	service.setRepo(rep);
	service.imprumut(titlu, autor);
	int n = service.findCarte(c);
	char status[20] = "imprumutata";
	char status2[30] = "disponibila";
	assert(strcmp(service.getAll()[n].getStatus(), status) == 0);
	service.returnare(titlu);
	assert(strcmp(service.getAll()[n].getStatus(), status2) == 0);

}
void testRepo() {
	RepoFile<Carte> rep;
	deque<Carte> carti;
	const char* fileIn = "carti.txt";
	const char* fileOut = "cartiOut.txt";
	rep.setFileIn(fileIn);
	rep.load_from_file();
	assert(rep.size() == 3);
	Carte c("ion", "g"," ");
	rep.addCarte(Carte("ion", "g", ""));
	rep.saveToFile(fileOut);
	assert(rep.size() == 4);
	rep.deleteCarte(c);
	rep.saveToFile(fileOut);
	assert(rep.size() == 3);
}