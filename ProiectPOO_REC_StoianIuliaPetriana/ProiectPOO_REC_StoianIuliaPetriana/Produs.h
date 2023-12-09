#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <string>

using namespace std;

class Produs
{
protected:
	const int idProdus;
	char* denumire;
	float pret;
	char* continut;
	bool inStoc;
	
public:
	static int nextId;

	// destructor
	~Produs();

	// constructor fara parametri
	Produs();

	// constructor cu toti parametrii
	Produs(char* denumire, float pret, char* continut, bool inStoc);

	// constructorul de copiere
	Produs(const Produs& p);

	// getteri si setteri
	int getIdProdus() const;

	char* getDenumire();

	float getPret();

	char* getContinut();

	bool getInStoc();

	void setDenumire(char* denumire);

	void setPret(float pret);

	void setContinut(char* continut);

	void setInStoc(bool inStoc);

	// operator =
	Produs& operator=(const Produs& p);

	// operator >>
	friend istream& operator>>(istream& in, Produs& p);

	// operator <<
	friend ostream& operator<<(ostream& out, const Produs& p);

	bool operator==(const Produs& other) const;
};

#endif PRODUS_H