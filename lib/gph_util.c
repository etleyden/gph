#include "gph_util.h"
#include <stdio.h>
#include <stdlib.h>

void destroy_LLNodes(gph_LLNode *head) {
    gph_LLNode *next;
    gph_LLNode *current = head;
    do {
        next = current->next;
        free(current);
        current = next;
    } while(current != NULL);
}

gph_LLNode* get_LLNodes(gph_LLNode *head, int n) {
    int i;
    gph_LLNode *result = head;
    if(n == -1) {
        while(result->next != NULL) {
            result = result->next;
        }
    } else {
        for(i = 0; i < n; i++) {
            result = result->next;
        }
    }
    return result;
}

void print_LLNodes(gph_LLNode *head) {
    gph_LLNode *current = head;
    while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

gph_Queue* build_Queue() {
    gph_Queue *q = (gph_Queue*) malloc(sizeof(gph_Queue));
    q->size = 0;
    return q;
}

void destroy_Queue(gph_Queue *q) {
    while(q->size > 0) {
        gph_LLNode *next = gph_qPop(q);
        free(next);
    }
    free(q);
}

gph_LLNode* gph_qPop(gph_Queue *q) {
    gph_LLNode *head = q->first;
    q->first = q->first->next;
    //detach the pointer to the next element
    head->next = NULL;
    q->size--;
    return head;
}

void gph_qAppendInt(gph_Queue *q, int val) {
    gph_LLNode *newNode = (gph_LLNode*) malloc(sizeof(gph_LLNode));
    newNode->val = val;
    newNode->next = NULL;
    gph_qAppendNode(q, newNode);
}
void gph_qAppendNode(gph_Queue *q, gph_LLNode *node) {
    if(q->size == 0) {
        q->first = node;
        q->last = node;
    } else {
        q->last->next = node;
        q->last = q->last->next;
    }
    q->size++;
}
