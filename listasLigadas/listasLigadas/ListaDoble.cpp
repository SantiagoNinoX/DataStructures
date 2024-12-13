#include <iostream>
#include "ListaDoble.h"
using namespace std;

bool ListaDoble::insertaFinalDoble(int dato) {
	NodoDoble* nuevo = nullptr;
	nuevo = new(nothrow) NodoDoble;
	if (!nuevo) {
		return false;
	}
	nuevo->dato = dato;
	if (!head) {
		head = tail = nuevo;
		return true;
	}
	else {
		tail->next = nuevo;
		nuevo->prev = tail;
		tail = nuevo;
	}
	return true;
}

void ListaDoble::imprimeListaDoble() {
	NodoDoble* tmp = head;
	if (!tmp) {
		cout << "No se encontro la lista." << endl;
	}
	while (tmp) {
		cout << tmp->dato << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void ListaDoble::imprimeListaDobleAlReves() {
	NodoDoble* tmp = tail;
	if (!tmp) {
		cout << "No se encontro la lista." << endl;
	}
	while (tmp) {
		cout << tmp->dato << " ";
		tmp = tmp->prev;
	}
	cout << endl;
}

void ListaDoble::deleteListaDoble() {
	NodoDoble* actual = head;
	while (actual) {
		NodoDoble* temp = actual->next;
		delete actual;
		actual = temp;
	}
	head = nullptr;
	tail = nullptr;
}

bool ListaDoble::deleteElementoDoble(int elemento) {   
	if (!head) {
		return false;
	}
	NodoDoble* actual = head;
	NodoDoble* anterior = nullptr;
	NodoDoble* siguiente = nullptr;

	while (actual) {
		if (actual->dato == elemento) {
			anterior = actual->prev;
			siguiente = actual->next;
			if (anterior && siguiente) {
				anterior->next = siguiente;
				siguiente->prev = anterior;
			}
			else if (!anterior){
				head = siguiente;
				if (head) {
					head->prev = nullptr;
				}
			}
			else if (!siguiente) {
				tail = anterior;
				tail->next = nullptr;
			}
			delete actual;
			actual = nullptr;
			return true;
		}
		actual = actual->next;
	}
	cout << "No se encontro el elemento a borrar " << elemento << endl;
	return false;
}

bool ListaDoble::insertaInicioDoble(int dato) {
	NodoDoble* nuevo = nullptr;
	nuevo = new(nothrow) NodoDoble;
	if (!nuevo) {
		return false;
	}
	nuevo->dato = dato;
	if (!head) {
		head = tail = nuevo;
		return true;
	}
	else {
		head->prev = nuevo;
		nuevo->next = head;
		head = nuevo;
	}
	return true;
}

bool ListaDoble::borrarInicialDoble() {
	if (!head) {
		return false;
	}
	NodoDoble* inicial = head;
	head = inicial->next;
	if (head) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}
	delete inicial;
	inicial = nullptr;
	return true;
}

bool ListaDoble::borrarFinalDoble() {
	if (!head) {
		return false;
	}
	if (!head->next) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	NodoDoble* actual = tail;
	NodoDoble* anterior = actual->prev;
	if (anterior) {
		anterior->next = nullptr;
	}
	tail = anterior;
	delete actual;
	actual = nullptr;
	return true;
}

bool ListaDoble::insertaEnOrdenDoble(int elemento) {    
	NodoDoble* tmp = nullptr, * nuevo = nullptr;
	nuevo = new(nothrow) NodoDoble;
	if (!nuevo) {
		return false;
	}
	nuevo->dato = elemento;
	nuevo->next = nullptr;
	nuevo->prev = nullptr;
	if (!head) {
		head = nuevo;
		tail = nuevo;
		return true;
	}
	if (head->dato > elemento) {
		nuevo->next = head;
		head->prev = nuevo;
		head = nuevo;
		return true;
	}
	tmp = head;
	while (tmp->next && tmp->next->dato < elemento) {
		tmp = tmp->next;
	}
	nuevo->next = tmp->next;
	nuevo->prev = tmp;
	if (tmp->next) {
		tmp->next->prev = nuevo;
	}
	else {
		tail = nuevo;
	}
	tmp->next = nuevo;
	return true;
}

bool ListaDoble::busquedaDoble(int elemento) {
	if (!head) {
		cout << "La lista esta vacia." << endl;
		return false;
	}
	NodoDoble* actual = head;

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

bool ListaDoble::eliminaPosicion(int pos) {
	if (!head) {
		return false;
	}
	if (!head->next) {
		if (pos == 0) {
			delete head;
			head = nullptr;
			return true;
		}
		else {
			cout << "La lista solo tiene 1 elemento" << endl;
			return false;
		}
	}
	NodoDoble* act = head;
	if (pos == 0) {
		act->next->prev = nullptr;
		head = act->next;
		delete act;
		act = nullptr;
		return true;
	}
	int cont = 0;
	while (cont != pos && act->next) {
		cont++;
		act = act->next;
	}
	NodoDoble* anterior = act->prev;
	NodoDoble* siguiente = act->next;
	if (act->next) {
		if (anterior) {
			anterior->next = siguiente;
		}
		if (siguiente) {
			siguiente->prev = anterior;
		}
		if (act) {
			delete act;
			act = nullptr;
			return true;
		}
	}
	else {
		if (cont == pos) {
			if (anterior) {
				anterior->next = nullptr;
			}
			if (act) {
				delete act;
				act = nullptr;
				return true;
			}
		}
	}
	cout << "No se encontro la posicion ingresada." << endl;
	return false;
}