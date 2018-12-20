//
// Created by Zdeněk Pašek on 20/12/2018.
//

#ifndef SEMESTRALKA_VYPUJCKA_H
#define SEMESTRALKA_VYPUJCKA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Vypujcka {
protected:
    string vypujcitel;
    string neVypujcitel;
    string kniha;
    string odDne;
    string doDne;


public:
    Vypujcka();

    //gettery
    const string &getVypujcitel() const;
    const string &getNeVypujcitel() const;
    const string &getKniha() const;
    const string &getOdDne() const;
    const string &getDoDne() const;


    //settery
    void setVypujcitel(const string &vypujcitel);
    void setNeVypujcitel(const string &neVypujcitel);
    void setKniha(const string &kniha);
    void setOdDne(const string &odDne);
    void setDoDne(const string &doDne);


};


#endif //SEMESTRALKA_VYPUJCKA_H
