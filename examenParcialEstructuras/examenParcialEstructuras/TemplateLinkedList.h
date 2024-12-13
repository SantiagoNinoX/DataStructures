#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
	T dato;
	Nodo<T>* next;

	Nodo(T dato) : dato(dato), next(nullptr) {}
};

template <typename T>
class ListaLigada {
private:
	Nodo<T>* head;
public:
	ListaLigada() {
		head = nullptr;
	}

	~ListaLigada() {
		borraLista();
	}

	bool insertarFinal(T dato) {    // Complejidad: O(n)
		Nodo<T>* nuevo = nullptr;
		nuevo = new (nothrow) Nodo<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (!head) {
			head = nuevo;
			return true;
		}
		Nodo<T>* tmp = head;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = nuevo;
		return true;
	}

	void borraLista() {                  //Complejidad: O(n)
		Nodo<T>* act = nullptr;
		act = head;
		while (act) {
			Nodo<T>* tmp = act->next;
			delete act;
			act = tmp;
		}
		head = nullptr;
	}


	bool insertarInicio(T dato) {             //Complejidad: O(1) por no contar con ciclos.
		Nodo<T>* nuevo = nullptr;               //Operaciones inmediatas, es constante.
		nuevo = new(nothrow) Nodo<T>(dato);
		if (!nuevo) {
			return false;
		}
		if (head) {
			nuevo->next = head;
		}
		head = nuevo;
		return true;
	}

	bool eliminaFinal() {          //Complejidad: O(n)
		if (!head) {
			return false;
		}
		if (!head->next) {
			delete head;
			head = nullptr;
			return true;
		}
		Nodo<T>* actual = head;
		Nodo<T>* anterior = nullptr;
		while (actual->next) {
			anterior = actual;
			actual = actual->next;
		}
		anterior->next = nullptr;
		delete actual;
		actual = nullptr;
		return true;
	}

	int cuentaMenores(int dato) {                    //Complejidad: O(n)
		if (!head) {
			cout << "La lista esta vacia." << endl;
			return 0;
		}
		int cont = 0;
		Nodo<T>* actual = head;
		while (actual) {
			if (actual->dato < dato) {
				cont++;
			}
			actual = actual->next;
		}
		cout << "Elementos menores a " << dato << " son: " << cont << endl;
		return cont;
	}

};
