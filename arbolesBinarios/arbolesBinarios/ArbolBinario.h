#pragma once
#include <iostream>
#include "TemplateQueue.h"
using namespace std;

class NodoArbol {
public:
	int dato;
	NodoArbol* left;
	NodoArbol* right;
	NodoArbol(int dato): dato(dato), left (nullptr), right (nullptr) {}
};

class ArbolBinario {
private:
	NodoArbol* root;

	int* buscarRecursivo(NodoArbol* actual, int dato) {
		if (!actual) {
			return nullptr;
		}
		if (dato < actual->dato) {
			return buscarRecursivo(actual->left, dato);
		}
		else if (dato > actual->dato) {
			return buscarRecursivo(actual->right, dato);
		}
		return &actual->dato;
	}

	bool insertaRecursivo(NodoArbol*& nodo, int dato) {
		if (!nodo) {
			nodo = new(nothrow) NodoArbol(dato);
			if (!nodo) {
				return false;
			}
			return true;
		}
		if (dato < nodo->dato) {
			return insertaRecursivo(nodo->left, dato);
		}
		else if (dato > nodo->dato) {
			return insertaRecursivo(nodo->right, dato);
		}
		return false;
	}

	void recorridoInOrder(NodoArbol* act) {   //IZQ -> RAIZ -> DER
		if (!act) {
			return;
		}
		recorridoInOrder(act->left);
		cout << act->dato << " ";
		recorridoInOrder(act->right);
	}

	void recorridoPreOrder(NodoArbol* act) {   //RAIZ -> IZQ -> DER
		if (!act) {
			return;
		}
		cout << act->dato << " ";
		recorridoPreOrder(act->left);
		recorridoPreOrder(act->right);
	}

	void recorridoPostOrder(NodoArbol* act) {    //IZQ -> DER -> RAIZ
		if (!act) {
			return;
		}
		recorridoPostOrder(act->left);
		recorridoPostOrder(act->right);
		cout << act->dato << " ";
	}

	NodoArbol* buscaMinRight(NodoArbol* nodo) {
		NodoArbol* minRight = nullptr;
		NodoArbol* parent = nullptr;
		parent = nodo;
		minRight = nodo->right;
		while (minRight->left) {
			parent = minRight;
			minRight = minRight->left;
		}
		nodo->dato = minRight->dato;
		if (parent == nodo) {
			parent->right = minRight->right;
		}
		else {
			parent->left = minRight->right;
		}
		return minRight;
	}

	bool eliminaRecursivo(NodoArbol*& act, int dato) {   
		if (!act) {
			return false;
		}
		if (dato < act->dato) {
			return eliminaRecursivo(act->left, dato);
		}
		if (dato > act->dato) {
			return eliminaRecursivo(act->right, dato);
		}
		if (act->left && act->right) {
			NodoArbol* sustituto = buscaMinRight(act);
			delete sustituto;
			sustituto = nullptr;
			return true;
		}
		else if (!act->left && act->right) {
			NodoArbol* temp = act;
			act = act->right;
			delete temp;
			temp = nullptr;
			return true;
		}
		else if (!act->right && act->left) {
			NodoArbol* temp = act;
			act = act->left;
			delete temp;
			temp = nullptr;
			return true;
		}
		delete act;
		act = nullptr;
		return true;
	}

public:
	ArbolBinario() {
		root = nullptr;
	}

	~ArbolBinario() {
		borrarArbol();
	}

	bool borrarArbol() {
		return deleteBST(&root);
	}

	bool deleteBST(NodoArbol** nodo) {
		if (*nodo) {
			deleteBST(&(*nodo)->left);
			deleteBST(&(*nodo)->right);
			delete* nodo;
			*nodo = nullptr;
			return true;
		}
	}

	int* buscar(int dato) {
		return buscarRecursivo(root, dato);
	}

	bool inserta(int dato) {
		return insertaRecursivo(root, dato);
	}

	void printInOrder() {
		cout << endl;
		return recorridoInOrder(root);
		cout << endl;
	}

	void printPreOrder() {
		cout << endl;
		return recorridoPreOrder(root);
		cout << endl;
	}

	void printPostOrder() {
		cout << endl;
		return recorridoPostOrder(root);
		cout << endl;
	}

	bool eliminarNodo(int dato) {
		return eliminaRecursivo(root, dato);
	}

	void printBFS() {
		Queue<NodoArbol*> colaImpresion;
		if (!root) {
			return;
		}
		colaImpresion.enqueue(root);
		while (!colaImpresion.isEmpty()) {
			NodoArbol** tmp = colaImpresion.peek_getFront();
			NodoArbol* act = *tmp;
			colaImpresion.dequeue();
			cout << act->dato << " ";
			if (act->left) {
				colaImpresion.enqueue(act->left);
			}
			if (act->right) {
				colaImpresion.enqueue(act->right);
			}
			
		}
		cout << endl;
	}

};
