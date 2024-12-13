#include "hashtable.h"

using namespace std;

bool HashTable::creatTable(unsigned int nSize) {
    if(nSize == 0 || table != nullptr)
        return false;

    table = new(std::nothrow) ListaDL<Monster>[nSize];
    if(!table)
        return false;
    size = nSize;
    return true;
}

void HashTable::borraTabla() {
    if(table) {
        delete [] table;
        table = nullptr;
        size = 0;
    }
}

unsigned int HashTable::hashMonsterToIndex(Monster dato) {
    string name;
    unsigned int hashValue = 0, len = 0;

    name = dato.getName();
    len = name.length();
    for(unsigned int l = 0; l < len; l ++)
        hashValue = hashValue + name[l];
    return hashValue % size;
}

bool HashTable::insertar(Monster dato) {
    unsigned int index = 0;

    if(!table)
        return false;

    
    index = hashMonsterToIndex(dato);
    return table[index].insertarFinal(dato);
}

bool HashTable::borrar(Monster dato) {
    return true;
}

Monster *HashTable::buscar(string name) {
    unsigned int index = 0;

    if(!table)
        return nullptr;

    index = hashMonsterToIndex(dato);
    return table[index].buscar(dato);
}