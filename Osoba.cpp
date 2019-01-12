//
// Created by Zdeněk Pašek on 16/12/2018.
//

#include "Osoba.h"
#include "Kniha.h"

Osoba::Osoba() {
    jmeno = {};
    prijmeni = {};
    datumNar = {};
    knihFond = {};
}

Osoba::Osoba(const string &jmeno, const string &prijmeni, const string &datumNar) {

    this->jmeno = jmeno;
    this->prijmeni = prijmeni;
    this->datumNar = datumNar;
}

Osoba::Osoba(const string &jmeno, const string &prijmeni, const string &datumNar, const vector<string> &knihFond) {
    
    this->jmeno = jmeno;
    this->prijmeni = prijmeni;
    this->datumNar = datumNar;
    this->knihFond = knihFond;
}

//gettery
const string &Osoba::getJmeno() const {
    return jmeno;
}
const string &Osoba::getPrijmeni() const {
    return prijmeni;
}
const string &Osoba::getDatumNar() const {
    return datumNar;
}



//settery
void Osoba::setJmeno(const string &jmeno) {
    Osoba::jmeno = jmeno;
}
void Osoba::setPrijmeni(const string &prijmeni) {
    Osoba::prijmeni = prijmeni;
}
void Osoba::setDatumNar(const string &datumNar) {
    Osoba::datumNar = datumNar;
}

Osoba::Osoba(const vector<string> &knihFond) : knihFond(knihFond) {}

const vector<string> &Osoba::getKnihFond() const {
    return knihFond;
}

void Osoba::setKnihFond(const vector<string> &knihFond) {
    Osoba::knihFond = knihFond;
}

void Osoba::vlozKnihu(){
    

}



