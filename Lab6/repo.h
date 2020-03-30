#pragma once
#include "Carte.h"
#include <deque>

using namespace std;
template<typename T>
class Repo {
private:
	deque<T> carti;
	
public:
	Repo();
	void addCarte(T);
	deque<T> getAll();
	~Repo();
	int size();
};

template<typename T>
Repo<T>::Repo() {

}
template<typename T>
Repo<T>::~Repo() {

}
template<typename T>
void Repo<T>::addCarte(T carte)
{
	this->carti.push_back(carte);
}
template<typename T>
int Repo<T>::size() {
	return this->carti.size();
}

template<typename T>
deque<T> Repo<T>::getAll() {
	return this->carti;
}