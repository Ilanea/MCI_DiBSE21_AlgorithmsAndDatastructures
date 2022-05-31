//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_SORTIMENT_H
#define PROTOTYP_SORTIMENT_H

#define WARENCOUNT 50

#include <iostream>
#include "Ware.h"

class Sortiment {
protected:
    Ware* waren[WARENCOUNT] = {};
    int WarenAnzahl = 0;

public:

    ~Sortiment(){
        //std::cout << "Dekonstruktor Sortiment" << std::endl;
        for (int i = 0; i < WARENCOUNT; ++i) {
            delete waren[i];
        }
    }

    void addWare(Ware *ware);
    void printSortiment();
    void sort(int modus);

    int getWarenAnzahl(){
        return WarenAnzahl;
    }

};



#endif //PROTOTYP_SORTIMENT_H
