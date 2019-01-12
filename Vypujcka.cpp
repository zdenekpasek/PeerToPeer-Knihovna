//
// Created by Zdeněk Pašek on 20/12/2018.
//

#include "Vypujcka.h"

Vypujcka::Vypujcka() {}

//gettery
const string &Vypujcka::getVypujcitel() const {
    return vypujcitel;
}
const string &Vypujcka::getNeVypujcitel() const {
    return neVypujcitel;
}
const string &Vypujcka::getKniha() const {
    return kniha;
}
const string &Vypujcka::getOdDne() const {
    return odDne;
}
const string &Vypujcka::getDoDne() const {
    return doDne;
}

//settery
void Vypujcka::setVypujcitel(const string &vypujcitel) {
    Vypujcka::vypujcitel = vypujcitel;
}
void Vypujcka::setNeVypujcitel(const string &neVypujcitel) {
    Vypujcka::neVypujcitel = neVypujcitel;
}
void Vypujcka::setKniha(const string &kniha) {
    Vypujcka::kniha = kniha;
}
void Vypujcka::setOdDne(const string &odDne) {
    Vypujcka::odDne = odDne;
}
void Vypujcka::setDoDne(const string &doDne) {
    Vypujcka::doDne = doDne;
}


Vypujcka::Vypujcka(const string &vypujcitel, const string &neVypujcitel, const string &kniha, const string &odDne, const string &doDne){
    this->vypujcitel = vypujcitel;
    this->neVypujcitel = neVypujcitel;
    this->kniha = kniha;
    this->odDne = odDne;
    this->doDne = doDne;
}
