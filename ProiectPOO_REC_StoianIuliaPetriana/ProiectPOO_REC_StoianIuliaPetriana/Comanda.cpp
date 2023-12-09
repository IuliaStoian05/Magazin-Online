#include "Comanda.h"
#include "Produs.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//initializare membru static
int Comanda::nrProduse = 0;

Comanda::~Comanda() {
	if (this->produse != NULL) {
		delete[]this->produse;
	}
	nrProduse--;
}

// constructor fara parametri
Comanda::Comanda() : idComanda(0), produse(nullptr), capacitate(0), dimensiune(0) {
	nrProduse++;
}

// constructor cu parametri
Comanda::Comanda(int initC, int id) : idComanda(id), capacitate(initC), dimensiune(0) {
	produse = new Produs[capacitate];
	nrProduse++;
}

Comanda::Comanda(int id) : idComanda(id), produse(new Produs[capacitate]), indexProdusCurent(0) {
	
}

// constructor de copiere
Comanda::Comanda(const Comanda& c) : idComanda(c.idComanda), capacitate(c.capacitate), dimensiune(c.dimensiune) {
	produse = new Produs[capacitate];
	for (int i = 0; i < dimensiune; ++i) {
		produse[i] = c.produse[i];
	}
	nrProduse++;
}

// operator =
Comanda& Comanda::operator=(const Comanda& c) {
	if (this != &c) {
		delete[] produse;
		//idComanda = c.idComanda;
		capacitate = c.capacitate;
		dimensiune = c.dimensiune;
		produse = new Produs[capacitate];
		for (int i = 0; i < dimensiune; ++i) {
			produse[i] = c.produse[i];
		}
	}
	return *this;
}

// getteri si setteri
int Comanda::getIdComanda() const {
	return this->idComanda;
}

Produs* Comanda::getProduse() {
	return this->produse;
}

void Comanda::setProduse(Produs* newProduse) {
	this->produse = newProduse;
}

int Comanda::getIndexProdusCurent() {
	return this->indexProdusCurent;
}

void Comanda::setIndexProdusCurent(int newIndex) {
	this->indexProdusCurent = newIndex;
}

// operatori de citire si afisare
	// operator <<
ostream& operator<<(ostream& out, const Comanda& c) {
	out << "ID Comanda: " << c.idComanda << endl;
	out << "Produse: " << endl;
	for (int i = 0; i < c.indexProdusCurent; ++i) {
		out << c.produse[i] << endl;
	}
	out << endl;
	return out;
}

// operator >>
istream& operator>>(istream& in, Comanda& c) {
	for (int i = 0; i < 10000; ++i) {
		char denumire[100]; 
		float pret;
		char continut[100]; 
		bool inStoc;

		cout << "Produs " << i + 1 << ":" << endl;

		cout << "Denumire: ";
		in >> denumire;

		cout << "Pret: ";
		in >> pret;

		cout << "Continut: ";
		in >> continut;

		cout << "In stoc (1 for true, 0 for false): ";
		in >> inStoc;

		Produs newProdus(denumire, pret, continut, inStoc);
		c += newProdus; 
	}

	return in;
}

Comanda& Comanda::operator+=(const Produs& prod) {
	if (indexProdusCurent < capacitate) {
		produse[indexProdusCurent++] = prod;
		dimensiune++;
	}
	else {
		cout << "Ati depasit capacitatea." << endl;
	}
	return *this;
}

Comanda& Comanda::operator-=(const Produs& prod) {
	for (int i = 0; i < indexProdusCurent; ++i) {
		if (produse[i] == prod) {
			for (int j = i; j < indexProdusCurent - 1; ++j) {
				produse[j] = produse[j + 1];
			}
			indexProdusCurent--;
		}
	}
	return *this;
}