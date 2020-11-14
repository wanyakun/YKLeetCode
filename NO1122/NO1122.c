//
//  NO1122.c
//  NO1122
//
//  Created by wanyakun on 2020/11/14.
//

#include "NO1122.h"
#include "uthash.h"
#include <stdlib.h>

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashTable;

HashTable* hashTable;

HashTable* find(int key) {
    HashTable* tmp = NULL;
    HASH_FIND_INT(hashTable, &key, tmp);
    return tmp;
}

void insert(int iKey, int iVal) {
    HashTable* tmp = malloc(sizeof(HashTable));
    tmp->key = iKey;
    tmp->val = iVal;
    HASH_ADD_INT(hashTable, key, tmp);
}

int cmp(const void* _a, const void* _b) {
    int a = *((int *)_a);
    int b = *((int *)_b);
    HashTable *fa = find(a), *fb = find(b);
    if(fa == NULL) {
        return fb == NULL ? a - b : 1;
    } else {
        return fb == NULL ? -1 : fa->val - fb->val;
    }
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    hashTable = NULL;
    for(int i = 0; i < arr2Size; i++) {
        insert(arr2[i], i);
    }
    qsort(arr1, arr1Size, sizeof(int), cmp);
    *returnSize = arr1Size;
    return arr1;
}
