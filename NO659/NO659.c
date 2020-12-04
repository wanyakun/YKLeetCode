//
//  NO659.c
//  NO659
//
//  Created by wanyakun on 2020/12/4.
//

#include "NO659.h"
#include "uthash.h"

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashTable;

HashTable* find(HashTable** hashTable, int key) {
    HashTable* tmp = NULL;
    HASH_FIND_INT(*hashTable, &key, tmp);
    return tmp;
}

void insert(HashTable** hashTable, int key, int val) {
    HashTable* tmp = malloc(sizeof(HashTable));
    tmp->key = key;
    tmp->val = val;
    HASH_ADD_INT(*hashTable, key, tmp);
}

int query(HashTable** hashTable, int key) {
    HashTable* tmp = find(hashTable, key);
    if(tmp) {
        return tmp->val;
    }
    return 0;
}

void modify(HashTable** hashTable, int key, int val) {
    HashTable *tmp = find(hashTable, key);
    if(tmp) {
        tmp->val = val;
    } else {
        insert(hashTable, key, val);
    }
}

void inc(HashTable** hashTable, int key) {
    HashTable *tmp = find(hashTable, key);
    if(tmp) {
        tmp->val++;
    } else {
        insert(hashTable, key, 1);
    }
}

bool isPossible(int* nums, int numsSize){
    HashTable* countMap = NULL;
    HashTable* endMap = NULL;
    for(int i = 0; i < numsSize; i++) {
        inc(&countMap, nums[i]);
    }

    for(int i = 0; i < numsSize; i++) {
        int count = query(&countMap, nums[i]);
        if(count > 0) {
            int preEndCount = query(&endMap, nums[i]-1);
            if(preEndCount > 0) {
                modify(&countMap, nums[i], count-1);
                modify(&endMap, nums[i]-1, preEndCount-1);
                inc(&endMap, nums[i]);
            } else {
                int count1 = query(&countMap, nums[i]+1);
                int count2 = query(&countMap, nums[i]+2);
                if(count1 > 0 && count2 > 0) {
                    modify(&countMap, nums[i], count-1);
                    modify(&countMap, nums[i]+1, count1-1);
                    modify(&countMap, nums[i]+2, count2-1);
                    inc(&endMap, nums[i]+2);
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}
