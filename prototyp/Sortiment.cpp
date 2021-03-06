//
// Created by msyu on 23.05.2022.
//

#include <iostream>
#include "Sortiment.h"
#include "Algorithms.h"

void Sortiment::addWare(Ware *ware) {

    for(int index = 0; index < WARENCOUNT; index++){
        if(!this->waren[index]){
            waren[index] = ware;
            WarenAnzahl++;
            std::cout << "Ware mit der Bezeichnung \"" << ware->getBezeichnung() << "\" wurde dem Sortiment hinzugefuegt" << std::endl;
            break;
        } else if(this->waren[WARENCOUNT-1]){
                std::cout << "Kein Platz mehr im Sortiment vorhanden" << std::endl;
                break;
        }
    }
}

void Sortiment::sort(int modus) {

    Algorithms algorithms;

    if(modus == 1){
        std::cout << "Verwende Algorithmus Quicksort fuer Seriennummern." <<  std::endl;
        algorithms.quicksort_seriennummer(this->WarenAnzahl, this->waren);
    } else if(modus == 2){
        std::cout << "Verwende Algorithmus Bubblesort fuer Gewicht." <<  std::endl;
        algorithms.bubblesort_gewicht(this->WarenAnzahl, this->waren);
    } else if(modus == 3){
        std::cout << "Verwende Algorithmus Mergesort fuer Bezeichnung." <<  std::endl;
        algorithms.mergesort_alphabetisch(this->WarenAnzahl, this->waren);
    } else if(modus == 4){
        std::cout << "Verwende Algorithmus Insertionsort fuer Einkaufspreis." <<  std::endl;
        algorithms.insertionsort_einkauf(this->WarenAnzahl, this->waren);
    } else if(modus == 5){
        std::cout << "Verwende Algorithmus Insertionsort fuer Verkaufspreis." <<  std::endl;
        algorithms.insertionsort_verkauf(this->WarenAnzahl, this->waren);
    }
}

void Sortiment::printSortiment() {

    for(int index = 0; index < WARENCOUNT; index++){
        if(waren[index]){
            std::cout << "Bezeichnung: " << this->waren[index]->getBezeichnung() << " || Seriennummer: " << this->waren[index]->getSeriennummer() << " || Gewicht: " << this->waren[index]->getGewicht() << " || Einkaufspreis: " << this->waren[index]->getEinkaufspreis() << " || Verkaufspreis: " << this->waren[index]->getVerkaufspreis() << std::endl;
        }
    }
}
