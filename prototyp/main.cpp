#include <iostream>
#include "Sortiment.h"
#include "Ware.h"


int main() {

    Sortiment *sortiment = new Sortiment();

    Ware *ware0 = new Ware("0", 0, 0, 0, 0);
    Ware *ware1 = new Ware("A", 1, 1, 1, 1);
    Ware *ware2 = new Ware("B", 2, 1, 1, 1);
    Ware *ware3 = new Ware("C", 3, 1, 1, 1);
    Ware *ware4 = new Ware("D", 4, 1, 1, 1);
    Ware *ware5 = new Ware("E", 5, 1, 1, 1);
    Ware *ware6 = new Ware("F", 6, 1, 1, 1);
    Ware *ware7 = new Ware("G", 7, 1, 1, 1);
    Ware *ware8 = new Ware("H", 8, 1, 1, 1);
    Ware *ware9 = new Ware("I", 9, 1, 1, 1);


    sortiment->addWare(ware0);
    sortiment->addWare(ware1);
    sortiment->addWare(ware2);
    sortiment->addWare(ware3);
    sortiment->addWare(ware4);
    sortiment->addWare(ware5);
    sortiment->addWare(ware6);
    sortiment->addWare(ware7);
    sortiment->addWare(ware8);
    sortiment->addWare(ware9);

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo vor sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo nach sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;

    return 0;

}
