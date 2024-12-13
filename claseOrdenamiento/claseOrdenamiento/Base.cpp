#include <iostream>
#include <ctime>
#include "Base.h"

void Base::iniciarArreglo() {
	srand(time(0));
	for (unsigned int i = 0; i < tamano; i++) {
		arreglo[i] = rand() % 100;
	}
}

bool Base::setSize(unsigned int nuevoSize) {
	if (nuevoSize == 0) {
		return false;
	}
	if (arreglo) {
		delete[] arreglo;
		arreglo = nullptr;
		tamano = 0;
	}
	arreglo = new(nothrow) unsigned int[nuevoSize];
	if (!arreglo) {
		return false;
	}
	//this->tamano = nuevoSize;
	tamano = nuevoSize;
	return true;
}

void Base::imprimirArreglo() {
	for (unsigned int i = 0; i < tamano; i++) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
}

void Base::bubbleSort() {
	for (unsigned int j = 0; j < tamano-1; j++) {
		for (unsigned int i = 0; i < tamano-1-j; i++) {
			if (arreglo[i] > arreglo[i + 1]) {
				int temp = arreglo[i];
				arreglo[i] = arreglo[i + 1];
				arreglo[i + 1] = temp;
			}
		}
	}
}

void Base::insertionSort() {
	for (unsigned int i = 1; i < tamano; i++) {
		unsigned int temp = arreglo[i];
		long int j = i - 1;       
		while (j >= 0 && temp < arreglo[j]) {
			arreglo[j+1] = arreglo[j];
			j = j - 1;
		}
		arreglo[j+1] = temp;
	}
}

void Base::selectionSort() {
	for (unsigned int i = 0; i < tamano; i++) {
		unsigned int posicionMini = i;
		for (unsigned int j = i + 1; j < tamano; j++) {
			if (arreglo[j] < arreglo[posicionMini]) {
				posicionMini = j;
			}
		}
		if (posicionMini != i) {
			unsigned int act = arreglo[i];
			arreglo[i] = arreglo[posicionMini];
			arreglo[posicionMini] = act;
		}
	}
}

bool Base::mergeSortear() {
	return(mergeSort(0, tamano - 1));
}

bool Base::mergeSort(unsigned int inicio, unsigned int fin) {
	unsigned int mitad = 0;
	if (inicio >= fin) {
		return true;
	}
	mitad = inicio + (fin - inicio) / 2;
	
	mergeSort(inicio, mitad);
	mergeSort(mitad + 1, fin);
	return(mezclar(inicio, mitad, fin));
}

bool Base::mezclar(unsigned int izquierda, unsigned int mitad, unsigned int derecha) {
	unsigned int tamanoIzq, tamanoDer;
	tamanoIzq = mitad - izquierda + 1;
	tamanoDer = derecha - mitad;

	unsigned int* arrIzq = nullptr;
	unsigned int* arrDer = nullptr;

	arrIzq = new(nothrow) unsigned int[tamanoIzq];
	if (!arrIzq) {
		cout << "No hay memoria para los sub-arreglos" << endl;
		return false;
	}

	arrDer = new(nothrow) unsigned int[tamanoDer];
	if (!arrDer) {
		cout << "No hay memoria para los sub-arreglos" << endl;
		delete[] arrIzq;
		return false;
	}

	for (unsigned int i = 0; i < tamanoIzq; i++) {
		arrIzq[i] = arreglo[izquierda + i];
	}
	for (unsigned int j = 0; j < tamanoDer; j++) {
		arrDer[j] = arreglo[mitad + 1 + j];
	}
	unsigned int i = 0, j = 0, k = izquierda;

	while (i < tamanoIzq && j < tamanoDer) {
		if (arrIzq[i] <= arrDer[j]) {
			arreglo[k] = arrIzq[i];
			i++;
		}
		else {
			arreglo[k] = arrDer[j];
			j++;
		}
		k++;
	}
	while (i < tamanoIzq) {
		arreglo[k] = arrIzq[i];
		i++;
		k++;
	}
	while (j < tamanoDer) {
		arreglo[k] = arrDer[j];
		j++;
		k++;
	}
	if (arrIzq) {
		delete[] arrIzq;
		arrIzq = nullptr;
	}
	if (arrDer) {
		delete[] arrDer;
		arrDer = nullptr;
	}
	return true;
}

void Base::quickSortear() {
	if (tamano > 0) {
		quickSort(0, tamano - 1);
	}
}

void Base::quickSort(int start, int end) {
	if (start >= end) {
		return;
	}
	int pivotIndex = partition(start, end);
	quickSort(start, pivotIndex - 1);
	quickSort(pivotIndex + 1, end);
}

int Base::partition(int inicio, int fin) {
	int valorPivote = arreglo[fin];
	int leftWall = inicio - 1;
	int tmp;
	for (int i = inicio; i < fin; i++) {
		if (arreglo[i] < valorPivote) {
			leftWall++;
			tmp = arreglo[leftWall];
			arreglo[leftWall] = arreglo[i];
			arreglo[i] = tmp;
		}
	}
	leftWall++;
	tmp = arreglo[leftWall];
	arreglo[leftWall] = arreglo[fin];
	arreglo[fin] = tmp;
	return leftWall;
}

int Base::busquedaBinario(int valor) {
	int inicio = 0; 
	int final = tamano - 1;    
	int medio;
	while (inicio <= final) {    
		medio = (inicio + final) / 2;
		if (valor == arreglo[medio]) {      
			return medio;
		}
		else {
			if (valor < arreglo[medio]) {    
				final = medio - 1;
			}
			else {
				inicio = medio + 1;
			}
		}
	}
	return -1;
}