#include <iostream>
#include "Sortiment.h"
#include "Ware.h"


int main() {

    Sortiment *sortiment = new Sortiment();

    Ware *ware0 = new Ware("0", 0, 0, 0, 0);
    Ware *ware1 = new Ware("A", 1, 14, 10, 321);
    Ware *ware2 = new Ware("B", 2, 3, 20, 6467);
    Ware *ware3 = new Ware("C", 3, 54, 30, 5898);
    Ware *ware4 = new Ware("D", 4, 278, 40, 456);
    Ware *ware5 = new Ware("E", 5, 123, 50, 975);
    Ware *ware6 = new Ware("F", 6, 5, 60, 567);
    Ware *ware7 = new Ware("G", 7, 1, 70, 43);
    Ware *ware8 = new Ware("H", 8, 88, 80, 857);
    Ware *ware9 = new Ware("I", 9, 345, 90, 234);



    sortiment->addWare(ware7);
    sortiment->addWare(ware2);
    sortiment->addWare(ware5);
    sortiment->addWare(ware3);
    sortiment->addWare(ware6);
    sortiment->addWare(ware8);
    sortiment->addWare(ware9);
    sortiment->addWare(ware1);
    sortiment->addWare(ware4);
    sortiment->addWare(ware0);

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo vor sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Sortieren: ";

    sortiment->sort(2);

    /*
    int modus == 1: Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus
    int modus == 2: Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus
    int modus == 3: Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus
    int modus == 4: Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
    int modus == 5: Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
     */

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo nach sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    return 0;

}
