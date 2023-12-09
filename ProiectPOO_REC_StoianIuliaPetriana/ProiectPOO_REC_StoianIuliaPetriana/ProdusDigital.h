#ifndef PRODUSDIGITAL_H
#define PRODUSDIGITAL_H
#include "Produs.h"
#include <iostream>
#include <string>

using namespace std;

class ProdusDigital :public Produs
{
protected:
	string format;
	float dimensiuneGb;

public:

	//constructor fara parametri
	ProdusDigital();

	//constructor cu toti parametrii
	ProdusDigital(char* denumire, float pret, char* continut, bool inStoc, string format, float dimensiuneGb);

	//constructor de copiere
	ProdusDigital(const ProdusDigital& pr);

	ProdusDigital(const Produs& p);

	// getteri si setteri
	string getFormat();

	float getDimensiuneGb();

	void setFormat(string format);

	void setDimensiuneGb(float dimensiuneGb);

	// operator = 
	ProdusDigital& operator=(const ProdusDigital& pr);
	// operator <<
	friend ostream& operator<<(ostream& out, const ProdusDigital& pr);
	// operator >>
	friend istream& operator>>(istream& in, ProdusDigital& pr);

};

#endif PRODUSDIGITAL_H
