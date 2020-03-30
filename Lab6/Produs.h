#pragma once
#include <ostream>
using namespace std;
class Produs {
private:
	char* cod;
	char* nume;
	int pret;
public:
	Produs();
	Produs(const char*, const char*, int);
	Produs(const Produs&);
	char* getCod();
	char* getNume();
	int getPret();
	void setCod(const char*);
	void setNume(const char*);
	void setPret(int);
	Produs& operator= (const Produs&);
	bool operator == (const Produs&);
	~Produs();
	friend ostream& operator<<(ostream& os, const Produs& p);
};