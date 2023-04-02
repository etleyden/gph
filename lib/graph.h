#include "gph_util.h"
#include <stdlib.h>
#ifndef LIBGPH_H_
#define LIBGPH_H_
#define MAX_BUFFER 255
typedef struct {
    int **adj;
    int num_vertices;
    int isDirected;
} Graph;
typedef struct Vertex {
    int value;
    struct Vertex* parent;
} Vertex;

/* 
 * Creates a Graph instance and returns its pointer.
 * Default behavior: Graph is undirected
 * Args: int size: the number of vertices in the graph
 */
Graph* gph_buildNew(int size);

/*
 * Reads a plain text file and creates a Graph instance out of it.
 * TODO: Support weighted graphs, and alternative index numbering
 * Format of a valid unweighted graph file:
 * 1. First line is an integer of how many vertices are in the grah
 * 2. All following lines is an adjacency list of the edges in the graph. 
 * Example (3 vertices, 4 edges: (0, 1), (0, 2), (1, 0), (2, 0):
 * 3
 * 0 1 2
 * 1 0
 * 2 0
 * Format of a valid weighted graph file:
 * 1. First line is an integer of how many vertices are in the graph
 * 2. Following lines are [u, v, w]
 * Example (3 vertices, 4 edges, first line is an edge from v0 to v1 of w5)
 * 3
 * 0 1 5
 * 0 2 2
 * 1 2 3
 * 2 0 1
 * Args: char* filename, isDirected (0 or 1), isWeighted (0 or 1)
 */
Graph* gph_readFile(char*, int, int);

/*
 * Frees a Graph instance into memory
 */
void gph_destroy(Graph *g);

/*
 * Add a weighted edge to a graph
 * Args: *Graph graph, int u, int v, int weight
 */
void gph_addEdge(Graph*, int, int, int);

/*
 * Prints the adjacency matrix of the graph
 */
void gph_printAdj(Graph*);

/*
 * Performs BFS and returns a Vertex with parent pointers from target to source
 * Args: Graph, int source, int target
 */
gph_LLNode* gph_bfsToTarget(Graph*, int, int);

/* 
 * Get a linked list of the neighbors of a particular node
 */
gph_Queue* gph_getNeighbors(Graph*, int);
#endif


