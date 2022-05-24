//
// Created by msyu on 23.05.2022.
//

#include <string>
#include "Ware.h"

std::string Ware::getBezeichnung(){
    return this->bezeichnung;
}

int Ware::getSeriennummer() const{
    return this->seriennummer;
}

double Ware::getGewicht() const{
    return this->gewicht;
}

double Ware::getEinkaufspreis() const{
    return this->einkaufspreis;
}

double Ware::getVerkaufspreis() const{
    return this->verkaufspreis;
}

void Ware::setBezeichnung() {

}

void Ware::setSeriennummer() {

}

void Ware::setGewicht() {

}

void Ware::setEinkaufspreis() {

}

void Ware::setVerkaufspreis() {

}
