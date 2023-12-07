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

public:
	static int nrProduse;

	// destructor
	~Comanda();

	// constructor fara parametri
	Comanda();

	// constructor cu parametri
	Comanda(Produs* prod);

	Comanda(int id);

	// constructor de copiere
	Comanda(const Comanda& c);

	// operator =
	Comanda& operator=(const Comanda& c);

	// getter si setter
	static int getNrProduse();

	Produs* getProduse();

	int getIdComanda() const;

	void setProduse(Produs* produse, int size);

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

#endif
