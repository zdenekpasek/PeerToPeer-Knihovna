#include <iostream>
#include <string>
#include "Kniha.h"
#include "Osoba.h"

using namespace std;



int main() {

    Kniha k1;
    Osoba o1;



    k1.setNazev("Romeo a Julie");

    cout << k1.getNazev();



    return 0;

    

}