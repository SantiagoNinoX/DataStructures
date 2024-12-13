#pragma once

class NodoDoble {
public:
	int dato;
	NodoDoble* prev;
	NodoDoble* next;
	NodoDoble() {
		prev = nullptr;
		next = nullptr;
		dato = 0;
	}
};
