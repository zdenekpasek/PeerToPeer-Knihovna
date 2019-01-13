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
void filtrCtenar(vector <Vypujcka *> &vypu, string jmeno);
void filtrVypujcitel(vector <Vypujcka *> &vypu, string jmeno);
void ulozFondDoSouboru(vector <Kniha *> &fond);



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
    fond2.push_back(new Kniha("Navrat Krale", "Tolkien", "Drama", 1990, 402, "eng"));
    fond3.push_back(new Kniha("Kmotr", "Puzo", "Drama", 1990, 402, "eng"));
    fond4.push_back(new Kniha("To", "Stephen King", "Drama", 1990, 402, "eng"));
    fond5.push_back(new Kniha("Test", "Stephen King", "Drama", 1990, 402, "eng"));
    
    
    vypujcky.push_back(new Vypujcka("Pasek", "Novak", "Promena", "1.1.2018", "10.1.2018"));
    vypujcky.push_back(new Vypujcka("Zmrzlina", "Pech", "Pohadky", "2.12.2018", "19.12..2018"));
    vypujcky.push_back(new Vypujcka("Pasek", "Pech", "Peklo", "2.12.2018", "19.12..2018"));
    vypujcky.push_back(new Vypujcka("Zmrzlina", "Novotna", "Illuminae", "2.12.2017", "31.12..2017"));
    vypujcky.push_back(new Vypujcka("Novotna", "Novak", "Hamlet", "22.4.2018", "28.5.2018"));
    
    
    fstream file("vypujcky.txt");
    int nacti = 0;
    cout << "Nacteni data ze souboru (0)" <<endl;
    if(nacti == 1){
        
        while (true) {
            vytvorVypZeSouboru(vypujcky, file);
            
        }
        
    }
  
    while (konec !=5) {
        
        cout << "Co chcete udelat?" << endl;
        cout << "Vypis vech uzivatelu (1)" << endl;
        cout << "Uprava kniznich fondu (2)" << endl;
        cout << "Vypis vypujcek (3)" << endl;
        cout << "Dostupnost knih (4)" << endl << endl;
        cout << "Ukoncit program (5)" << endl;
        cin >> volba;
        
        switch (volba) {
                
            case 1:
                    cout << "Vypis vsech uzivatelu: " << endl;
                    vypisOsob(listOsob);
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
                        
                        cout << "Prijmeni: ";
                        cin >> hledanePrijmeni;
                        
                      
                        
                        
                        bool fail;
                        
                        cout << "Nazev knihy: " << endl;
                        cin >> nazev;
                        cout << "Autor: " << endl;
                        cin >> autor;
                        cout << "Zanr: " << endl;
                        cin >> zanr;
                
                        do{
                        cout << "Rok vydani: " << endl;
                        cin >> rokVyd;
                            fail = cin.fail();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } while(fail == true);
                        
                        do{
                        cout << "Pocet stran: " << endl;
                        cin >> pocStran;
                            fail = cin.fail();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } while(fail == true);
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
                        filtrCtenar(vypujcky, hledanePrijmeni);
                        
                        break;
                    case 3:
                        cout << "Zadejte prijmeni: " << endl;
                        vypisOsob(listOsob);
                        cin >> hledanePrijmeni;
                        filtrVypujcitel(vypujcky, hledanePrijmeni);
                        
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
    ulozVypDoSouboru(vypujcky);
    ulozFondDoSouboru(fond1);
    ulozFondDoSouboru(fond2);
    ulozFondDoSouboru(fond3);
    ulozFondDoSouboru(fond4);
    ulozFondDoSouboru(fond5);
    
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
    ofstream file;
    file.open("vypujcky.txt");
    for(int i = 0; i < list.size(); i++){
        file << list.at(i)->getVypujcitel();
        file << endl;
        file << list.at(i)->getNeVypujcitel();
        file << endl;
        file << list.at(i)->getKniha();
        file << endl;
        file << list.at(i)->getOdDne();
        file << endl;
        file << list.at(i)->getDoDne();
        file << endl;
    }
    file << 420;
}

void ulozFondDoSouboru(vector <Kniha *> &fond){
    ofstream fondy;
    fondy.open("fondy.txt", ios::out|ios::app);
    for (int i = 0; i < fond.size(); i++) {
        fondy << fond.at(i)->getNazev();
        fondy << endl;
        fondy << fond.at(i)->getAutor();
        fondy << endl;
        fondy << fond.at(i)->getZanr();
        fondy << endl;
        fondy << fond.at(i)->getRokVyd();
        fondy << endl;
        fondy << fond.at(i)->getPocStran();
        fondy << endl;
        fondy << fond.at(i)->getJazyk();
        fondy << endl;
       
    }
    fondy << 420;
    
}

void filtrCtenar(vector <Vypujcka *> &vypu, string jmeno){
    
    for(int i = 0; i < vypu.size(); i++){
        if(vypu.at(i)->getNeVypujcitel() == jmeno){
            cout << "Kniha: " <<vypu.at(i)->getKniha() << " Vypujceno od: "<<vypu.at(i)->getVypujcitel() << " Od: "<< vypu.at(i)->getOdDne() << " Do: " << vypu.at(i)->getDoDne() << endl;
        }
    }
}

void filtrVypujcitel(vector <Vypujcka *> &vypu, string jmeno){
    
    for(int i = 0; i < vypu.size(); i++){
        if(vypu.at(i)->getVypujcitel() == jmeno){
            cout << "Kniha: " <<vypu.at(i)->getKniha() << " Komu: "<<vypu.at(i)->getNeVypujcitel() << " Od: "<< vypu.at(i)->getOdDne() << " Do: " << vypu.at(i)->getDoDne() << endl;
        }
    }
}



void vypisVypujcky(vector <Vypujcka *> &vyp){
    for(int i = 0; i < vyp.size(); i++){
        cout << "Vypujcka:" << i << " "<< "Vypujcitel: " <<vyp.at(i)->getVypujcitel() << "   " << "Ctenar: "<< vyp.at(i)->getNeVypujcitel() << "   "<< "Kniha: "<< vyp.at(i)->getKniha()<< "   "<< "Od: "<< vyp.at(i)->getOdDne()<< "   "<< "Do: "<< vyp.at(i)->getDoDne()<< endl;
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
