//
//  NO1207.c
//  NO1207
//
//  Created by wanyakun on 2020/10/28.
//

#include "NO1207.h"
#include <stdlib.h>
#include "uthash.h"

typedef struct {
    int key;
    UT_hash_handle hh;
} unordered_set;

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} unordered_map;

bool uniqueOccurrences(int* arr, int arrSize){
    unordered_map* occur = NULL;
    for (int i = 0; i < arrSize; i++) {
        unordered_map* tmp = NULL;
        HASH_FIND_INT(occur, &arr[i], tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(unordered_map));
            tmp->key = arr[i];
            tmp->val = 1;
            HASH_ADD_INT(occur, key, tmp);
        } else {
            (tmp->val)++;
        }
    }
    unordered_set* times = NULL;
    unordered_map * cur, *cur_tmp;
    HASH_ITER(hh, occur, cur, cur_tmp) {
        unordered_set* tmp = NULL;
        HASH_FIND_INT(times, &(cur->val), tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(unordered_set));
            tmp->key = cur->val;
            HASH_ADD_INT(times, key, tmp);
        }
    }
    return HASH_COUNT(occur) == HASH_COUNT(times);
}
