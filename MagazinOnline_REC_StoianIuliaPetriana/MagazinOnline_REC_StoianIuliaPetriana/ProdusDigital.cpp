#include "ProdusDigital.h"
#include "Produs.h"
#include <iostream>
#include <string>


	//constructor fara parametri
	ProdusDigital::ProdusDigital() :Produs() {
		this->format = "NA";
		this->dimensiuneGb = 0.0;
	}

	//constructor cu toti parametrii
	ProdusDigital::ProdusDigital(string denumire, float pret, char* continut, bool inStoc, string format, float dimensiuneGb) :Produs(denumire, pret, continut, inStoc) {
		this->format = format;
		this->dimensiuneGb = dimensiuneGb;
	}

	//constructor de copiere
	ProdusDigital::ProdusDigital(const ProdusDigital& pr) :Produs(pr) {
		if (this != &pr) {
			if (this->continut != NULL) {
				delete[] this->continut;
			}
			this->format = pr.format;
			this->dimensiuneGb = pr.dimensiuneGb;
		}
	}
/*
	ProdusDigital::ProdusDigital(const Produs& p) :Produs(p) {
		if (this != &p){
			if (this->continut != NULL) {
				delete[] this->continut;
			}
		this->format = "NA";
		this->dimensiuneGb = 0.0f;
		}
	}
*/
	// getteri si setteri
	string ProdusDigital::getFormat() {
		return this->format;
	}

	float ProdusDigital::getDimensiuneGb() {
		return this->dimensiuneGb;
	}

	void ProdusDigital::setFormat(string format) {
		this->format = format;
	}

	void ProdusDigital::setDimensiuneGb(float dimensiuneGb) {
		this->dimensiuneGb = dimensiuneGb;
	}

	// operator = 
	ProdusDigital& ProdusDigital::operator=(const ProdusDigital& pr) {
		Produs::operator=(pr);
		this->format = pr.format;
		this->dimensiuneGb = pr.dimensiuneGb;
		return *this;
	}

	// operator <<
	ostream& operator<<(ostream& out, const ProdusDigital& pr)
	{
		out << (Produs&)pr;
		out << "Format: " << pr.format << endl;
		out << "\nDimensiune (GB): " << pr.dimensiuneGb << endl;
		return out;
	}

	// operator >>
	istream& operator>>(istream& in, ProdusDigital& pr) {
		in >> (Produs&)pr;
		cout << "Format: ";
		in >> pr.format;
		cout << "\nDimensiune (GB): ";
		in >> pr.dimensiuneGb;
		return in;
	}

