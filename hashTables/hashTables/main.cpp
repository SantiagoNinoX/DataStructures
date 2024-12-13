#include <iostream>
#include "tablasHash.h"
#include "Monstruo.h"
#include "TemplateListasDobles.h"
#include "Catalogo.h"
using namespace std;

int main()
{
    Catalogo miCatalogo;
    if (!miCatalogo.loadFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
    }
    miCatalogo.imprimir();
    Monstruo* res = miCatalogo.buscar("cat");
    if (res) {
        cout << *res << endl;
    }
    else {
        cout << "No se encontro cat" << endl;
    }
    return 0;
}

