//Multiplication method for hashing
//U = {0, 1, 2...}
#include <iostream>
#include <cmath>

const int M = 16324;                  // size of the hashtable
const double A = (sqrt(5) - 1) / 2.0; //knuth's suggestion

int hash(double key)
{
    // h(k) = floor(m * ((key * A) mod 1))
    key = key * A;
    key = fmod(key, 1.0);
    int hk = floor(M * key);
    return hk;
}

void insert(int *hashTable, int key)
{
    int index = hash(key);
    hashTable[index] = key;
}

int search(int *hashTable, int key)
{
    //returns -1 if not found
    int index = hash(key);
    int result = hashTable[hash(key)];
    return result;
}

void tableDel(int *hashTable, int key)
{
    hashTable[hash(key)] = -1;
}

int main()
{
    int key = 6447;
    int hashTable[16324] = {-1};
    insert(hashTable, key);
    std::cout << search(hashTable, key) << std::endl;
    tableDel(hashTable, key);
    std::cout << search(hashTable, key) << std::endl;
}
