#include <iostream>
#include <string>
#include <vector>
#include "Kniha.h"
#include "Osoba.h"
#include "Vypujcka.h"
#include <fstream>

using namespace std;

void vypisOsob(vector <Osoba *> &list);
void vypisFond(vector <Kniha *> &fond);
void smazKnihu(vector <Kniha *> &fond);
void vypisVypujcky(vector <Vypujcka *> &vyp);
void ulozVypDoSouboru(vector <Vypujcka *> &list);
void vytvorVypZeSouboru(vector <Vypujcka *> &list, fstream &file);




int main() {
    
    cout << "Vitejte v Peer-to-peer knihovne." << endl << endl;
    
    int volba;
    int vyber;
    int konec = 0;
    string jmeno;
    string prijmeni;
    string datum;
    string hledanePrijmeni;
    string hledanaKniha;
    
    string nazev;
    string autor;
    string zanr;
    int rokVyd;
    int pocStran;
    string jazyk;
    vector<Osoba *> listOsob;
    vector<Kniha *> fond1;
    vector<Kniha *> fond2;
    vector<Kniha *> fond3;
    vector<Kniha *> fond4;
    vector<Kniha *> fond5;
    vector<Vypujcka *> vypujcky;
    
    
    
    
    
    listOsob.push_back(new Osoba("Zdenek", "Pasek", "9.11.1990"));
    listOsob.push_back(new Osoba("Jan", "Novak", "17.2.1978"));
    listOsob.push_back(new Osoba("Mirka", "Novotna", "28.1.1987"));
    listOsob.push_back(new Osoba("Tomas", "Pech", "29.12.1992"));
    listOsob.push_back(new Osoba("Otakar", "Zmrzlina", "9.11.1966"));
    
 
    fond1.push_back(new Kniha("Hamlet", "William Shakespeare", "Drama", 1890, 320, "cz"));
    
    
    vypujcky.push_back(new Vypujcka("Pasek", "Novak", "Promena", "1.1.2018", "10.1.2018"));
    vypujcky.push_back(new Vypujcka("Zmrzlina", "Pech", "Pohadky", "2.12.2018", "19.12..2018"));
    vypujcky.push_back(new Vypujcka("Zmrzlina", "Novotna", "Illuminae", "2.12.2017", "31.12..2017"));
    vypujcky.push_back(new Vypujcka("Novotna", "Novak", "Hamlet", "22.4.2018", "28.5.2018"));
    
    fstream file("knihovna.txt");
    int nacti = 0;
    cout << "Nacteni dat ze souboru (1)" <<endl;
    if(nacti == 1){
        
        while (true) {
            vytvorVypZeSouboru(vypujcky, file);
            
        }
        
    }
  
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
                cout << "Vypis vsech uzivatelu (3)" << endl;
                
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
                        
                    case 3:
                        cout << "Vypis vsech uzivatelu: " << endl;
                        vypisOsob(listOsob);
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
                        vypisOsob(listOsob);
                        cin >> hledanePrijmeni;
                        
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
                    
                        
                        if(hledanePrijmeni == "Pasek"){
                            fond1.push_back(new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk));
                             cout << "Kniha uspesne pridana" << endl;
                        
                        } else if (hledanePrijmeni == "Novak"){
                            fond2.push_back(new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk));
                            cout << "Kniha uspesne pridana" << endl;
                            
                        } else if (hledanePrijmeni == "Novotna"){
                            fond3.push_back(new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk));
                             cout << "Kniha uspesne pridana" << endl;
                        } else if (hledanePrijmeni == "Pech"){
                            fond4.push_back(new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk));
                             cout << "Kniha uspesne pridana" << endl;
                        } else if (hledanePrijmeni == "Zmrzlina"){
                            fond5.push_back(new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk));
                             cout << "Kniha uspesne pridana" << endl;
                        } else{
                            cout << "Uzivatel nenalezen" << endl;
                        }
                        
                        
                        break;
                        
                        
                        
                    case 2:
                        cout << "Jakemu uzivateli chcete odebrat knihu? (zadejte prijmeni)" << endl;
                        cout << "Vypis uzivatelu: " << endl;
                        vypisOsob(listOsob);
                        cout << "Zadejte prijmeni: ";
                        cin >> hledanePrijmeni;
                        
                        if(hledanePrijmeni == "Pasek"){
                            vypisFond(fond1);
                            smazKnihu(fond1);
                            }
                        if(hledanePrijmeni == "Novak"){
                            vypisFond(fond2);
                            smazKnihu(fond2);
                            
                        }
                        if(hledanePrijmeni == "Novotna"){
                            vypisFond(fond3);
                            smazKnihu(fond3);
                            
                        }
                        if(hledanePrijmeni == "Pech"){
                            vypisFond(fond4);
                            smazKnihu(fond4);
                            
                        }
                        if(hledanePrijmeni == "Zmrzlina"){
                            vypisFond(fond5);
                            smazKnihu(fond5);
                            
                        }
        }
                
                
                break;
                
            case 3:
                cout << "Vypis vsech vypujcek (1)" << endl;
                cout << "Vypis vypujcek podle prijmeni vypujcitele (2)" << endl;
                cout << "Vypis vypujcek podle prijmeni toho, kdo si knihu vypujcil (3)" << endl;
                
                cin >> vyber;
                
                switch (vyber) {
                    case 1:
                        vypisVypujcky(vypujcky);
                       
                        break;
                        
                    case 2:
                        cout << "Zadejte prijmeni: " << endl;
                        vypisOsob(listOsob);
                        cin >> hledanePrijmeni;
                        
                        
                        
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

void vytvorVypZeSouboru(vector <Vypujcka *> &list, fstream &file){
    string vypujcitel;
    string neVypujcitel;
    string kniha;
    string odDne;
    string doDne;
    
    file >> vypujcitel;
    file >> neVypujcitel;
    file >> kniha;
    file >> odDne;
    file >> doDne;
    
    list.push_back(new Vypujcka(vypujcitel, neVypujcitel, kniha, odDne, doDne));
}

void ulozVypDoSouboru(vector <Vypujcka *> &list){
    fstream file("knihovna.txt", ios::out);
    for(int i = 0; i < list.size(); i++){
        file << list.at(i)->getVypujcitel();
        cout << " ";
        file << list.at(i)->getNeVypujcitel();
        cout << " ";
        file << list.at(i)->getKniha();
        cout << " ";
        file << list.at(i)->getOdDne();
        cout << " ";
        file << list.at(i)->getDoDne();
    }
    file << 420;
}

void filtrPrijmeni(vector <Vypujcka *> &vypu){
    
    for(int i = 0; i < vypu.size(); i++){
        cout << "Vypujcitel: " <<vypu.at(i)->getVypujcitel() << " " << "Ctenar: "<< vypu.at(i)->getNeVypujcitel() << endl;
    }
}


void vypisVypujcky(vector <Vypujcka *> &vyp){
    for(int i = 0; i < vyp.size(); i++){
        cout << "Vypujcitel: " <<vyp.at(i)->getVypujcitel() << " " << "Ctenar: "<< vyp.at(i)->getNeVypujcitel() << endl;
    }
}

void vypisOsob(vector <Osoba *> &list){
    for(int i = 0; i < list.size(); i++){
        cout <<
        list.at(i)->getJmeno() << " " << list.at(i)->getPrijmeni() << endl;
    }
    cout << string(2, '\n');
}

void vypisFond(vector <Kniha *> &fond){
    for(int i = 0; i < fond.size(); i++){
        cout << "Nazev: " << fond.at(i)->getNazev() << "  " << "Autor: " <<fond.at(i)->getAutor() << endl;
    }
}

void smazKnihu(vector <Kniha *> &fond){
    string hledanaKniha;
    cout << "Zadejte nazev knihy: " << endl;
    cin >> hledanaKniha;
    for (int i = 0; i < fond.size(); i++) {
        if (fond.at(i)->getNazev() == hledanaKniha) {
            cout << "Mazu knihu " << fond.at(i)->getNazev() << endl;
            fond.erase(fond.begin() + i);
            break;
        } else {
            cout << "Kniha nenalezena." << endl;
        }
    }
    
}
