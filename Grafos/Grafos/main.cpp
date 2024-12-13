#include <iostream>
#include "Grafo.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";
    Grafo grafo;
    grafo.crearGrafo(5);
    grafo.insertarArista(0, 1);
    grafo.insertarArista(0, 2);
    grafo.insertarArista(0, 3);
    grafo.insertarArista(1, 0);
    grafo.insertarArista(1, 2);
    grafo.insertarArista(2, 0);
    grafo.insertarArista(2, 1);
    grafo.insertarArista(2, 4);
    grafo.insertarArista(3, 0);
    grafo.insertarArista(4, 2);
    grafo.imprimirGrafo();
    grafo.DFS_recursivo(0);
    cout << endl;
    grafo.DFS_iterativo(0);
    if (grafo.guardarArchivo("grafito.txt")) {
        cout << "Se creo el archivo grafito.txt" << endl;
    }

    Grafo grafote;
    if (!grafote.cargarArchivo("grafote.txt")) {
        cout << "No se cargo el archivo grafote.txt" << endl;
    }
    grafote.imprimirGrafo();

    Grafo grafito;
    grafito.crearGrafo(5);
    grafito.insertarArista(0, 1);
    grafito.insertarArista(0, 2);
    grafito.insertarArista(1, 0);
    grafito.insertarArista(1, 2);
    grafito.insertarArista(1, 3);
    grafito.insertarArista(2, 0);
    grafito.insertarArista(2, 1);
    grafito.insertarArista(2, 4);
    grafito.insertarArista(3, 1);
    grafito.insertarArista(3, 4);
    grafito.insertarArista(4, 2);
    grafito.insertarArista(4, 3);
    grafito.imprimirGrafo();
    grafito.BFS(0);
    grafito.printPathBFS(0,4);
    grafito.dijkstra(0);

    Grafo otrografo;
    otrografo.crearGrafo(7);
    otrografo.insertarArista(0, 1);
    otrografo.insertarArista(0, 2);
    otrografo.insertarArista(1, 0);
    otrografo.insertarArista(1, 3);
    otrografo.insertarArista(2, 0);
    otrografo.insertarArista(2, 3);
    otrografo.insertarArista(3, 1);
    otrografo.insertarArista(3, 2);
    otrografo.insertarArista(3, 4);
    otrografo.insertarArista(3, 5);
    otrografo.insertarArista(4, 3);
    otrografo.insertarArista(4, 5);
    otrografo.insertarArista(4, 6);
    otrografo.insertarArista(5, 3);
    otrografo.insertarArista(5, 4);
    otrografo.insertarArista(5, 6);
    otrografo.insertarArista(6, 4);
    otrografo.insertarArista(6, 5);
    cout << endl;
    otrografo.dijkstra(0);

    return 0;
}
