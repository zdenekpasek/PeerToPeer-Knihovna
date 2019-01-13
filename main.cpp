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
void vytvorFondZeSouboru(vector <Kniha *> &fond, fstream &fondy);



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
    // vytvoreni vectoru pro osoby
    vector<Osoba *> listOsob;
    
    // vytvoreni vectoru pro knizni fond, kazda osoba ma svuj vektor
    vector<Kniha *> fond1;
    vector<Kniha *> fond2;
    vector<Kniha *> fond3;
    vector<Kniha *> fond4;
    vector<Kniha *> fond5;
    vector<Vypujcka *> vypujcky;
    
    // vytvoreni instanci osob a pushnuti do vectoru osob
    listOsob.push_back(new Osoba("Zdenek", "Pasek", "9.11.1990"));
    listOsob.push_back(new Osoba("Jan", "Novak", "17.2.1978"));
    listOsob.push_back(new Osoba("Mirka", "Novotna", "28.1.1987"));
    listOsob.push_back(new Osoba("Tomas", "Pech", "29.12.1992"));
    listOsob.push_back(new Osoba("Otakar", "Zmrzlina", "9.11.1966"));
    
    // vytvoreni instanci knih a pushnuti do jednotlivych vectoru osob
    fond1.push_back(new Kniha("Hamlet", "William Shakespeare", "Drama", 1890, 320, "cz"));
    fond2.push_back(new Kniha("Navrat Krale", "Tolkien", "Drama", 1990, 402, "eng"));
    fond3.push_back(new Kniha("Kmotr", "Puzo", "Drama", 1990, 402, "eng"));
    fond4.push_back(new Kniha("To", "Stephen King", "Drama", 1990, 402, "eng"));
    fond5.push_back(new Kniha("Test", "Stephen King", "Drama", 1990, 402, "eng"));

    // vytvoreni instanci vypujcek a pushnuti do vectoru vypujcky
    vypujcky.push_back(new Vypujcka("Pasek", "Novak", "Promena", "1.1.2018", "10.1.2018"));
    vypujcky.push_back(new Vypujcka("Zmrzlina", "Pech", "Pohadky", "2.12.2018", "19.12..2018"));
    vypujcky.push_back(new Vypujcka("Pasek", "Pech", "Peklo", "2.12.2018", "19.12..2018"));
    vypujcky.push_back(new Vypujcka("Zmrzlina", "Novotna", "Illuminae", "2.12.2017", "31.12..2017"));
    vypujcky.push_back(new Vypujcka("Novotna", "Novak", "Hamlet", "22.4.2018", "28.5.2018"));
    vypujcky.push_back(new Vypujcka("Novotna", "Pasek", "Y O", "22.4.2018", "28.5.2018"));
  
   /*
    fstream file;
    file.open("vypujcky.txt");
    cout << "Nacteni vypujcek ze souboru (0)" << endl;
    int moznost;
    cin >> moznost;
    
    if(moznost == 0){
        vytvorVypZeSouboru(vypujcky, file);
            }
    */
  
    // dokud neni vstup 5, tak vypisuj tohle menu
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
                
                // uprava kniznich fondu
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
                        
                        // cin.fail -- k osetreni vstupu, pokud zadam napr. string, zepta se me znovu na vstup
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
                        
                        // podle prijmeni pridej knihu do knizniho fondu
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
                        
                    // odebrani knihy z knizniho fondu podle prijmeni, kazda osoba ma svuj knizni fond
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
                
            // vypis vypujcek
            case 3:
                cout << "Vypis vsech vypujcek (1)" << endl;
                cout << "Vypis vypujcek podle prijmeni vypujcitele (2)" << endl;
                cout << "Vypis vypujcek podle prijmeni toho, kdo si knihu vypujcil (3)" << endl;
                
                cin >> vyber;
                
                switch (vyber) {
                    // vypis vsech vypujcek
                    case 1:
                        vypisVypujcky(vypujcky);
                        break;
                        
                    case 2:
                        // vypis vypujcek podle prijmeni vypujcitele
                        vypisOsob(listOsob);
                        cout << "Zadejte prijmeni: " << endl;
                        cin >> hledanePrijmeni;
                        filtrCtenar(vypujcky, hledanePrijmeni);
                        
                        break;
                    case 3:
                        // vypis vypujcek podle ctenare
                        cout << "Zadejte prijmeni: " << endl;
                        vypisOsob(listOsob);
                        cin >> hledanePrijmeni;
                        filtrVypujcitel(vypujcky, hledanePrijmeni);
                        
                        break;
                }
                break;
                
            case 4:
                cout << "Zadejte nazev knihy: " << endl;
                string hledanaKniha;
                cin >> hledanaKniha;
                
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

