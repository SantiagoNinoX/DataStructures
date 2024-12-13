#include <iostream>
#include "Lista.h"
using namespace std;

bool Lista::insertaFinal(int dato) {
	Nodo* tmp = nullptr, * nuevo = nullptr;
	nuevo = new(nothrow) Nodo;
	if (!nuevo) {
		return false;
	}
	nuevo->dato = dato;
	if (!head) {
		head = nuevo;
		return true;
	}
	tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = nuevo;
	return true;
}

void Lista::imprimeLista() {
	Nodo* tmp = head;
	while (tmp) {
		cout << tmp->dato << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void Lista::deleteLista() {
	Nodo* actual = head;
	while (actual) {
		Nodo* temp = actual->next;
		delete actual;
		actual = temp;
	}
	head = nullptr;
}

bool Lista::deleteElemento(int elemento) {
	if (!head) {
		return false;
	}
	Nodo* actual = head;
	Nodo* anterior = nullptr;

	while (actual) {
		if (actual->dato == elemento) {
			if (anterior) {     
				anterior->next = actual->next;
			}
			else {
				head = actual->next;
			}
			delete actual;
			actual = nullptr;
			return true;
		}
		anterior = actual;
		actual = actual->next;
	}
	cout << "No se encontro el elemento a borrar " << elemento << endl;
	return false;
}

bool Lista::insertaInicio(int dato) {
	Nodo* nuevo = nullptr;
	nuevo = new(nothrow) Nodo;
	if (!nuevo) {
		return false;
	}
	nuevo->dato = dato;
	nuevo->next = head;
	head = nuevo;
	return true;
}

bool Lista::borrarInicial() {
	if (!head) {
		return false;
	}
	Nodo* inicial = head;
	head = inicial->next;
	delete inicial;
	inicial = nullptr;
	return true;
}

bool Lista::borrarFinal() {
	if (!head) {
		return false;
	}
	if (!head->next) {
		delete head;
		head = nullptr;
		return true;
	}
	Nodo* actual = head;
	Nodo* anterior = nullptr;
	while (actual->next) {
		anterior = actual;
		actual = actual->next;
	}
	anterior->next = nullptr;
	delete actual;
	actual = nullptr;
	return true;
}

bool Lista::insertaEnOrden(int elemento) {
	Nodo* tmp = nullptr, * nuevo = nullptr;
	nuevo = new(nothrow) Nodo;
	if (!nuevo) {
		return false;
	}
	nuevo->dato = elemento;
	nuevo->next = nullptr;
	if (!head) {
		head = nuevo;
		return true;
	}
	if (head->dato > elemento) {
		nuevo->next = head;
		head = nuevo;
		return true;
	}
	tmp = head;
	while (tmp->next && tmp->next->dato < elemento) {
		tmp = tmp->next;
	}
	nuevo->next = tmp->next;
	tmp->next = nuevo;
	return true;
}

bool Lista::busqueda(int elemento) {
	if (!head) {
		cout << "La lista esta vacia." << endl;
		return false;
	}
	Nodo* actual = head;

	while (actual) {
		if (actual->dato == elemento) {
			cout << "El elemento " << elemento << " se encuentra en el Nodo cuyo pointer es: " << actual << endl;
			return true;
		}
		actual = actual->next;
	}
	cout << "No se encontro al Nodo que contiene al elemento " << elemento << endl;
	return false;
}

int Lista::cuentaMenores(int dato) {
	if (!head){
		cout << "La lista esta vacia." << endl;
		return 0;
	}
	int cont = 0;
	Nodo* actual = head;
	while (actual) {
		if (actual->dato < dato) {
			cont++;
		}
		actual = actual->next;
	}
	//cout << "Elementos menores a " << dato << " son: " << cont << endl;
	return cont;
}