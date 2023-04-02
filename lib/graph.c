#include "graph.h"
#include <stdio.h>

Graph* gph_build(int size) {
    int size_adj = size * size * sizeof(int);
    Graph *gph = (Graph*) malloc(sizeof(Graph) + size_adj);
    gph->adj = (int**) malloc(size * sizeof(int*));
    int i = 0;
    for(; i < size; i++) {
        gph->adj[i] = (int*) malloc(size * sizeof(int));
    }
    //Initialize graph to 0 values (TODO: implement a better NULL solution).
    for(i = 0; i < size; i++) {
        int j = 0;
        for(; j < size; j++) {
            gph->adj[i][j] = 0;
        }
    }
    gph->num_vertices = size;
    gph->isDirected = 0;
    return gph;
}

//Notes: 
// * Assumes Graph is unweighted
// * Vertex numbering starts from 0
// * An edge weight of 0 means no edge
Graph* gph_readFile(char* filename, int isDirected, int isWeighted) {
    //Check that the file is valid
    FILE *in;
    in = fopen(filename, "r");
    if(in == NULL) {
        printf("Could not open %s\n", filename);
        return NULL;
    }

    //Read the number of vertices in the graph
    int num_vertices; 
    fscanf(in, "%d\n", &num_vertices);
    Graph* g = gph_build(num_vertices);
    g->isDirected = isDirected;

    char buffer[MAX_BUFFER];
    if(isWeighted == 0) {
        //Loads each line into the buffer
        while(fgets(buffer, MAX_BUFFER, in) != NULL) {
            //Reads the line from left to right matching the pattern, moving forward by the offset
            int next_int, source, offset;
            char* data = buffer;
            while(sscanf(data, " %d%n", &next_int, &offset) > 0) {
                if(offset == 1) { source = next_int; } //First element in the line will have an offest of 1 in a space separated file
                else { gph_addEdge(g, source, next_int, 1); } //Everything else will be the destination of the edge
                data += offset;
            }
        }
    } else {
        while(fgets(buffer, MAX_BUFFER, in) != NULL) {
            int v, u, w, offset;
            char* data = buffer;
            sscanf(data, " %d%n", &v, &offset);
            data += offset;
            sscanf(data, " %d%n", &u, &offset);
            data += offset;
            sscanf(data, " %d%n", &w, &offset);
            gph_addEdge(g, v, u, w);
        }
    }
    fclose(in);

    return g;
}

void gph_destroy(Graph *g) {
    int i = 0; 
    for(; i < g->num_vertices; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

void gph_addEdge(Graph *g, int u, int v, int w) {
    g->adj[u][v] = w;
    if(g->isDirected == 0) {
        g->adj[v][u] = w;
    }
}

void gph_printAdj(Graph *g) {
    int i = 0;
    int size = g->num_vertices;

    //header
    printf("  "); //empty first cell
    for(; i < size; i++) {
        printf(" %d", i);
    }
    printf("\n");
    //Each row
    for(i = 0; i < size; i++) {
        int j = 0;
        printf("%d ", i);
        for(; j < size; j++) {
            printf(" %d", g->adj[i][j]);
        }
        printf("\n");
    }
}

gph_LLNode* gph_bfsToTarget(Graph *g, int s, int t) {
    gph_Queue *q = build_Queue();
    gph_qAppendInt(q, s);
    int gph_size = g->num_vertices;
    int path[gph_size];
    int visited[gph_size];
    int i;
    for(i = 0; i < gph_size; i++) {
        path[i] = -1;
        visited[i] = 0;
    }
    visited[s] = 1;

    while(q->size > 0) {
        //Visit each node
        gph_LLNode *current = gph_qPop(q);
        gph_Queue *neighbors = gph_getNeighbors(g, current->val);
        while(neighbors->size > 0) {
            gph_LLNode *neighbor = gph_qPop(neighbors);
            if(visited[neighbor->val] == 0) {
                //Set the parent
                path[neighbor->val] = current->val;
                //Queue to be visited
                gph_qAppendInt(q, neighbor->val);
                visited[neighbor->val] = 1;
            }
            free(neighbor);
        }
        destroy_Queue(neighbors);
        free(current);
    }
    //Build the linked list based on the integer of parent pointers
    i = t;
    gph_LLNode *head = (gph_LLNode*) malloc(sizeof(gph_LLNode));
    head->next = NULL;
    gph_LLNode *tail = head;
    while(i != -1) {
        tail->val = i;
        if(path[i] != -1) {
            tail->next = (gph_LLNode*) malloc(sizeof(gph_LLNode));
            tail = tail->next;
            tail->next = NULL;
        }
        i = path[i];
    }
    destroy_Queue(q);
    return head;
}

gph_Queue *gph_getNeighbors(Graph *g, int u)
{
    int i;
    gph_Queue *q = build_Queue();
    for (i = 0; i < g->num_vertices; i++)
    {
        if (g->adj[u][i] != 0)
        {
            gph_qAppendInt(q, i);
        }
    }
    return q;
}
