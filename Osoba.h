//
// Created by Zdeněk Pašek on 16/12/2018.
//
#include <iostream>
#include <string>
#include <vector>
#include "Kniha.h"

using namespace std;

#ifndef SEMESTRALKA_OSOBA_H
#define SEMESTRALKA_OSOBA_H


class Osoba {
protected:
    string jmeno;
    string prijmeni;
    string datumNar;
    vector<string> knihFond;
    


public:
    //defaultni konstruktor
    Osoba();

    //konstruktor se vsemi parametry
    Osoba(const string &jmeno, const string &prijmeni, const string &datumNar);
    
    //konstruktor pro knizni fond
    Osoba(const vector<string> &knihFond);
    
    
    //konstruktor pro vsechno
    Osoba(const string &jmeno, const string &prjmeni, const string &datumNar, const vector<string> &knihFond);

    //gettery
    const string &getJmeno() const;
    const string &getPrijmeni() const;
    const string &getDatumNar() const;
    const vector<string> &getKnihFond() const;
    
    //settery
    void setJmeno(const string &jmeno);
    void setPrijmeni(const string &prijmeni);
    void setDatumNar(const string &datumNar);
    void setKnihFond(const vector<string> &knihFond);
    
    void vlozKnihu();
    
    void vypisOsob();
    
    
    
    
    
    
    

};


#endif //SEMESTRALKA_OSOBA_H
