//
// Created by msyu on 23.05.2022.
//

#include <iostream>
#include "Sortiment.h"
#include "Algorithms.h"



void Sortiment::addWare(Ware *ware) {

    for(int index = 0; index < WARENCOUNT; index++){
        if(this->waren[index] == nullptr){
            waren[index] = ware;
            std::cout << "Ware wurde hinzugefuegt" << std::endl;
            break;
        } else if(this->waren[WARENCOUNT-1] != nullptr){
                std::cout << "Kein Platz mehr vorhanden" << std::endl;
                break;
        }
    }


}

void Sortiment::sort(int modus) {

    if(modus == 1){
        std::cout << "Verwende Algorithmus Quicksort fuer Seriennummern." <<  std::endl;
        Algorithms::quicksort_seriennummer(this->waren);
    } else if(modus == 2){
        std::cout << "Verwende Algorithmus Bubblesort fuer Gewicht." <<  std::endl;
        Algorithms::bubblesort_gewicht(this->waren);
    } else if(modus == 3){
        std::cout << "Verwende Algorithmus Mergesort fuer Bezeichnung." <<  std::endl;
        Algorithms::mergesort_alphabetisch(this->waren);
    } else if(modus == 4){
        std::cout << "Verwende Algorithmus Insertionsort fuer Einkaufspreis." <<  std::endl;
        Algorithms::insertionsort_einkauf(this->waren);
    } else if(modus == 5){
        std::cout << "Verwende Algorithmus Insertionsort fuer Verkaufspreis." <<  std::endl;
        Algorithms::insertionsort_verkauf(this->waren);
    }

}

void Sortiment::printSortiment() {

    for(int index = 0; index < WARENCOUNT; index++){
        if(waren[index] != nullptr){
            std::cout << "Bezeichnung: " << this->waren[index]->getBezeichnung() << " || Seriennummer: " << this->waren[index]->getSeriennummer() << " || Gewicht: " << this->waren[index]->getGewicht() << " || Einkaufspreis: " << this->waren[index]->getEinkaufspreis() << " || Verkaufspreis: " << this->waren[index]->getVerkaufspreis() << std::endl;
        }
    }

}
