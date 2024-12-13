#pragma once
#include <iostream>
using namespace std;

class NodoStack {
public:
	int dato;
	NodoStack* next;

	NodoStack() {
		dato = 0;
		next = nullptr;
	}
};

class Stack {          //LIFO
public:
	Stack() {
		top = nullptr;
	}

	~Stack() {
	}

	bool push(int dato) {
		NodoStack* nuevo = nullptr;
		nuevo = new(nothrow) NodoStack;
		if (!nuevo) {
			return false;
		}
		nuevo->dato = dato;
		if (!top) {
			top = nuevo;
			return true;
		}
		nuevo->next = top;
		top = nuevo;
		return true;
	}

	bool pop() {
		if (!top) {
			return false;
		}
		NodoStack* tmp = top;
		top = top->next;
		delete tmp;
		return true;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	int* getTop() {
		if (!top) {
			return nullptr;
		}
		return &top->dato;
	}

	void imprimir() {
		NodoStack* act = top;
		while (act) {
			cout << act->dato << " ";
			act = act->next;
		}
		cout << endl;
	}

private:
	NodoStack* top;
};


