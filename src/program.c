#include <stdio.h>
#include "../List/List.h"
#include "../Graph/Graph.h"
#include <Windows.h>


void main() {
	int max_nodes;
	srand(time(NULL));
	printf("Ingrese numero de nodos: ");
	scanf("%d", &max_nodes); //Nodos de 
	Graph *grafo = Graph_Create();
	for (int num = 0; num < max_nodes; num++){
		GVertex *ver;
		ver = GVertex_Create(Generic_NewInteger(num + 1)); //Genera vertices con valor de 1 como contenido
		Graph_AddVertex(grafo, ver);
	}

	for (int num = 1; num <= max_nodes; num++){
		GVertex *node1, *node2, *node3;
		int rnd1 = (rand() % max_nodes) + 1;
		int rnd2 = (rand() % max_nodes) + 1;
		int rnd3 = (rand() % max_nodes) + 1;
		while (rnd1 == num){
			rnd1 = (rand() % max_nodes) + 1;
		}
		while (rnd2 == num || rnd2 == rnd1){
			rnd2 = (rand() % max_nodes) + 1;
		}
		while (rnd3 == num || rnd3 == rnd2 || rnd3 == rnd1){
			rnd3 = (rand() % max_nodes) + 1;
		}
		node1 = Graph_SearchVertex(grafo, Generic_NewInteger(rnd1), integerCmp);
		node2 = Graph_SearchVertex(grafo, Generic_NewInteger(rnd2), integerCmp);
		node3 = Graph_SearchVertex(grafo, Generic_NewInteger(rnd3), integerCmp);
		Graph_LinkVertices(grafo, Graph_SearchVertex(grafo, Generic_NewInteger(num), integerCmp), node1, 1, NULL);
		Graph_LinkVertices(grafo, Graph_SearchVertex(grafo, Generic_NewInteger(num), integerCmp), node2, 1, NULL);
		Graph_LinkVertices(grafo, Graph_SearchVertex(grafo, Generic_NewInteger(num), integerCmp), node3, 1, NULL);
	}


}