//
// Created by msyu on 23.05.2022.
//

#ifndef PROTOTYP_SORTIMENT_H
#define PROTOTYP_SORTIMENT_H

#define WARENCOUNT 10

#include <iostream>
#include "Ware.h"

class Sortiment {
protected:
    Ware* waren[WARENCOUNT] = {};
    int WarenAnzahl = 0;

public:
    void addWare(Ware *ware);
    void printSortiment();
    void sort(int modus);

    int getWarenAnzahl(){
        return WarenAnzahl;
    }

};



#endif //PROTOTYP_SORTIMENT_H
