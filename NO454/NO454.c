//
//  NO454.c
//  NO454
//
//  Created by wanyakun on 2020/11/27.
//

#include "NO454.h"
#include "uthash.h"
#include <stdlib.h>

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashTable;

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    HashTable* hashTable = NULL;
    for(int i = 0; i < ASize; i++) {
        for(int j = 0; j < BSize; j++) {
            int iKey = A[i] + B[j];
            HashTable* tmp = NULL;
            HASH_FIND_INT(hashTable, &iKey, tmp);
            if(tmp == NULL) {
                tmp = malloc(sizeof(HashTable));
                tmp->key = iKey;
                tmp->val = 1;
                HASH_ADD_INT(hashTable, key, tmp);
            } else {
                tmp->val++;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < CSize; i++) {
        for(int j = 0; j < DSize; j++) {
            int iKey = -C[i] - D[j];
            HashTable* tmp = NULL;
            HASH_FIND_INT(hashTable, &iKey, tmp);
            if(tmp) {
                res += tmp->val;
            }
        }
    }
    return res;
}
