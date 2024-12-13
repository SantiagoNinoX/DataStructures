#pragma once
#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		arreglo = nullptr;
		tamano = 0;
	}
	~Base() {
		if (arreglo) {
			delete[] arreglo;
			arreglo = nullptr;
			tamano = 0;
		}
	}

	void iniciarArreglo();
	bool setSize(unsigned int nuevoSize);
	void imprimirArreglo();
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	bool mergeSortear();
	void quickSortear();
	int busquedaBinario(int valor);

private:
	unsigned int* arreglo;
	unsigned int tamano;
	bool mergeSort(unsigned int inicio, unsigned int fin);
	bool mezclar(unsigned int izquierda, unsigned int mitad, unsigned int derecha);
	int partition(int start, int end);
	void quickSort(int start, int end);
};
