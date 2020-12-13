//
//  NO217.c
//  NO217
//
//  Created by wanyakun on 2020/12/13.
//

#include "NO217.h"
#include <stdlib.h>
#include "uthash.h"
// 排序法
int cmp(const void * _a, const void * _b) {
    return *(int *)_a - *(int *)_b;
}

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize <= 1) return false;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize-1; i++) {
        if(nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}


// 哈希表
 typedef struct {
     int key;
     UT_hash_handle hh;
 } HashMap;

 bool containsDuplicate1(int* nums, int numsSize){
     if(numsSize <= 1) return false;
     HashMap* hashMap = NULL;
     for(int i = 0; i < numsSize; i++) {
         int num = nums[i];
         HashMap* tmp = NULL;
         HASH_FIND_INT(hashMap, &num, tmp);
         if(tmp == NULL) {
             tmp = malloc(sizeof(HashMap));
             tmp->key = num;
             HASH_ADD_INT(hashMap, key, tmp);
         } else {
             return true;
         }
     }
     return false;
 }
