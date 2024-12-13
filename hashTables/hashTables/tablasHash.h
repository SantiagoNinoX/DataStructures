#pragma once
#include <iostream>
#include "TemplateListasDobles.h"
#include "Monstruo.h"

class TablaHash {
public:
    using HashFunction = unsigned int (*)(Monstruo& dato, unsigned int tableSize);

    
    TablaHash() {
        hashFunction = nullptr;
        table = nullptr;
        size = 0;
    }

    ~TablaHash() { 
        borrarTabla(); 
    };

    unsigned int getSize();
    bool createTable(unsigned int nSize, HashFunction hashF);
    void borrarTabla();
    bool insertar(Monstruo dato);
    bool borrar(Monstruo dato);
    Monstruo* buscar(Monstruo dato);   
    void imprimir();

private:
    ListaDoble<Monstruo>* table;
    unsigned int size;
    HashFunction hashFunction;
    unsigned int getIndex(Monstruo dato);  
};