#include "tablasHash.h"

using namespace std;

unsigned int TablaHash::getSize() {
    return size;
}

unsigned int TablaHash::getIndex(Monstruo dato) {
    if (!hashFunction) {
        return 0;
    }
    return hashFunction(dato, size) % size;
}

bool TablaHash::createTable(unsigned int nSize, HashFunction hashF) {
    if (nSize == 0 || table != nullptr || !hashF) {
        return false;
    }
    table = new(nothrow) ListaDoble<Monstruo>[nSize];
    if (!table) {
        return false;
    }
    size = nSize;
    hashFunction = hashF;
    return true;
}

void TablaHash::borrarTabla() {
    if (table) {
        delete [] table;
        table = nullptr;
        size = 0;
    }
}

bool TablaHash::insertar(Monstruo dato) {
    unsigned int index = 0;
    if (!table) {
        return false;
    }
    index = getIndex(dato);
    return table[index].insertaFinalDoble(dato);
}

bool TablaHash::borrar(Monstruo dato) {
    unsigned int hashValue = 0;
    if (!table) {
        return false;
    }
    hashValue = getIndex(dato);
    return table[hashValue].deleteElementoDoble(dato);
}

Monstruo* TablaHash::buscar(Monstruo dato) {   //string name
    unsigned int index = 0;
    if (!table) {
        return nullptr;
    }
    index = getIndex(dato);
    return table[index].busquedaDoble(dato);
}

void TablaHash::imprimir() {
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