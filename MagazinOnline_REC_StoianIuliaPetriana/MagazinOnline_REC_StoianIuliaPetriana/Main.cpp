#include "Comanda.h" 
#include "Main.h"
#include "Produs.h" 
#include "ProdusDigital.h" 
#include "ProdusFizic.h" 
#include <fstream>
#include <iostream>
#include <string>

int main() {
      
        cout << "------Creare produse------" << endl;

        
        Produs p1("ABC");
        p1.setPret(12345.3);
        char content[] = "Produs, incarcator";
        p1.setContinut(content);
        p1.setInStoc(1);
        cout << p1;
        cout << endl;
        cout << endl;
        cout << endl;

        Produs p2("ABCD");
        p2.setPret(1000.0);
        char content2[] = "Produs";
        p2.setContinut(content2);
        p2.setInStoc(0);
        cout << p2;
        cout << endl;
        cout << endl;
        cout << endl;

        Produs p3();
    //    p3 = p1;

        cout << "Produs ID 1: " << p1.getIdProdus() << endl;
        cout << "Produs ID 2: " << p2.getIdProdus() << endl;

        cout << "------Creare produs digital------" << endl;
        char contentDigital[] = "Produs in format .pdf";
        ProdusDigital pd1("DEF", 122.25, contentDigital, 0, "PDF", 1);
        cout << pd1;
        cout << endl;
        cout << endl;
        cout << endl;
  
        cout << "------Creare produs fizic------" << endl;
        char contentFizic[] = "Produs, incarcator, manual instructiuni";
        float dimensiuni[3] = { 1,2,3 };
        ProdusFizic pf1("GHI",123456.0,contentFizic,1,10,dimensiuni);
        pf1.setGreutateKg(2);
        cout << pf1;
        cout << endl;
        cout << endl;
        cout << endl;

        cout << "------Creare comanda------" << endl;
        try {
            Comanda c(1);
            c += p1;
            c += p2;
            //   c += p3;
            c -= p1;
            Produs* produse = c.getProduse();
            for (int i = 0; i < c.getIndexProdusCurent(); ++i) {
                cout << produse[i];
            }
        }
        catch(const char* message){
            cerr << "Exceptiune";
        }

    return 0;
}