//
// Created by msyu on 23.05.2022.
//

#include "Algorithms.h"

void Algorithms::quicksort_seriennummer(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/quick-sort/



}

void Algorithms::bubblesort_gewicht(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/bubble-sort/

    for (int index = 0; index < WarenAnzahl; index++)
        for (int j = 0; j < WarenAnzahl - index - 1; j++)
            if (waren[j]->getGewicht() > waren[j + 1]->getGewicht())
                std::swap(waren[j], waren[j + 1]);
}

void Algorithms::mergesort_alphabetisch(int WarenAnzahl, Ware *waren[]) {

    //https://www.geeksforgeeks.org/merge-sort/

    int Middle = WarenAnzahl;

    auto divide = [&Middle](Ware *waren[]){
        int middle = 1 + (Middle-1) / 2;
        return middle;
    };

    while(Middle >= 2){
        Middle = divide(waren);
        std::cout << "Middle: " << Middle << std::endl;
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
