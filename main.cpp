#include <iostream>
#include <string>
#include <vector>
#include "Kniha.h"
#include "Osoba.h"

using namespace std;



int main() {

    cout << "Vitejte v Peer-to-peer knihovne." << endl << endl;




    int volba;
    int vyber;
    int konec = 0;
    string jmeno;
    string prijmeni;
    string datum;
    string hledanePrijmeni;
    vector<Osoba *> list;

    while (konec !=5) {

        cout << "Co chcete udelat?" << endl;
        cout << "Sprava uzivatelu (1)" << endl;
        cout << "Uprava kniznich fondu (2)" << endl;
        cout << "Vypis vypujcek (3)" << endl;
        cout << "Dostupnost knih (4)" << endl << endl;
        cout << "Ukoncit program (5)" << endl;
        cin >> volba;

        switch (volba) {
            case 1:
                cout << string(2, '\n');
                cout << "Pridani uzivatele (1)" << endl;
                cout << "Odstraneni uzivatele (2)" << endl;

                cin >> vyber;

                switch (vyber) {
                    case 1:

                        cout << "Zadejte jmeno: " << endl;
                        cin >> jmeno;
                        cout << "Zadejte prijmeni: " << endl;
                        cin >> prijmeni;
                        cout << "Zadejte datum narozeni: " << endl;
                        cin >> datum;
                        list.push_back(new Osoba(jmeno, prijmeni, datum));

                        cout << list.back()->getJmeno() << endl;
                        cout << list.back()->getPrijmeni() << endl;
                        cout << list.back()->getDatumNar() << endl;

                        break;


                    case 2:
                        cout << "Zadejte prijmeni uzivatele, ktereho chcete odstranit: " << endl;
                        cin >> hledanePrijmeni;

                        for (int i = 0; i < list.size(); i++) {
                            if (list.at(i)->getPrijmeni() == hledanePrijmeni) {
                                cout << "Mazu uzivatele " << list.at(i)->getPrijmeni() << endl;
                                list.erase(list.begin() + i);
                                break;
                            } else {
                                cout << "Uzivatel nenalezen." << endl;
                            }
                        }

                        break;
                }
                break;
            case 2:
                cout << "Pridani knih do fondu uzivatele (1)" << endl;
                cout << "Odstraneni knih z fondu uzivatele (2)" << endl;


                cin >> vyber;


                switch (vyber) {
                    case 1:
                        cout << "Vypis uzivatelu: " << endl;


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

                switch (vyber) {
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
                break;


        }

        cout <<"Chcete pokracovat? (1)"<< endl;
        cout <<"Chcete skoncit? (5)"<< endl;

        cin >> konec;




    }
    cout << "Program ukoncen" << endl;


    return 0;

    

}