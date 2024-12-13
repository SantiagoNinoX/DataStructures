#pragma once
#include <iostream>
#include "TemplateListasDobles.h"
using namespace std;

template <typename T>
class TablaHash {
public:
    using HashFunction = unsigned int (*)(T& dato, unsigned int tableSize);


    TablaHash() {
        hashFunction = nullptr;
        table = nullptr;
        size = 0;
    }

    ~TablaHash() {
        borrarTabla();
    };

    unsigned int getSize() {
        return size;
    }

    bool createTable(unsigned int nSize, HashFunction hashF) {
        if (nSize == 0 || table != nullptr || !hashF) {
            return false;
        }
        table = new(nothrow) ListaDoble<T>[nSize];
        if (!table) {
            return false;
        }
        size = nSize;
        hashFunction = hashF;
        return true;
    }

    void borrarTabla() {
        if (!size) {
            return;
        }
        if (table) {
            delete[] table;
            table = nullptr;
            size = 0;
        }
    }

    bool insertar(T dato) {
        unsigned int index = 0;
        if (!table) {
            return false;
        }
        index = getIndex(dato);
        return table[index].insertaFinalDoble(dato);
    }

    bool borrar(T dato) {
        unsigned int hashValue = 0;
        if (!table) {
            return false;
        }
        hashValue = getIndex(dato);
        return table[hashValue].deleteElementoDoble(dato);
    }

    T* buscar(T dato) {
        unsigned int index = 0;
        if (!table) {
            return nullptr;
        }
        index = getIndex(dato);
        return table[index].busquedaDoble(dato);
    }

    void imprimir() {
        unsigned int longest = 0;
        for (unsigned int k = 0; k < size; k++) {
            unsigned int lSize = 0;
            lSize = table[k].getSize();
            if (lSize > longest) {
                longest = lSize;
            }
            cout << "tabla[" << k << "]: " << lSize << endl;
        }
        cout << "Longest was: " << longest << endl;
    }

private:
    ListaDoble<T>* table;
    unsigned int size;
    HashFunction hashFunction;

    unsigned int getIndex(T dato) {
        if (!hashFunction) {
            return 0;
        }
        return hashFunction(dato, size);
    }
};
