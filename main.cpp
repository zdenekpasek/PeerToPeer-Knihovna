#include <iostream>
#include <string>
#include "Kniha.h"
#include "Osoba.h"

using namespace std;



int main() {

    cout << "Vitejte v Peer-to-peer knihovne." << endl << endl;
    cout << "Co chcete udelat?" << endl;
    cout << "Sprava uzivatelu (1)" << endl;
    cout << "Uprava kniznich fondu (2)" << endl;
    cout << "Vypis vypujcek (3)" << endl;
    cout << "Dostupnost knih (4)" << endl;

    Osoba o1("Adolf", "Novak", "9.12. 1990");
    Osoba o2;



    int volba;
    int vyber;
    string jmeno;
    cin >> volba;

    switch(volba) {
        case 1:
            cout << string(2, '\n');
            cout << "Pridani uzivatele (1)" << endl;
            cout << "Odstraneni uzivatele (2)" << endl;

            cin >> vyber;

            switch (vyber){
                case 1:


                    cout << "Zadejte jmeno: " << endl;
                    cin >> jmeno;
                    o2.setJmeno(jmeno);
                    cout << "Zadejte prijmeni: " << endl;
                    cout << "Zadejte datum narozeni: " << endl;
                    cout << o2.getJmeno();

                    break;



                case 2:
                    cout << "Zadejte prijmeni uzivatele, ktereho chcete odstranit: " << endl;
                    break;

    }
   break;
        case 2:
            cout << "Pridani knih do fondu uzivatele (1)" << endl;
            cout << "Odstraneni knih z fondu uzivatele (2)" << endl;


            cin >> vyber;


            switch(vyber){
                case 1:
                    cout << "Vypis uzivatelu: " << endl;
                    cout << o1.getPrijmeni();

                    break;
                case 2:
                    cout << "odstran";
                    break;
                default:
                    cout << "fk";
                    break;
            }

    break;

        case 3:
            cout << "Vypis vsech vypujcek (1)" << endl;
            cout << "Vypis vypujcek podle prijmeni vypujcitele (2)" << endl;
            cout << "Vypis vypujcek podle prijmeni toho, kdo si knihu vypujcil (3)" << endl;

            cin >> vyber;

            switch(vyber){
                case 1:
                    cout << "Vypujcka 1" << endl;
                    cout << "Vypujcka 2" << endl;
                    break;

                case 2:
                    cout << "Zadejte prijmeni: " << endl;

                    cout << "Vypujcka 20" << endl;
                    break;
                case 3:
                    cout << "Zadejte prijmeni: " << endl;

                    cout << "Vypujcka 30" << endl;
                    break;

            }
            break;

        case 4:
            cout << "Zadejte nazev knihy: " << endl;


    }



    return 0;

    

}