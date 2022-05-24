//
// Created by msyu on 23.05.2022.
//

#include "Algorithms.h"
#include "Ware.h"

void Algorithms::quicksort_seriennummer(Ware *waren[]) {

}

void Algorithms::bubblesort_gewicht(Ware *waren[]) {

}

void Algorithms::mergesort_alphabetisch(Ware *waren[]) {

}

void Algorithms::insertionsort_einkauf(Ware *waren[]) {
    for(int index = 0; index < WARENCOUNT; index++){
        Ware *temp = waren[index];
        int j = index-1;

        //std::cout << "Temp: " << temp << std::endl;
        //std::cout << "Pointer: " << waren[index] << std::endl;

        while(j >= 0 && temp->getEinkaufspreis() <= waren[j]->getEinkaufspreis())
        {
            waren[j+1] = waren[j];
            j = j-1;
        }
        waren[j+1] = temp;
    }
}

void Algorithms::insertionsort_verkauf(Ware *waren[]) {
    for(int index = 0; index < WARENCOUNT; index++){
        Ware *temp = waren[index];
        int j = index-1;

        //std::cout << "Temp: " << temp << std::endl;
        //std::cout << "Pointer: " << waren[index] << std::endl;

        while(j >= 0 && temp->getVerkaufspreis() <= waren[j]->getVerkaufspreis())
        {
            waren[j+1] = waren[j];
            j = j-1;
        }
        waren[j+1] = temp;
    }
}
