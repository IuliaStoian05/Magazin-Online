#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <string>

using namespace std;

class Produs {
protected:
	const int idProdus;
	string denumire;
	float pret;
	char* continut;
	bool inStoc;
	static int nextId;
public:
	// destructor
	~Produs();

	// constructor fara parametri
	Produs();

	// constructor cu 1 parametru
	Produs(string denumire);

	// constructor cu 2 parametri
	Produs(string denumire, float pret);

	// constructor cu 3 parametri
	Produs(string denumire, float pret, char* continut);


	// constructor cu toti parametrii
	Produs(string denumire, float pret, char* continut, bool inStoc);

	// constructorul de copiere
	Produs(const Produs& p);

	// getteri si setteri
	int getIdProdus() const;

	string getDenumire();

	float getPret();

	char* getContinut();

	bool getInStoc();

	void setDenumire(string denumire);

	void setPret(float pret);

	void setContinut(char* continut);

	void setInStoc(bool inStoc);

	// operator =
	Produs& operator=(const Produs& p);

	// operator ==
	bool operator==(const Produs& other) const;

	// operator >>
	friend istream& operator>>(istream& in, Produs& p);

	// operator <<
	friend ostream& operator<<(ostream& out, const Produs& p);
};


#endif PRODUS_H