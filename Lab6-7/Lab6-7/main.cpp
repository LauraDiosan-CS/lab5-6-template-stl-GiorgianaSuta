#include <iostream>
#include "ui.h"
#include "test.h"

using namespace std;

void initService(Service& s)
{
	RepoFile<Carte> r("carti.txt", "cartiOut.txt");
	s.setRepo(r);
}
int main() {
	testService();
	testRepo();
	testImprumutRetur();
	Service serv;
	initService(serv);
	UI ui;
	ui.setService(serv);
	ui.run();
	return 0;
}