#include "hashTableChaining.h"
#include <iostream>
#include <list>
#include <algorithm>

HashTable::HashTable() {
    this->size = 0;
    this->entries = nullptr;
    this->setHashFunction("firstTwoLetters");
}

HashTable::HashFunction::HashFunction(std::string name, hashFunctionPtr algorithm, int size) {
    this->name = name;
    this->algorithm = algorithm;
    this->size = size;
}

void HashTable::insert(Ware* entry) {
    int hashValue = this->hashFunction(entry->getBezeichnung());
    hashValue = hashValue % this->size;

    entries[hashValue].push_back(entry);

}

void HashTable::print() {
    std::cout << "=====================================" << std::endl;
    for(int i = 0; i < this->size; i++) {
        if(!entries[i].empty()){
            std::cout << i << " :\t";
            std::cout << "[";
            for(auto const &j : entries[i]){
                std::cout << j->getBezeichnung() << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
    std::cout << "=====================================" << std::endl;
}

void HashTable::setHashFunction(std::string algorithmName) {
    for(int i = 0; i < 4; i++) {
        if(this->availableAlgorithms[i].name == algorithmName) {
            this->hashFunction = this->availableAlgorithms[i].algorithm;
            this->size = this->availableAlgorithms[i].size;
            if(this->entries != nullptr) {
                delete[] this->entries;
            }
            this->entries = new std::list<Ware*>[this->size];
            return;
        }
    }

    std::cerr << "The Hash Function provided was not found!" << std::endl;
}


const Ware* HashTable::search(std::string key) {
    int hashValue = this->hashFunction(key);    //  key is "hashed" and stored in the variable int hashValue
    hashValue = hashValue % this->size;

    if(entries[hashValue].empty()){
        std::cout << "Hashtable is empty, no entries" << std::endl;
        return nullptr;
    }
    else{
        for(auto i : entries[hashValue]){
            if(i->getBezeichnung() == key){
                std::cout << "Ware mit der Bezeichnung " << key << " im Lager gefunden!" << std::endl;
                return i;
            }
        }
        std::cout << "Ware mit der Bezeichnung " << key << " wurde nicht gefunden!" << std::endl;
        return nullptr;
    }


}

bool HashTable::deleteItem(std::string key) {
    int hashValue = this->hashFunction(key);
    hashValue = hashValue % this->size;

    if(entries[hashValue].empty()){
        std::cout << "Hashtable is empty, no entries" << std::endl;
        return false;
    }
    else{
        for(auto i : entries[hashValue]){
            if(i->getBezeichnung() == key){
                entries[hashValue].remove(i);
                std::cout << "Ware mit der Bezeichnung " << key << " wurde geloescht!" << std::endl;
                return true;
            }
        }
        std::cout << "Ware mit der Bezeichnung " << key << " wurde nicht gefunden!" << std::endl;
        return false;
    }
}



/*  algorithm that "hashes" the last digit of a number  */
int lastNumber(std::string telNr) {
    if(telNr.length() <=0) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 1 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-1, telNr.end()));
}

/*  algorithm that "hashes" the first three digits of a number  */
int firstThreeNumbers(std::string telNr) {
        if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.begin(), telNr.begin()+3));
}

/*  algorithm that "hashes" the first two letters of a bezeichnung  */
int firstTwoLetters(std::string bezeichnung) {
    if(bezeichnung.length() < 2) {
        std::cerr << "Bezeichnung '" << bezeichnung << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }

    std::string first_two = bezeichnung.substr(0, 2);
    int ascii = int(first_two[0]) + int(first_two[1]);

    //std::cout << "ASCII Value of first 2 Characters: " << ascii << std::endl;

    return ascii;
}

/*  algorithm that "hashes" the last three digits of a number  */
int lastThreeNumbers(std::string telNr) {
    if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-3, telNr.end()));
}

/*  algorithm that "hashes" the through mod17  */
int mod17(std::string telNr) {
    return (int)(std::stol(telNr)%17);
}

