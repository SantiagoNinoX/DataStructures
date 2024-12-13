#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TemplateListasDobles.h"
#include "TemplateStack.h"
#include "TemplateQueue.h"

using namespace std;

template <typename T>
class Vertice {
public:
	T dato;
	ListaDoble<unsigned int> edges;
	bool visited;
	Vertice() : dato(T()), visited(false) {}  // Inicializar dato con su valor predeterminado

};

template <typename T>
class Grafo {
public:
	Grafo() { vertices = nullptr; size = 0, previous = nullptr; }

	~Grafo() { borrarGrafo(); }

	bool crearGrafo(unsigned int nSize) {
		if (nSize == 0 || vertices) {
			return false;
		}
		vertices = new(nothrow) Vertice<T>[nSize];
		if (!vertices) {
			return false;
		}
		size = nSize;
		previous = new(nothrow) unsigned int[nSize];
		if (!previous) {
			return false;
		}
		for (unsigned int o = 0; o < nSize; o++) {
			previous[o] = UINT_MAX;
		}
		return true;
	}

	bool setVertex(unsigned int vertex, T data) {
		if (!size || vertex >= size) {
			return false;
		}
		vertices[vertex].dato = data;
		return true;
	}

	bool insertarArista(unsigned int fuente, unsigned int destino) {
		if (!vertices) {
			return false;
		}
		if (fuente >= size || destino >= size) {
			return false;
		}
		if (vertices[fuente].edges.busquedaDoble(destino)) {
			return false;
		}
		if (!vertices[fuente].edges.insertaFinalDoble(destino)) {
			return false;
		}
		return true;
	}

	bool eliminarArista(unsigned int fuente, unsigned int destino) {
		if (!vertices) {
			return false;
		}
		if (fuente >= size || destino >= size) {
			return false;
		}
		if (!vertices[fuente].edges.busquedaDoble(destino)) {
			return false;
		}
		if (vertices[fuente].edges.deleteElementoDoble(destino)) {
			return true;
		}
		return false;
	}

	void borrarGrafo() {
		if (!size) {
			return;
		}
		if (vertices) {
			delete[] vertices;
			vertices = nullptr;
			size = 0;
		}
		if (previous) {
			delete[] previous;
			previous = nullptr;
		}
	}

	void imprimirGrafo() {
		for (unsigned int i = 0; i < size; i++) {
			cout << i << ": ";
			vertices[i].edges.imprimeListaDoble();
		}
		cout << endl;
	}

	bool cargarArchivo(const string& filename) {
		ifstream        file(filename);
		string          line;
		unsigned int vertex = 0, nSize = 0;

		//file.open(filename, ios::in);
		if (!file.is_open()) {
			cerr << "Error al abrir el archivo: " << filename << endl;
			return false;
		}
		if (!getline(file, line)) {
			cout << "Sin header" << endl;
			file.close();
			return false;
		}
		if (line != "Grafo") {
			file.close();
			return false;
		}
		if (!getline(file, line)) {  //Cantidad de vertices
			cout << "Sin tamaño de grafo" << endl;
			file.close();
			return false;
		}
		if (!isValidNumeric(line)) {
			cout << "Tamaño de grafo no es numerico" << endl;
			file.close();
			return false;
		}
		nSize = stoi(line);
		if (nSize <= 0) {
			cout << "Tamaño de grafo incorrecto" << endl;
			file.close();
			return false;
		}
		borrarGrafo();   //Borrar grafo actual
		if (!crearGrafo(nSize)) {   //Crear nuevos vertices, nuevo grafo
			cout << "No se pudo crear el grafo" << endl;
			file.close();
			return false;
		}
		for (vertex = 0; vertex < size; vertex++) {
			if (!getline(file, line)) {  //Aristas
				cout << "Sin aristas" << endl;
				file.close();
				return false;
			}
			if (line.length()) {    //Si hay contenido en el vertice
				stringstream ss(line);
				string cell;
				while (getline(ss, cell, ' ')) {
					int destino = 0;
					if (!isValidNumeric(cell)) {
						file.close();
						return false;
					}
					destino = stoi(cell);
					if (!insertarArista(vertex, destino)) {
						file.close();
						return false;
					}
				}
			}
		}
		file.close();
		return true;
	}

