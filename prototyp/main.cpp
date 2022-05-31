#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include "Sortiment.h"
#include "extendedBinaryTree.h"

std::string random_string(int Dist, std::size_t length){
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(0, Dist);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i){
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int main() {

    srand((unsigned) time(NULL));

    Sortiment *sortiment = new Sortiment();

    Ware *rootWare = new Ware("ROOT", 1, 1, 1, 100);
    BinaryTree *binaryTree = new BinaryTree(rootWare);

    for(int i = 0; i < 10; i++){
        int Dist = rand() % 62;
        int seriennummer = rand() % 1000 + 1;
        int gewicht = rand() % 1000 + 1;
        int einkaufspreis = rand() % 1000 + 1;
        int verkaufspreis = rand() % 1000 + 1;
        Ware *ware = new Ware(random_string(Dist,5), seriennummer, gewicht, einkaufspreis, verkaufspreis);
        sortiment->addWare(ware);
        binaryTree->insert(ware);
    }

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo vor sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Sortieren: ";

    //sortiment->sort(5);

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


    std::cout << "Binary Tree" << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << binaryTree->printPreorder() << "\n";

    delete sortiment;

    return 0;

}
