#pragma once
#include <iostream>
#include "TemplateQueue.h"
using namespace std;

template <typename T>
class NodoAVL {
public:
	T dato;
	int altura;
	NodoAVL<T>* left;
	NodoAVL<T>* right;
	NodoAVL(T dato) : dato(dato), altura(0), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVL {
private:
	NodoAVL<T>* root;

	T* buscarRecursivo(NodoAVL<T>* actual, T dato) {
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

	bool insertaRecursivo(NodoAVL<T>*& nodo, T dato) {
		if (!nodo) {
			nodo = new(nothrow) NodoAVL<T>(dato);
			if (!nodo) {
				return false;
			}
			nodo->altura = 0;
			return true;
		}
		if (dato < nodo->dato) {
			if (insertaRecursivo(nodo->left, dato)) {
				calculaAltura(nodo);
				balancea(nodo);
				return true;
			}
			else {
				return false;
			}
		}
		else if (dato > nodo->dato) {
			if (insertaRecursivo(nodo->right, dato)) {
				calculaAltura(nodo);
				balancea(nodo);
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	void recorridoInOrder(NodoAVL<T>* act) {   //IZQ -> RAIZ -> DER
		if (!act) {
			return;
		}
		recorridoInOrder(act->left);
		cout << act->dato << " ";
		recorridoInOrder(act->right);
	}

	void recorridoPreOrder(NodoAVL<T>* act) {   //RAIZ -> IZQ -> DER
		if (!act) {
			return;
		}
		cout << act->dato << " ";
		recorridoPreOrder(act->left);
		recorridoPreOrder(act->right);
	}

	void recorridoPostOrder(NodoAVL<T>* act) {    //IZQ -> DER -> RAIZ
		if (!act) {
			return;
		}
		recorridoPostOrder(act->left);
		recorridoPostOrder(act->right);
		cout << act->dato << " ";
	}

	NodoAVL<T>* buscaMinRight(NodoAVL<T>* nodo) {
		NodoAVL<T>* minRight = nullptr;
		NodoAVL<T>* parent = nullptr;
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

	bool eliminaRecursivo(NodoAVL<T>*& act, T dato) {
		if (!act) {
			return false;
		}
		if (dato < act->dato) {
			return eliminaRecursivo(act->left, dato);
		}
		else if (dato > act->dato) {
			return eliminaRecursivo(act->right, dato);
		}
		else {
			NodoAVL<T>* aBorrar = nullptr;
			aBorrar = act;
			if (!act->left) {
				act = act->right;
			}
			else if (!act->right) {
				act = act->left;
			}
			else {
				aBorrar = buscaMinRight(act);
			}
			delete aBorrar;
		}
		if (act) {
			calculaAltura(act);
			balancea(act);
		}
		return true;
	}

	int getAltura(NodoAVL<T>* nodo) {
		if (!nodo) {
			return -1;
		}
		return nodo->altura;
	}

	int revisaBalance(NodoAVL<T>* nodo) {
		if (!nodo) {
			return -1;
		}
		return (getAltura(nodo->left) - getAltura(nodo->right));
	}

	void calculaAltura(NodoAVL<T>* nodo) {
		if (nodo) {
			nodo->altura = 1 + max(getAltura(nodo->left), getAltura(nodo->right));
		}
	}

	NodoAVL<T>* rotacionDerecha(NodoAVL<T>* nodo) {
		NodoAVL<T>* hijoizq = nodo->left;
		NodoAVL<T>* nietoizqder = hijoizq->right;
		hijoizq->right = nodo;
		nodo->left = nietoizqder;
		calculaAltura(nodo);
		calculaAltura(hijoizq);
		return hijoizq;
	}

	NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* nodo) {
		NodoAVL<T>* hijoder = nodo->right;
		NodoAVL<T>* nietoderizq = hijoder->left;
		hijoder->left = nodo;
		nodo->right = nietoderizq;
		calculaAltura(nodo);
		calculaAltura(hijoder);
		return hijoder;
	}

	NodoAVL<T>* rotacionDobleDerecha(NodoAVL<T>* nodo) {
		nodo->left = rotacionIzquierda(nodo->left);
		return rotacionDerecha(nodo);
	}

	NodoAVL<T>* rotacionDobleIzquierda(NodoAVL<T>* nodo) {
		nodo->right = rotacionDerecha(nodo->right);
		return rotacionIzquierda(nodo);
	}

	void balancea(NodoAVL<T>*& nodo) {
		if (revisaBalance(nodo) > 1) {
			if (revisaBalance(nodo->left) >= 0) {
				nodo = rotacionDerecha(nodo);
			}
			else {
				nodo = rotacionDobleDerecha(nodo);
			}
		}
		if (revisaBalance(nodo) < -1) {
			if (revisaBalance(nodo->right) <= 0) {
				nodo = rotacionIzquierda(nodo);
			}
			else {
				nodo = rotacionDobleIzquierda(nodo);
			}
		}
	}

	void imprimirAlturasRecursivo(NodoAVL<T>* nodo, int nivel) {
		if (!nodo) {
			return;
		}
		imprimirAlturasRecursivo(nodo->right, nivel + 1);
		for (int i = 0; i < nivel; i++) {
			cout << "    ";
		}
		cout << nodo->dato << "(" << nodo->altura << ")" << endl;
		imprimirAlturasRecursivo(nodo->left, nivel + 1);
	}

public:
	AVL() {
		root = nullptr;
	}

	~AVL() {
		borrarArbol();
	}

	bool borrarArbol() {
		return deleteAVL(&root);
	}

	bool deleteAVL(NodoAVL<T>** nodo) {
		if (*nodo) {
			deleteAVL(&(*nodo)->left);
			deleteAVL(&(*nodo)->right);
			delete* nodo;
			*nodo = nullptr;
			return true;
		}
	}

	T* buscar(T dato) {
		return buscarRecursivo(root, dato);
	}

	bool inserta(T dato) {
		return insertaRecursivo(root, dato);
	}

	void printInOrder() {
		recorridoInOrder(root);
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

	bool eliminarNodo(T dato) {
		if (eliminaRecursivo(root, dato)) {
			if (!root) {
				return false;
			}
			balancea(root->left);
			balancea(root->right);
			calculaAltura(root);
			balancea(root);
			return true;
		}
		else {
			return false;
		}
	}

	void printBFS() {
		Queue<NodoAVL<T>*> colaImpresion;
		if (!root) {
			return;
		}
		colaImpresion.enqueue(root);
		while (!colaImpresion.isEmpty()) {
			NodoAVL<T>** tmp = colaImpresion.peek_getFront();
			NodoAVL<T>* act = *tmp;
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

	void imprimirPorAlturas() {
		return (imprimirAlturasRecursivo(root, 0));
	}

};