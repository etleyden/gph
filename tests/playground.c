/*
 * This file is where you can test the latest features
 * or be creative and try to break the library
 */
#include "graph.h"
#include <stdio.h>

int main() {
    Graph* g = gph_readFile("tests/simple.txt", 0);
    gph_printAdj(g); 
    gph_LLNode *path = gph_bfsToTarget(g, 0, 3);

    print_LLNodes(path); 
    destroy_LLNodes(path);
    gph_destroy(g);
}
