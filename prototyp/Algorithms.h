//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_ALGORITHMS_H
#define PROTOTYP_ALGORITHMS_H

#include "Sortiment.h"

class Algorithms {
public:
    static void quicksort_seriennummer(int WarenAnzahl, Ware *waren[]);
    static void bubblesort_gewicht(int WarenAnzahl, Ware *waren[]);
    static void mergesort_alphabetisch(int WarenAnzahl, Ware *waren[]);
    static void insertionsort_einkauf(int WarenAnzahl, Ware *waren[]);
    static void insertionsort_verkauf(int WarenAnzahl, Ware *waren[]);

};


#endif //PROTOTYP_ALGORITHMS_H
