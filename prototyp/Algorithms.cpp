//
// Created by msyu on 23.05.2022.
//

#include "Algorithms.h"

void Algorithms::quicksort_seriennummer(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/quick-sort/



}

void Algorithms::bubblesort_gewicht(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/bubble-sort/

    for (int index = 0; index < WarenAnzahl - 1; index++)
        for (int j = 0; j < WarenAnzahl - index - 1; j++)
            if (waren[j]->getGewicht() > waren[j + 1]->getGewicht())
                std::swap(waren[j], waren[j + 1]);
}

void Algorithms::mergesort_alphabetisch(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/merge-sort/

    merge_sort(waren, 0, WarenAnzahl-1);

}

void Algorithms::merge_sort(Ware *waren[], int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(waren,low,mid);
        merge_sort(waren,mid+1,high);
        //merge or conquer sorted arrays
        merge(waren,low,high,mid);
    }
}

void Algorithms::merge(Ware *waren[], int low, int high, int mid)
{
    int i, j, k;
    Ware *c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (waren[i]->getBezeichnung() < waren[j]->getBezeichnung()) {
            c[k] = waren[i];
            k++;
            i++;
        }
        else  {
            c[k] = waren[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = waren[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = waren[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        waren[i] = c[i];
    }
}

void Algorithms::insertionsort_einkauf(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/insertion-sort/

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

    //https://www.geeksforgeeks.org/insertion-sort/

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
