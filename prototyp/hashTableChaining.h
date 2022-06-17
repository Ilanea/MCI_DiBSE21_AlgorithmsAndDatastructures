#include <string>
#include <list>
#include "Ware.h"

#pragma once
typedef int (*hashFunctionPtr)(std::string);    //  typedefinition of a pointer for a hashfunction; they all need conform to the guideline: int <functionName>(std::string <param>) 
int lastNumber(std::string telNr);              //  hash algorithm that uses only the last digit of a given telNr
int firstThreeNumbers(std::string telNr);       //  hash algorithm that uses the first three digits of a given telNr
int firstTwoLetters(std::string bezeichnung);   //  hash algorithm that uses the first two letters of a given bezeichnung
int lastThreeNumbers(std::string telNr);        //  hash algorithm that uses the last three digits of a given telNr
int mod17(std::string telNr);                   //  hash algorithm that takes a given telNr mod17

class HashTable {
    private:
        class HashFunction {                    //  private inner class to make hash functions managable
            public:
                int size;
                std::string name;
                hashFunctionPtr algorithm;
                
                HashFunction(std::string name, hashFunctionPtr algorithm, int size);    //  constructor
        };

        HashFunction availableAlgorithms[5] = { {"lastNumber", lastNumber, 10}, {"firstThreeNumbers", firstThreeNumbers, 1000}, {"firstTwoLetters", firstTwoLetters, 1000},  {"lastThreeNumbers", lastThreeNumbers, 1000}, {"mod17", mod17, 17}};
        
        class HashNode {                    //  private inner class for HashNodes that have a key (which will be the telephone number) and a value of type PbEntry
            public:                         
                std::string key = "";       
                Ware* lagerEntry;
        };

    public:
        int size;                       //  m in lecture
        int numberOfEntries;            //  n in lecture
        std::list<Ware*> *entries;              //  nodes of the hash table
        hashFunctionPtr hashFunction;   //  pointer to the hash algorithm used is stored in a private variable of type hashFunctionPtr - see beginning of this file


        void insert(Ware* entry);
        const Ware* search(std::string key);
        bool deleteItem(std::string key);
        void print();
        void setHashFunction(std::string name);

        HashTable();                        //  default constructor
};