#pragma once

class Nodo {
public:
	int dato;
	Nodo* next;
	Nodo() {
		next = nullptr;
		dato = 0;
	}
};