// vytvori vypujcky ze souboru
void vytvorVypZeSouboru(vector <Vypujcka *> &list, fstream &file){
    string vypujcitel;
    string neVypujcitel;
    string kniha;
    string odDne;
    string doDne;
    
    string line;
   
    while (line != "konec") {
        
        file >> line;
        if (line !="konec") {vypujcitel=line;}
        else break;
        file >> neVypujcitel;
        file >> kniha;
        file >> odDne;
        file >> doDne;
    
        list.push_back(new Vypujcka(vypujcitel, neVypujcitel, kniha, odDne, doDne));
    }
}
// ulozi vypujcky do souboru
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
    file << "konec";
}

// ulozi fondy knih do souboru
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
    //fondy << 999 <<"\n";
}

// vytvori fondy knih ze souboru
void vytvorFondZeSouboru(vector <Kniha *> &fond, fstream &fondy){
    string nazev;
    string autor;
    string zanr;
    int rokVyd;
    unsigned int pocStran;
    string jazyk;
    
    fondy >> nazev;
    fondy >> autor;
    fondy >> zanr;
    fondy >> rokVyd;
    fondy >> pocStran;
    fondy >> jazyk;
    
    fond.push_back(new Kniha(nazev, autor, zanr, rokVyd, pocStran, jazyk));
}

// filtrovany vypis vypujcek podle prijmeni toho, kdo si vypujcil (ctenar)
void filtrCtenar(vector <Vypujcka *> &vypu, string jmeno){
    
    for(int i = 0; i < vypu.size(); i++){
        if(vypu.at(i)->getNeVypujcitel() == jmeno){
            cout << "Kniha: " <<vypu.at(i)->getKniha() << " Vypujceno od: "<<vypu.at(i)->getVypujcitel() << " Od: "<< vypu.at(i)->getOdDne() << " Do: " << vypu.at(i)->getDoDne() << endl;
        }
    }
}

// filtrovany vypis vypujcek podle prijmeni vypujcitele
void filtrVypujcitel(vector <Vypujcka *> &vypu, string jmeno){
    
    for(int i = 0; i < vypu.size(); i++){
        if(vypu.at(i)->getVypujcitel() == jmeno){
            cout << "Kniha: " <<vypu.at(i)->getKniha() << " Komu: "<<vypu.at(i)->getNeVypujcitel() << " Od: "<< vypu.at(i)->getOdDne() << " Do: " << vypu.at(i)->getDoDne() << endl;
        }
    }
}

// vypis vsech vypujcek z vektoru vypujcek
void vypisVypujcky(vector <Vypujcka *> &vyp){
    for(int i = 0; i < vyp.size(); i++){
        cout << "Vypujcka:" << i << " "<< "Vypujcitel: " <<vyp.at(i)->getVypujcitel() << "   " << "Ctenar: "<< vyp.at(i)->getNeVypujcitel() << "   "<< "Kniha: "<< vyp.at(i)->getKniha()<< "   "<< "Od: "<< vyp.at(i)->getOdDne()<< "   "<< "Do: "<< vyp.at(i)->getDoDne()<< endl;
    }
}

// vypis vsech osob z vektoru osob
void vypisOsob(vector <Osoba *> &list){
    for(int i = 0; i < list.size(); i++){
        cout <<
        list.at(i)->getJmeno() << " " << list.at(i)->getPrijmeni() << endl;
    }
    cout << string(2, '\n');
}

// vypsani knih z knizniho fondu
void vypisFond(vector <Kniha *> &fond){
    for(int i = 0; i < fond.size(); i++){
        cout << "Nazev: " << fond.at(i)->getNazev() << "  " << "Autor: " <<fond.at(i)->getAutor() << endl;
    }
}

// smazani knihy z knizniho fondu
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
