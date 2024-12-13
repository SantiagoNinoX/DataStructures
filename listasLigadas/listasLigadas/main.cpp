#include <iostream>
#include "Lista.h"
#include "ListaDoble.h"
#define MAX_DATA 20
using namespace std;

int main()
{   
    // LISTA SENCILLA LIGADA.
    cout << "Lista sencilla ligada." << endl;
    Lista prueba;
    for (int i = 0; i < MAX_DATA; i++) {
        if (!prueba.insertaFinal(i)) {
            cout << "No hubo memoria." << endl;
            return 0;
        }
    }
    prueba.imprimeLista();
    //prueba.deleteLista();
    prueba.deleteElemento(5);
    prueba.imprimeLista();
    prueba.insertaInicio(19);
    prueba.imprimeLista();
    prueba.borrarInicial();
    prueba.imprimeLista();
    prueba.insertaFinal(23);
    prueba.imprimeLista();
    prueba.borrarFinal();
    prueba.imprimeLista();
    prueba.insertaEnOrden(5);
    prueba.imprimeLista();
    prueba.busqueda(10);
    prueba.busqueda(5);
    prueba.busqueda(23);
    prueba.busqueda(1);
    prueba.deleteElemento(21);
    prueba.imprimeLista();
    prueba.deleteElemento(12);
    prueba.imprimeLista();
    prueba.cuentaMenores(12);

    // LISTA DOBLEMENTE LIGADA.
    cout << "Lista doble ligada." << endl;
    ListaDoble prueba2;
    for (int i = 0; i < MAX_DATA; i++) {
        if (!prueba2.insertaFinalDoble(i)) {
            cout << "No hubo memoria." << endl;
            return 0;
        }
    }
    prueba2.imprimeListaDoble();
    //prueba2.deleteListaDoble();
    prueba2.deleteElementoDoble(5);
    prueba2.imprimeListaDoble();
    prueba2.insertaInicioDoble(20);
    prueba2.imprimeListaDoble();
    prueba2.borrarInicialDoble();
    prueba2.imprimeListaDoble();
    prueba2.insertaFinalDoble(25);
    prueba2.imprimeListaDoble();
    prueba2.borrarFinalDoble();
    prueba2.imprimeListaDoble();
    prueba2.insertaEnOrdenDoble(5);
    prueba2.imprimeListaDoble();
    prueba2.busquedaDoble(10);
    prueba2.busquedaDoble(5);
    prueba2.busquedaDoble(0);
    prueba2.busquedaDoble(25);
    prueba2.busquedaDoble(19);
    prueba2.imprimeListaDoble();
    prueba2.imprimeListaDobleAlReves();
    prueba2.deleteElementoDoble(21);
    prueba2.imprimeListaDoble();
    prueba2.eliminaPosicion(19);
    prueba2.imprimeListaDoble();

    return 0;
}
