#pragma once
#include <ostream>
using namespace std;
class Carte {
private:
	char* titlu;
	char* autor;
	char* status;
public:
	Carte();
	Carte(const char*, const char*, const char*);
	Carte(const Carte&);
	char* getTitlu();
	char* getAutor();
	char* getStatus();
	void setTitlu(const char*);
	void setAutor(const char*);
	void setStatus(const char*);
	Carte& operator= (const Carte&);
	bool operator == (const Carte&);
	~Carte();
	friend ostream& operator<<(ostream& os, const Carte& p);
	friend istream& operator >>(istream& is, Carte& c);
};