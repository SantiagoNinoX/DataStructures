#include <iostream>
#include "TemplateListasDobles.h"
#include "TemplateListasSimples.h"
using namespace std;
#define MAX 5

int main(){
	// Lista Sencilla de INTS.
	ListaLigada<int> sencillaInt;
	for (int i = 0; i < MAX; i++) {
		if (!sencillaInt.insertaFinal(i)) {
			cout << "Sin memoria." << endl;
			return 0;
		}
	}
	sencillaInt.imprimeLista();
	sencillaInt.deleteElemento(1);
	sencillaInt.imprimeLista();
	sencillaInt.deleteElemento(5);
	sencillaInt.imprimeLista();
	sencillaInt.insertaAlInicio(5);
	sencillaInt.imprimeLista();
	sencillaInt.insertaAlInicio(0);
	sencillaInt.imprimeLista();
	sencillaInt.borrarInicial();
	sencillaInt.imprimeLista();
	sencillaInt.insertaFinal(20);
	sencillaInt.imprimeLista();
	sencillaInt.borrarInicial();
	sencillaInt.imprimeLista();
	sencillaInt.borrarFinal();
	sencillaInt.imprimeLista();
	sencillaInt.insertaAlInicio(50);
	sencillaInt.imprimeLista();
	sencillaInt.borrarFinal();
	sencillaInt.imprimeLista();
	sencillaInt.borrarInicial();
	sencillaInt.imprimeLista();
	sencillaInt.insertaEnOrden(1);
	sencillaInt.imprimeLista();
	sencillaInt.insertaEnOrden(0);
	sencillaInt.imprimeLista();
	sencillaInt.insertaEnOrden(7);
	sencillaInt.imprimeLista();
	sencillaInt.borrarInicial();
	sencillaInt.imprimeLista();
	sencillaInt.busqueda(0);
	sencillaInt.busqueda(2);
	sencillaInt.busqueda(100);
	sencillaInt.busqueda(7);
	sencillaInt.deleteElemento(7);
	sencillaInt.imprimeLista();
	sencillaInt.busqueda(7);


	//Lista Ligada de STRINGS.
	ListaLigada<string> sencillaString;
	for (int i = 0; i < 5; i++) {
		if (!sencillaString.insertaFinal("progra")){
			cout << "No hubo memoria" << endl;
			return 0;
		}
	}
	sencillaString.imprimeLista();


	//Lista Doble de INTS.
    ListaDoble<int> pruebaInt;
	for (int num : {1, 4, 6, 7}) {
		if (!pruebaInt.insertaFinalDoble(num)) {
			cout << "No hubo memoria" << endl;
			return 0;
		}
	}
	pruebaInt.imprimeListaDoble();
	pruebaInt.imprimeListaAlRevesDoble();
	pruebaInt.insertaInicioDoble(10);
	pruebaInt.imprimeListaDoble();
	pruebaInt.deleteElementoDoble(4);
	pruebaInt.imprimeListaDoble();
	pruebaInt.borrarInicialDoble();
	pruebaInt.imprimeListaDoble();
	pruebaInt.insertaFinalDoble(10);
	pruebaInt.imprimeListaDoble();
	pruebaInt.borrarFinalDoble();
	pruebaInt.imprimeListaDoble();
	pruebaInt.insertaEnOrdenDoble(5);
	pruebaInt.imprimeListaDoble();
	pruebaInt.busquedaDoble(5);
	pruebaInt.deleteElementoDoble(5);
	pruebaInt.imprimeListaDoble();
	pruebaInt.busquedaDoble(5);
	pruebaInt.insertaEnOrdenDoble(4);
	pruebaInt.imprimeListaDoble();
	pruebaInt.busquedaDoble(4);
	pruebaInt.busquedaDoble(1);
	pruebaInt.busquedaDoble(10);


	//LISTA DOBLE DE STRINGS.
	ListaDoble<string> pruebaString;
	for (int i = 0; i < 5; i++) {
		if(!pruebaString.insertaFinalDoble("perro")){
			cout << "No hubo memoria" << endl;
			return 0;
		}
	}
	pruebaString.imprimeListaDoble();
	for (int i = 0; i < 5; i++) {
		if (!pruebaString.insertaFinalDoble("gato")){
			cout << "No hubo memoria" << endl;
			return 0;
		}
	}
	pruebaString.imprimeListaAlRevesDoble();
	pruebaString.insertaInicioDoble("raton");
	pruebaString.imprimeListaDoble();
	pruebaString.insertaFinalDoble("z");
	pruebaString.imprimeListaDoble();
	pruebaString.insertaEnOrdenDoble("ximena");
	pruebaString.imprimeListaDoble();
	pruebaString.deleteElementoDoble("gato");
	pruebaString.imprimeListaDoble();
	pruebaString.borrarInicialDoble();
	pruebaString.imprimeListaDoble();
	pruebaString.borrarFinalDoble();
	pruebaString.imprimeListaDoble();
	pruebaString.busquedaDoble("raton");
	pruebaString.busquedaDoble("ximena");


	//MENU
	ListaDoble<int> prueba2Int;
	for (int num : {1, 4, 6, 7}) {
		if (!prueba2Int.insertaFinalDoble(num)) {
			cout << "No hubo memoria" << endl;
			return 0;
		}
	}
	int opcion = -1;
	while (opcion != 0) {
		cout << "Elige una opcion para LISTAS DOBLEMENTE LIGADAS: " << endl;
		cout << "1) Insertar dato al inicio. " << endl;
		cout << "2) Eliminar HEAD." << endl;
		cout << "3) Eliminar TAIL." << endl;
		cout << "4) Eliminar dato por busqueda." << endl;
		cout << "5) Eliminar lista." << endl;
		cout << "0) Salir del programa." << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			int dato_a_insertar;
			cout << "Has seleccionado 1) Insertar dato al inicio." << endl;
			cout << "La lista es: " << endl;
			prueba2Int.imprimeListaDoble();
			cout << "Inserta el dato a agregar: " << endl;
			cin >> dato_a_insertar;
			prueba2Int.insertaInicioDoble(dato_a_insertar);
			cout << "El resultado es: " << endl;
			prueba2Int.imprimeListaDoble();
			break;

		case 2:
			cout << "Has seleccionado 2) Eliminar HEAD." << endl;
			cout << "La lista es: " << endl;
			prueba2Int.imprimeListaDoble();
			prueba2Int.borrarInicialDoble();
			cout << "El resultado es: " << endl;
			prueba2Int.imprimeListaDoble();
			break;
		
		case 3:
			cout << "Has seleccionado 3) Eliminar TAIL." << endl;
			cout << "La lista es: " << endl;
			prueba2Int.imprimeListaDoble();
			prueba2Int.borrarFinalDoble();
			cout << "El resultado es: " << endl;
			prueba2Int.imprimeListaDoble();
			break;

		case 4:
			int dato_a_eliminar;
			cout << "Has seleccionado 4) Eliminar dato por busqueda." << endl;
			cout << "La lista es: " << endl;
			prueba2Int.imprimeListaDoble();
			cout << "Ingresa el dato a eliminar: " << endl;
			cin >> dato_a_eliminar;
			prueba2Int.deleteElementoDoble(dato_a_eliminar);
			cout << "El resultado es: " << endl;
			prueba2Int.imprimeListaDoble();
			break;

		case 5:
			cout << "Has seleccionado 5) Eliminar lista." << endl;
			cout << "La lista es: " << endl;
			prueba2Int.imprimeListaDoble();
			prueba2Int.deleteListaDoble();
			cout << "El resultado es: " << endl;
			prueba2Int.imprimeListaDoble();
			break;

		case 0:
			cout << "Has salido." << endl;
			return 0;

		default:
			cout << "Opcion incorrecta. Ingresa un numero del 1 al 5." << endl;
		}
	}
	return 0;
}
