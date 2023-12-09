#include "Comanda.h" 
#include "Main.h"
#include "Produs.h" 
#include "ProdusDigital.h" 
#include "ProdusFizic.h" 
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    char denumire1[] = "Produs1";
    char continut1[] = "Description1";
    char denumire2[] = "Produs2";
    char continut2[] = "Description2";

    Produs p1(denumire1, 10.0, continut1, true);
    Produs p2(denumire2, 15.0, continut2, false);
    cout << p1 << endl;
    cout << p2 << endl;
 //   cout << "test1" << endl;
    Produs p3;
    cin >> p3;
  //  cout << "test2" << endl;
    Comanda c(1); 
  //  cout << "test3" << endl;
    c += p1; 
  //  cout << "test4" << endl;
    cout << c; 
    return 0;
}