//TYPEDEFS
/*
 * A linked list utility for graph.c
 */
typedef struct gph_LLNode {
    int val;
    struct gph_LLNode *next;
} gph_LLNode;
/*
 * A wrapper for linked lists (Queue)
 */
typedef struct gph_Queue {
    int size;
    gph_LLNode *first;
    gph_LLNode *last;
} gph_Queue;

//LINKED LIST 
/*
 * Free a linked list back into memory
 */
void destroy_LLNodes(gph_LLNode*);

/*
 * Get nth node. 
 * Args: the linked list, and the nth value. n=-1 gets the last item
 */
gph_LLNode* get_LLNodes(gph_LLNode*, int);

/*
 * Print the values of a linked list in sequence
 */
void print_LLNodes(gph_LLNode*);

//QUEUE
gph_Queue* build_Queue();
/*
 * Free a queue back into memory
 */
void destroy_Queue(gph_Queue*);

/*
 * Utility methods to add and remove from the queue.
 * qAppendInt -> pass an integer value and we will create the node for you
 * qAppendNode -> pass a gph_LLNode and we will just pop it onto the end
 */
gph_LLNode* gph_qPop(gph_Queue*);
void gph_qAppendInt(gph_Queue*, int);
void gph_qAppendNode(gph_Queue*, gph_LLNode*);
