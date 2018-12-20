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

    string nazev;
    string autor;
    string zanr;
    int rokVyd;
    int pocStran;
    string jazyk;
    vector<Osoba *> listOsob;

    listOsob.push_back(new Osoba("Zdenek", "Pasek", "9.11.1990"));
    listOsob.push_back(new Osoba("Jan", "Novak", "17.2.1978"));
    listOsob.push_back(new Osoba("Mirka", "Novotna", "28.1.1987"));
    listOsob.push_back(new Osoba("Tomas", "Pech", "29.12.1992"));
    listOsob.push_back(new Osoba("Otakar", "Zmrzlina", "9.11.1966"));

    new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk);






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
                        listOsob.push_back(new Osoba(jmeno, prijmeni, datum));

                        cout << "Uzivatel uspesne pridan." << endl << endl;

                        break;


                    case 2:
                        cout << "Zadejte prijmeni uzivatele, ktereho chcete odstranit: " << endl;
                        cin >> hledanePrijmeni;

                        for (int i = 0; i < listOsob.size(); i++) {
                            if (listOsob.at(i)->getPrijmeni() == hledanePrijmeni) {
                                cout << "Mazu uzivatele " << listOsob.at(i)->getPrijmeni() << endl;
                                listOsob.erase(listOsob.begin() + i);
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
                        cout << "Jakemu uzivateli chcete pridat knihu? (zadejte prijmeni)" << endl;
                        cout << "Vypis uzivatelu: " << endl;
                        for(int i = 0; i < listOsob.size(); i++){
                            cout <<
                             listOsob.at(i)->getJmeno() << " " << listOsob.at(i)->getPrijmeni() << endl;
                        }
                        cin >> prijmeni;


                        cout << "Nazev knihy: " << endl;
                        cin >> nazev;
                        cout << "Autor: " << endl;
                        cin >> autor;
                        cout << "Zanr: " << endl;
                        cin >> zanr;
                        cout << "Rok vydani: " << endl;
                        cin >> rokVyd;
                        cout << "Pocet stran: " << endl;
                        cin >> pocStran;
                        cout << "Jazyk: " << endl;
                        cin >> jazyk;

                        new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk);


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