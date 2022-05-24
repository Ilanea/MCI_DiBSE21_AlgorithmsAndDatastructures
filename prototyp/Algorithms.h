//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_ALGORITHMS_H
#define PROTOTYP_ALGORITHMS_H

#include "Sortiment.h"

class Algorithms {
public:
    static void quicksort_seriennummer(Ware *waren[]);
    static void bubblesort_gewicht(Ware *waren[]);
    static void mergesort_alphabetisch(Ware *waren[]);
    static void insertionsort_einkauf(Ware *waren[]);
    static void insertionsort_verkauf(Ware *waren[]);

};


#endif //PROTOTYP_ALGORITHMS_H
