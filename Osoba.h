//
// Created by Zdeněk Pašek on 16/12/2018.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef SEMESTRALKA_OSOBA_H
#define SEMESTRALKA_OSOBA_H


class Osoba {
private:
    string jmeno;
    string prijmeni;
    string datumNar;

public:
    //defaultni konstruktor
    Osoba();

    //konstruktor se vsemi parametry
    Osoba(const string &jmeno, const string &prijmeni, const string &datumNar);

    //gettery
    const string &getJmeno() const;
    const string &getPrijmeni() const;
    const string &getDatumNar() const;

    //settery
    void setJmeno(const string &jmeno);
    void setPrijmeni(const string &prijmeni);
    void setDatumNar(const string &datumNar);

};


#endif //SEMESTRALKA_OSOBA_H
