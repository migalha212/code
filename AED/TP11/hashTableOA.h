// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// A simple lightweight implemetation of hash tables
// (using open addressing, a.k.a. closed hashing)
// Last update: 08/12/2024
//* Used for Exercise 69
// -------------------------------------------------------------

#ifndef _HASHTABLEOA_H_
#define _HASHTABLEOA_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>

template <class KeyType> class HashTableOA
{
    enum EntryType { EMPTY, ACTIVE, DELETED }; // Type of table entry
    struct HashEntry
    {                       // One table entry
        EntryType state;
        KeyType key;
    };

    int size;                                      // Size of the hash table
    int numberActive;                              // Number of active table entries (with keys)
    int numberDeleted;                             // Number of deleted table entries
    std::vector<HashEntry> table;                  // The hash table itself
    std::function<unsigned(const KeyType&)> hash; // Hash function: key -> unsigned

public:
    // Constructor: receives the table size n and the hash function h
    HashTableOA(int n, std::function<unsigned(const KeyType&)> h) :
        size(n), numberActive(0), numberDeleted(0), table(n), hash(h) {
        for (int i = 0; i < size; i++) table[i].state = EMPTY;
    }

    // Show contents of hash table (to check if implementation is correct)
    void showContents() {
        std::cout << "Size: " << size << " | Nr Active: " << numberActive
            << " | Nr Deleted: " << numberDeleted << " | Load Factor: "
            << std::fixed << std::setprecision(3)
            << (double) (numberActive + numberDeleted) / size << std::endl;
        std::cout << "Table:";
        for (int i = 0; i < size; i++) {
            if (table[i].state == EMPTY) std::cout << " {}";
            else if (table[i].state == DELETED) std::cout << " DEL";
            else std::cout << " " << table[i].key;
        }
        std::cout << std::endl;
    }

    // ---------------------------------------------------------
    // TODO: functions to implement in this exercise
    // ---------------------------------------------------------


        // Does it contain key k?
    bool contains(const KeyType& k) {
        for(int i = 0; i < size; i++){
            if(table[i].key == k && this->table[i].state == ACTIVE){
                return true;
            }
        }
    return false;
    }

    // Insert key k (true if successful)
    bool insert(const KeyType& k) {
        if(!contains(k)){
            int pos = hash(k) % size;
            if(table[pos].state == ACTIVE){
                for(int i = (pos + 1) % size; i != pos;i = (i + 1) % size){
                    if(table[i].state != ACTIVE){
                        pos = i;
                        break;
                    }
                }
                if (table[pos].state == ACTIVE) return false; // no empty spots
            } 
            if(table[pos].state == DELETED) numberDeleted--;
            if(numberActive + 1 + numberDeleted == size) {return false;}
            this->table[pos].state = ACTIVE;
            this->table[pos].key = k;
            numberActive++;
            return true;
        }
        return false;
    }

    // Remove key k (true if successful)
    bool remove(const KeyType& k) {
        for (int i = 0; i < size; i++) {
            if (table[i].key == k && this->table[i].state == ACTIVE) {
                table[i].state = DELETED;
                numberActive--; numberDeleted++;
                return true;
            }
        }
    return false;
    }
};

#endif
