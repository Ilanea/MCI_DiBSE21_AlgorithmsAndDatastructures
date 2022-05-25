//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_ALGORITHMS_H
#define PROTOTYP_ALGORITHMS_H

#include "Sortiment.h"

class Algorithms {
public:

    ~Algorithms(){
        //std::cout << "Dekonstruktor Algorithms" << std::endl;
    };

    void quicksort_seriennummer(int WarenAnzahl, Ware *waren[]);
    int partition(Ware *waren[], int low, int high);
    void quicksort(Ware *waren[], int low, int high);
    void bubblesort_gewicht(int WarenAnzahl, Ware *waren[]);
    void mergesort_alphabetisch(int WarenAnzahl, Ware *waren[]);
    void mergesort(Ware *waren[], int low, int high);
    void merge(Ware *waren[], int low, int high, int mid);
    void insertionsort_einkauf(int WarenAnzahl, Ware *waren[]);
    void insertionsort_verkauf(int WarenAnzahl, Ware *waren[]);

};


#endif //PROTOTYP_ALGORITHMS_H
