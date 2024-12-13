#include <iostream>
#include "templateGrafos.h"
#include "TemplateListasDobles.h"
using namespace std;

int main()
{
	Grafo<unsigned int> dungeons;
	dungeons.cargarArchivo("dungeon.txt");
	dungeons.imprimirGrafo();
	dungeons.DFS_iterativo(0);
	dungeons.DFS_recursivo(0);
	//dungeons.BFS(0);
	//dungeons.printPath(24);
	dungeons.printPathBFS(0, 24);
	dungeons.avanzaRuta();

	return 0;
}