	bool guardarArchivo(const string& filename) {
		ofstream file;
		if (!size) {
			return false;
		}
		file.open(filename, ios::out);
		if (!file.is_open()) {
			cerr << "Error al guardar el archivo: " << filename << endl;
			return false;
		}
		file << "Grafo" << endl;    //Encabezado
		file << size << endl;       //Cantidad de vertices
		for (unsigned int i = 0; i < size; i++) {
			ListaDoble<unsigned int>::iterator j(nullptr);
			for (j = vertices[i].edges.begin(); j != vertices[i].edges.end(); ++j) {
				file << *j << " ";
			}
			file << endl;
		}
		file.close();
		return true;
	}

	void DFS_recursivo(unsigned int vertex) {
		vertices[vertex].visited = true;
		cout << vertex << " ";
		ListaDoble<unsigned int>::iterator i(nullptr);
		for (i = vertices[vertex].edges.begin(); i != vertices[vertex].edges.end(); ++i) {
			if (!vertices[*i].visited) {
				DFS_recursivo(*i);
			}
		}
		//cout << vertex << " ";

	}

	bool DFS_iterativo(unsigned int vertex) {
		if (!size || vertex >= size) {
			return false;
		}
		inicializarVisited();
		Stack<unsigned int> pila;
		pila.push(vertex);
		cout << "DFS (" << vertex << "): ";
		while (!pila.isEmpty()) {
			unsigned int verticeactual = *pila.getTop();
			pila.pop();
			if (!vertices[verticeactual].visited) {
				vertices[verticeactual].visited = true;
				cout << verticeactual << " ";
				ListaDoble<unsigned int>::iterator it = vertices[verticeactual].edges.begin();
				while (it != vertices[verticeactual].edges.end()) {
					if (!vertices[*it].visited) {
						pila.push(*it);
					}
					++it;
				}
			}
		}
		cout << endl;
		return true;
	}

	bool BFS(unsigned int vertexInicio) {
		Queue<unsigned int> cola;
		if (!size || vertexInicio >= size) {
			return false;
		}
		inicializarVisited();
		//cout << "BFS (" << vertexInicio << "): ";
		if (!cola.enqueue(vertexInicio)) {
			return false;
		}
		vertices[vertexInicio].visited = true;   //Optimizacion
		while (!cola.isEmpty()) {
			unsigned int verticeAct = *cola.peek_getFront();
			//cout << verticeAct << " ";
			cola.dequeue();
			for (auto arista : vertices[verticeAct].edges) {
				if (!vertices[arista].visited) {
					if (!cola.enqueue(arista)) {
						return false;
					}
					vertices[arista].visited = true;
					previous[arista] = verticeAct;
				}
			}
		}
		cout << endl;
		return true;
	}

	bool printPathBFS(unsigned int vertexInicial, unsigned int vertexFinal) {
		if (!BFS(vertexInicial)) {
			return false;
		}
		unsigned int act = vertexFinal;
		while (act != UINT_MAX) {
			if (!path.insertaInicioDoble(act)) {
				return false;
			}
			act = previous[act];
		}
		path.imprimeListaDoble();
		return true;
	}

	void printPath(unsigned int vertexFinal) {
		unsigned int act = vertexFinal;
		while (act != UINT_MAX) {
			if (!path.insertaInicioDoble(act)) {
				return;
			}
			act = previous[act];
		}
		path.imprimeListaDoble();
	}

	unsigned int* avanzaRuta() {
		ListaDoble<unsigned int>::iterator q = path.begin();
		if(q != path.end()){
			return *(++q);
		}
	}


	unsigned int getSizeGrafo() {
		return size;
	}

private:
	Vertice<T>* vertices;
	unsigned int size;
	unsigned int* previous;
	ListaDoble<unsigned int> path;

	bool isValidNumeric(const string& str) {
		for (char c : str) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}

	void inicializarVisited() {
		for (unsigned int i = 0; i < size; i++) {
			vertices[i].visited = false;
		}
	}
};
