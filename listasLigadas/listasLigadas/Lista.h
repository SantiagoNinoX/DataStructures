#pragma once
#include "Nodo.h"

class Lista {
private:
	Nodo* head;

public:
	Lista() {
		head = nullptr;
	}
	~Lista() {
		deleteLista();
	}
	bool insertaFinal(int dato);
	void imprimeLista();
	void deleteLista();
	bool deleteElemento(int dato);
	bool insertaInicio(int dato);
	bool borrarInicial();
	bool borrarFinal();
	bool insertaEnOrden(int elemento);
	bool busqueda(int elemento);
	int cuentaMenores(int dato);
};
