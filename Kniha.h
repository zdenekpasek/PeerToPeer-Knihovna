//
// Created by Zdeněk Pašek on 13/12/2018.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef SEMESTRALKA_KNIHA_H
#define SEMESTRALKA_KNIHA_H


class Kniha {

protected:
    string nazev;
    string autor;
    string zanr;
    int rokVyd;
    unsigned int pocStran;
    string jazyk;


public:
    //defaultni konstruktor
    Kniha();

    //konstruktor se vsemi parametry
    Kniha(const string &nazev, const string &autor, const string &zanr, int rokVyd, unsigned int pocStran, const string &jazyk);


    //gettery
    const string &getNazev() const;
    const string &getAutor() const;
    const string &getZanr() const;
    int getRokVyd() const;
    unsigned int getPocStran() const;
    const string &getJazyk() const;

    //settery
    void setNazev(const string &nazev);
    void setAutor(const string &autor);
    void setZanr(const string &zanr);
    void setRokVyd(int rokVyd);
    void setPocStran(unsigned int pocStran);
    void setJazyk(const string &jazyk);


};


#endif //SEMESTRALKA_KNIHA_H
