/*
 * This file is where you can test the latest features
 * or be creative and try to break the library
 */
#include "graph.h"
#include <stdio.h>

int main() {
    Graph* g = gph_readFile("tests/ex_graphs/dijkstra.txt", GPH_UNDIRECTED, GPH_WEIGHTED);

    gph_printAdj(g); 
    int *shortest_paths = gph_dijkstra(g, 0);
    int gph_size = g->num_vertices;
    int i;
    for(i = 0; i < gph_size; i++) {
        printf("%d: %d\n", i, shortest_paths[i]);
    }
    
    free(shortest_paths);
    gph_destroy(g);
}
