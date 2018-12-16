//
// Created by Zdeněk Pašek on 13/12/2018.
//

#include "Kniha.h"

//nastaveni knihy na defaultni hodnoty
Kniha::Kniha() {
    nazev = { };
    autor = { };
    zanr = { };
    rokVyd = 0;
    pocStran = 0;
    jazyk = { };
}

Kniha::Kniha(const string &nazev, const string &autor, const string &zanr, int rokVyd, unsigned int pocStran,
             const string &jazyk) : nazev(nazev), autor(autor), zanr(zanr), rokVyd(rokVyd), pocStran(pocStran),
                                    jazyk(jazyk) {
    this->nazev = nazev;
    this->autor = autor;
    this->zanr = zanr;
    this->rokVyd = rokVyd;
    this->pocStran = pocStran;
    this->jazyk = jazyk;
}

//gettery
const string &Kniha::getNazev() const {
    return nazev;
}
const string &Kniha::getAutor() const {
    return autor;
}
const string &Kniha::getZanr() const {
    return zanr;
}
int Kniha::getRokVyd() const {
    return rokVyd;
}
unsigned int Kniha::getPocStran() const {
    return pocStran;
}
const string &Kniha::getJazyk() const {
    return jazyk;
}

//settery
void Kniha::setNazev(const string &nazev) {
    Kniha::nazev = nazev;
}
void Kniha::setAutor(const string &autor) {
    Kniha::autor = autor;
}
void Kniha::setZanr(const string &zanr) {
    Kniha::zanr = zanr;
}
void Kniha::setRokVyd(int rokVyd) {
    Kniha::rokVyd = rokVyd;
}
void Kniha::setPocStran(unsigned int pocStran) {
    Kniha::pocStran = pocStran;
}
void Kniha::setJazyk(const string &jazyk) {
    Kniha::jazyk = jazyk;
}
