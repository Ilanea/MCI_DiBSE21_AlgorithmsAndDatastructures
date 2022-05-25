//
// Created by msyu on 23.05.2022.
//

#include "Algorithms.h"

//----------------------------------------------------------------------------------------------------------------
// Quicksort
// https://www.geeksforgeeks.org/quick-sort/
//----------------------------------------------------------------------------------------------------------------

void Algorithms::quicksort_seriennummer(int WarenAnzahl, Ware *waren[]) {

    quicksort(waren, 0, WarenAnzahl - 1);
}

int Algorithms::partition (Ware *waren[], int low, int high){
    Ware *pivot = waren[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (waren[j]->getSeriennummer() < pivot->getSeriennummer()){
            i++;
            std::swap(waren[i], waren[j]);
        }
    }
    std::swap(waren[i + 1], waren[high]);
    return (i + 1);
}

void Algorithms::quicksort(Ware *waren[], int low, int high){

    if (low < high){
        int pi = partition(waren, low, high);
        quicksort(waren, low, pi - 1);
        quicksort(waren, pi + 1, high);
    }
}

//----------------------------------------------------------------------------------------------------------------
// Bubblesort
// https://www.geeksforgeeks.org/bubble-sort/
//----------------------------------------------------------------------------------------------------------------

void Algorithms::bubblesort_gewicht(int WarenAnzahl, Ware *waren[]) {

    for (int index = 0; index < WarenAnzahl - 1; index++)
        for (int j = 0; j < WarenAnzahl - index - 1; j++)
            if (waren[j]->getGewicht() > waren[j + 1]->getGewicht())
                std::swap(waren[j], waren[j + 1]);
}

//----------------------------------------------------------------------------------------------------------------
// Mergesort
// https://www.geeksforgeeks.org/merge-sort/
// https://www.softwaretestinghelp.com/merge-sort/
//----------------------------------------------------------------------------------------------------------------

void Algorithms::mergesort_alphabetisch(int WarenAnzahl, Ware *waren[]) {

    mergesort(waren, 0, WarenAnzahl-1);
}

void Algorithms::mergesort(Ware *waren[], int low, int high) {

    int mid;
    if(low < high){
        mid=(low+high)/2;
        mergesort(waren,low,mid);
        mergesort(waren,mid+1,high);
        merge(waren,low,high,mid);
    }
}

void Algorithms::merge(Ware *waren[], int low, int high, int mid) {

    int i, j, k;
    Ware *c[50];
    i = low;
    k = low;
    j = mid + 1;
    while(i <= mid && j <= high) {
        if(waren[i]->getBezeichnung() < waren[j]->getBezeichnung()) {
            c[k] = waren[i];
            k++;
            i++;
        }
        else {
            c[k] = waren[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        c[k] = waren[i];
        k++;
        i++;
    }
    while(j <= high) {
        c[k] = waren[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        waren[i] = c[i];
    }
}

//----------------------------------------------------------------------------------------------------------------
// Insertionsort
// https://www.geeksforgeeks.org/insertion-sort/
//----------------------------------------------------------------------------------------------------------------

void Algorithms::insertionsort_einkauf(int WarenAnzahl, Ware *waren[]) {

    for(int index = 0; index < WarenAnzahl; index++){
        Ware *temp = waren[index];
        int j = index - 1;
        while(j >= 0 && temp->getEinkaufspreis() <= waren[j]->getEinkaufspreis()){
            waren[j+1] = waren[j];
            j = j-1;
        }
        waren[j+1] = temp;
    }
}

void Algorithms::insertionsort_verkauf(int WarenAnzahl, Ware *waren[]) {

    for(int index = 0; index < WarenAnzahl; index++){
        Ware *temp = waren[index];
        int j = index - 1;
        while(j >= 0 && temp->getVerkaufspreis() <= waren[j]->getVerkaufspreis()){
            waren[j+1] = waren[j];
            j = j-1;
        }
        waren[j+1] = temp;
    }
}
