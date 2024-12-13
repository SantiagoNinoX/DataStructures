#include <iostream>
#include "Base.h"
using namespace std;

int main()
{
    Base base;

    unsigned int tamanio = 0;
    int elemento;
    do {
        cout << "Dame el tamaño del arreglo: ";
        cin >> tamanio;
    } while (tamanio == 0);

    if (!base.setSize(tamanio)) {
        cout << "No hubo memoria" << endl;
        return 0;
    }

    int opcion = -1;
    while (opcion != 0) {
        cout << "Elige una opcion para el SORT: " << endl;
        cout << "1) Bubble Sort. " << endl;
        cout << "2) Insertion Sort." << endl;
        cout << "3) Selection Sort." << endl;
        cout << "4) Merge Sort." << endl;
        cout << "5) Quick Sort." << endl;
        cout << "6) Búsqueda Binaria." << endl;
        cout << "7) Salir." << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Has seleccionado Bubble Sort." << endl;
            //BUBBLE O(n2).
            base.iniciarArreglo();
            cout << "El arreglo es: " << endl;
            base.imprimirArreglo();
            cout << "El arreglo ordenado por BUBBLE SORT es: " << endl;
            base.bubbleSort();
            base.imprimirArreglo();
            break;

        case 2:
            cout << "Has seleccionado Insertion Sort." << endl;
            //INSERTION O(n2).
            cout << "El arreglo es: " << endl;
            base.iniciarArreglo();
            base.imprimirArreglo();
            cout << "El arreglo ordenado por INSERTION SORT es: " << endl;
            base.insertionSort();
            base.imprimirArreglo();
            break;

        case 3: 
            cout << "Has seleccionado Selection Sort." << endl;
            //SELECTION O(n2).
            cout << "El arreglo es: " << endl;
            base.iniciarArreglo();
            base.imprimirArreglo();
            cout << "El arreglo ordenado por SELECTION SORT es: " << endl;
            base.selectionSort();
            base.imprimirArreglo();
            break;

        case 4:
            cout << "Has seleccionado Merge Sort." << endl;
            //MERGE O(n log n). 
            cout << "El arreglo es: " << endl;
            base.iniciarArreglo();
            base.imprimirArreglo();
            cout << "El arreglo ordenado por MERGE SORT es: " << endl;
            base.mergeSortear();
            base.imprimirArreglo();
            break;
        
        case 5:
            cout << "Has seleccionado Quick Sort." << endl;
            //QUICK O(n log n) en el mejor de los casos, O(n^2) si ya está ordenado.
            cout << "El arreglo es: " << endl;
            base.iniciarArreglo();
            base.imprimirArreglo();
            cout << "El arreglo ordenado por QUICK SORT es: " << endl;
            base.quickSortear();
            base.imprimirArreglo();
            break;

        case 6: 
            cout << "Has seleccionado Búsqueda Binaria." << endl;
            //BUSQUEDA BINARIA O(log n) promedio y peor caso, O(1) en el mejor de los casos.
            base.iniciarArreglo();
            base.imprimirArreglo();
            cout << "Ingresa el elemento a buscar: " << endl;
            cin >> elemento;
            base.quickSortear();
            base.imprimirArreglo();
            int resultado;
            resultado = base.busquedaBinario(elemento);
            if (resultado != -1) {
                cout << "Elemento encontrado en la posicion: " << resultado << endl;
            }
            else {
                cout << "Elemento no encontrado dentro del arreglo." << endl;
            }
            break;

        case 7:
            cout << "Has salido." << endl;
            opcion = 0;
            return 0;

        default:
            cout << "Opcion incorrecta. Ingresa un numero del 1 al 5." << endl;
        }
    }
    return 0;
}