//
//  NO1356.c
//  NO1356
//
//  Created by wanyakun on 2020/11/6.
//

#include "NO1356.h"
#include <stdlib.h>
#include <string.h>

int* bit;

int getCount(int num) {
    int cnt = 0;
    while(num>0) {
        if(num%2) cnt++;
        num = num/2;
    }
    return cnt;
}

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (bit[x] == bit[y] ? x - y : bit[x] - bit[y]);
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    bit = malloc(10001*sizeof(int));
    memset(bit, 0, sizeof(int) * 10001);
    for(int i = 0; i < arrSize; i++) {
        bit[arr[i]] = getCount(arr[i]);
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    free(bit);
    *returnSize = arrSize;
    return arr;
}


 typedef struct {
     int val;
     int count;
 } Node;

 int* sortByBits1(int* arr, int arrSize, int* returnSize){
     Node** nodes = malloc(arrSize*sizeof(Node));
     for(int i = 0; i < arrSize; i++) {
         Node* node = malloc(sizeof(Node));
         node->val = arr[i];
         node->count = getCount(arr[i]);
         nodes[i] = node;
     }
     // 对Node进行冒泡排序
     for (int i = 0; i < arrSize; i++) {
         for (int j = arrSize -1; j > i; j--) {
             Node* node1 = nodes[i];
             Node* node2 = nodes[j];
             if ((node1->count > node2->count) || (node1->count == node2->count && node1->val > node2->val)) {
                 nodes[i] = node2;
                 nodes[j] = node1;
             }
         }
     }
     
     int* res = malloc(arrSize*sizeof(int));
     *returnSize = arrSize;
     for(int i = 0; i < arrSize; i++) {
         res[i] = nodes[i]->val;
     }
     return res;
 }
