//
//  Offer09.c
//  Offer09
//
//  Created by wanyakun on 2020/12/21.
//

#include "Offer09.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;
    int top1;
    int top2;
    int* stk1;
    int* stk2;
} CQueue;


CQueue* cQueueCreate() {
    CQueue* queue = malloc(sizeof(CQueue));
    queue->top1 = -1;
    queue->top2 = -1;
    queue->stk1 = malloc((10000)*sizeof(int));
    queue->stk2 = malloc((10000)*sizeof(int));
    memset(queue->stk1, 0, sizeof(queue->stk1));
    memset(queue->stk2, 0, sizeof(queue->stk2));
    return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    (obj->stk1)[++(obj->top1)] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    if(obj->top2 >= 0) {
        return (obj->stk2)[obj->top2--];
    } else {
        if(obj->top1 >= 0) {
            while(obj->top1 >= 0) {
                (obj->stk2)[++obj->top2] = (obj->stk1)[obj->top1--];
            }
            return (obj->stk2)[obj->top2--];
        } else {
            return -1;
        }
    }
}

void cQueueFree(CQueue* obj) {
    free(obj->stk1);
    free(obj->stk2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
