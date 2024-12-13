#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>
using namespace std;

int main() {
    // STACK = PILA = LIFO.
    cout << "Pila / Stack: " << endl;
    Stack pila;
    pila.push(1);
    pila.imprimir();
    pila.pop();
    pila.imprimir();
    pila.push(2);
    pila.imprimir();
    pila.push(3);
    pila.imprimir();
    pila.pop();
    pila.imprimir();
    cout << pila.getTop() << endl;
    cout << *pila.getTop() << endl;
    if (!pila.isEmpty()) {
        cout << "Stack no esta vacia" << endl;
    }
    pila.pop();
    if (pila.isEmpty()) {
        cout << "Stack esta vacia" << endl;
    }
    pila.push(5);
    pila.push(12);
    pila.imprimir();
    int* valor = nullptr;
    valor = pila.getTop();
    if (valor) {
        cout << "El valor top es: " << *valor << endl;
    }
    else {
        cout << "No existe top" << endl;
    }

    // QUEUE = COLA = FIFO.
    cout << "Queue / Cola: " << endl;
    Queue cola;
    cola.enqueue(5);
    cola.imprimir();
    cola.enqueue(2);
    cola.imprimir();
    cola.enqueue(3);
    cola.imprimir();
    cola.dequeue();
    cola.imprimir();
    cout << cola.peek_getFront() << endl;
    cout << *cola.peek_getFront() << endl;
    int* peek = nullptr;
    peek = cola.peek_getFront();
    if (peek) {
        cout << "El valor front es: " << *peek << endl;
    }
    else {
        cout << "No existe front" << endl;
    }
    cola.dequeue();
    cola.imprimir();
    if (!cola.isEmpty()) {
        cout << "La queue no esta vacia" << endl;
    }
    cola.dequeue();
    cola.imprimir();
    if (cola.isEmpty()) {
        cout << "La queue esta vacia" << endl;
    }

    return 0;
}