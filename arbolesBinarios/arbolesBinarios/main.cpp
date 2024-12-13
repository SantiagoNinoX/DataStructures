#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main()
{
    ArbolBinario myTree;
    myTree.inserta(2);
    myTree.inserta(3);
    myTree.inserta(1);
    cout << *myTree.buscar(1) << endl;
    cout << *myTree.buscar(2) << endl;
    myTree.printBFS();
    myTree.printInOrder();
    myTree.printPreOrder();
    myTree.printPostOrder();
    myTree.eliminarNodo(2);
    myTree.printInOrder();
    cout << endl;

    //Otro arbol
    cout << "Otro arbolito muy bonito ... " << endl;
    ArbolBinario miArbol;
    miArbol.inserta(6);
    miArbol.inserta(2);
    miArbol.inserta(8);
    miArbol.inserta(1);
    miArbol.inserta(5);
    miArbol.inserta(3);
    miArbol.inserta(4);
    miArbol.printBFS();
    cout << *miArbol.buscar(1) << *miArbol.buscar(2) << *miArbol.buscar(3) << *miArbol.buscar(4) << *miArbol.buscar(5) << *miArbol.buscar(6) << *miArbol.buscar(8) << endl;
    miArbol.printInOrder();
    miArbol.printPreOrder();
    miArbol.printPostOrder();
    cout << "Ahora borramos el 2: " << endl;
    miArbol.eliminarNodo(2);
    miArbol.printBFS();
    miArbol.printInOrder();
    miArbol.printPreOrder();
    miArbol.printPostOrder();
    return 0;
}
