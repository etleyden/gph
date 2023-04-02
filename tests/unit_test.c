#include "graph.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Unit Tests for the library
int main(int argc, char *argv[]) {
    char *GREEN = "\033[0;32m";
    char *RED = "\033[0;31m";
    char *RESET = "\033[0m";
    printf("\n\n");
    //TEST gph_readFile
    printf("TEST 1: Undirected, unweighted, gph_readFile()\n");
    Graph *g = gph_readFile("tests/ex_graphs/simple.txt", 0, 0);
    int test1_size = 5;
    int test1[5] = {
        g->adj[0][1] == 1,
        g->adj[1][0] == 1,
        g->adj[3][1] == 1,
        g->adj[4][2] == 1,
        g->adj[3][2] == 0};
    
    int i;
    for(i = 0; i < test1_size; i++) {
        if(test1[i] == 0) {
            printf("%s TEST 1 FAILED.\n", RED);
            break;
        }
    }
    if(i == test1_size) {printf("%s TEST 1 OK.\n", GREEN);}

    //TEST gph_bfsToTarget
    printf("%sTEST 2: Undirected, unweighted, gph_bfsToTarget()\n", RESET);
    gph_LLNode *path = gph_bfsToTarget(g, 0, 3);
    //Path sequence should be 3, 1, 0 
    i = 0;
    int test2[3] = {3, 1, 0};
    gph_LLNode *current = path;
    while(current != NULL) {
        if(current->val == test2[i]) {
            current = current->next;
        } else {
            printf("%s TEST 2 FAILED.\n", RED);
            break;
        }
        i++;
    }
    if(i == 3) {
        printf("%s TEST 2 OK.\n", GREEN);
    }
    destroy_LLNodes(path);

    printf("%sLEAK CHECK: ", RESET);

    int status;
    if(argc == 2 && strcmp(argv[1], "valgrind") == 0) {
        printf("Won't do valgrind this time\n");
    } else {
        //Run unit tests with valgrind, and check for leaks
        status = system("valgrind --leak-check=full --log-file=\"tests/logs/valgrind.txt\" ./unit_test valgrind > tests/logs/valgrind.txt");

        //check log file  for leaks
        if(status != 0) {
            printf("%sFAILED. Valgrind was unable to execute\n", RED);
        }
        status = system("grep \"definitely lost\" tests/logs/valgrind.txt > tests/logs/output.txt");
        if(status != 0) {
            printf("%sFAILED. \"definitely lost\" in Valgrind output\n", RED);
        } else {
            printf("%sCOMPLETED. \"definitely lost\" was not found in Valgrind output\n", GREEN);
        }
    }

    //gph_destroy(g);
}
