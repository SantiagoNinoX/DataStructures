#pragma once
#include <iostream>
using namespace std;

class NodoCola {
public:
	int dato;
	NodoCola* next;

	NodoCola() {
		dato = 0;
		next = nullptr;
	}
};

class Queue {     //FIFO
public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	~Queue() {
	}

	bool enqueue(int dato) {
		NodoCola* nuevo = nullptr;
		nuevo = new(nothrow) NodoCola;
		if (!nuevo) {
			return false;
		}
		nuevo->dato = dato;
		if (!rear) {
			front = nuevo;
			rear = nuevo;
			return true;
		}
		rear->next = nuevo;
		rear = nuevo;
		return true;
	}

	bool dequeue() {
		if (!front) {
			return false;
		}
		NodoCola* tmp = front;
		front = front->next;
		if (!front) {
			rear = nullptr;
		}
		tmp->next = nullptr;
		delete tmp;
		return true;
	}

	int* peek_getFront(){
		if (!front) {
			return nullptr;
		}
		else {
			return &front->dato;
		}
	}

	bool isEmpty() {
		return front == nullptr;
	}

	void imprimir() {
		NodoCola* act = front;
		while (act) {
			cout << act->dato << " ";
			act = act->next;
		}
		cout << endl;
	}

private:
	NodoCola* front;
	NodoCola* rear;
};
