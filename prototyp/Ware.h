//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_WARE_H
#define PROTOTYP_WARE_H


#include <string>
#include <iostream>

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
    ~Ware(){
        //std::cout << "Dekonstruktor Ware" << std::endl;
    };

    std::string getBezeichnung();
    int getSeriennummer() const;
    double getGewicht() const;
    double getEinkaufspreis() const;
    double getVerkaufspreis() const;

    void setBezeichnung();
    void setSeriennummer();
    void setGewicht();
    void setEinkaufspreis();
    void setVerkaufspreis();

};

std::ostream &operator<<(std::ostream &out, Ware &waren);

#endif //PROTOTYP_WARE_H
