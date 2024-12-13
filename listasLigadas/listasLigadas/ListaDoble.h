#pragma once
#include "NodoDoble.h"

class ListaDoble {
private:
	NodoDoble* head;
	NodoDoble* tail;

public:
	ListaDoble() {
		head = nullptr;
		tail = nullptr;
	}
	~ListaDoble() {
		deleteListaDoble();
	}
	bool insertaFinalDoble(int dato);
	void imprimeListaDoble();
	void imprimeListaDobleAlReves();
	void deleteListaDoble();
	bool deleteElementoDoble(int dato);    
	bool insertaInicioDoble(int dato);
	bool borrarInicialDoble();
	bool borrarFinalDoble();
	bool insertaEnOrdenDoble(int elemento);       
	bool busquedaDoble(int elemento);
	bool eliminaPosicion(int pos);
};
