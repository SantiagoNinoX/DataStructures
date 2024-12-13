#pragma once
#include <iostream>
#include "tablasHash.h" //Catalogo es una TablaHash
#include "Monstruo.h"  //Catalogo contiene monstruos
#include <fstream>
#include <sstream>
using namespace std;
#define ARCHIVO "monsters.csv"   

class Catalogo {
public: 
    Catalogo() {
        srand(time(0));   //Semilla para generar numeros rand
        contadorDeMonstruos = contarMonstruosenCSV(ARCHIVO);
    }

    ~Catalogo() {
        catalog.borrarTabla();
    }

    bool loadFromCSV(const string& filename);  //Complejidad de los metodos: O(n)
    unsigned int contarMonstruosenCSV(const string& filename);  
    Monstruo* buscar(string name);
    void imprimir();

private:
    TablaHash catalog;
    unsigned int contadorDeMonstruos; 
};