//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_WARE_H
#define PROTOTYP_WARE_H


#include <string>

class Ware {
protected:
    std::string bezeichnung;
    int seriennummer;
    double gewicht;
    double einkaufspreis;
    double verkaufspreis;

public:

    //Konstruktor
    Ware(std::string bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis) : bezeichnung(bezeichnung), seriennummer(seriennummer), gewicht(gewicht), einkaufspreis(einkaufspreis), verkaufspreis(verkaufspreis) {

    }

    //Destruktor
    ~Ware();

    std::string getBezeichnung(){
        return this->bezeichnung;
    }

    int getSeriennummer() const{
        return this->seriennummer;
    }

    double getGewicht() const{
        return this->gewicht;
    }

    double getEinkaufspreis() const{
        return this->einkaufspreis;
    }

    double getVerkaufspreis() const{
        return this->verkaufspreis;
    }

};

std::ostream &operator<<(std::ostream &out, Ware &waren);

#endif //PROTOTYP_WARE_H
