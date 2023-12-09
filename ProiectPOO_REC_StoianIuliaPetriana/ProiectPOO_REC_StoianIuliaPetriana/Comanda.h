#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
#include <string>
#include <fstream>
#include "Produs.h"

using namespace std;

class Comanda
{
private:
	const int idComanda;
	Produs* produse;
	int indexProdusCurent;
	int capacitate;
	int dimensiune;

public:
	static int nrProduse;

	// destructor
	~Comanda();

	// constructor fara parametri
	Comanda();

	// constructor cu 1 parametru
	Comanda(int id);
		

	// constructor cu 2 parametri
	Comanda(int initC, int id);

	// constructor de copiere
	Comanda(const Comanda& c);

	// operator =
	Comanda& operator=(const Comanda& c);

	// getter si setter
	static int getNrProduse();

	Produs* getProduse();

	int getIdComanda() const;

	void setProduse(Produs* newProduse);

	int getIndexProdusCurent();

	void setIndexProdusCurent(int indexProdusCurent);

	// operatori de citire si afisare

	// operator >>
	friend istream& operator>>(istream& in, Comanda& c);

	// operator <<
	friend ostream& operator<<(ostream& out, const Comanda& c);


	// operator +=
	Comanda& operator+=(const Produs& prod);

	// operator -=
	Comanda& operator-=(const Produs& prod);

	// serializare/deserializare fisier binar
	// serializare
	void exportBinar(string numeFisier);

	// deserializare
	void importBinar(string numeFisier);
};

#endif COMANDA_H