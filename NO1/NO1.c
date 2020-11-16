//
//  NO1.c
//  NO1
//
//  Created by wanyakun on 2020/11/16.
//

#include "NO1.h"
#include "uthash.h"
#include <stdlib.h>

typedef struct {
     int val;
     int index;
     UT_hash_handle hh;
 } unorder_map;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = malloc(2*sizeof(int));
    (*returnSize) = 2;
    unorder_map* map = NULL;
    for(int i = 0; i < numsSize; i++) {
        int sum = target - nums[i];
        unorder_map* tmp = NULL;
        HASH_FIND_INT(map, &sum, tmp);
        if(tmp) {
            res[0] = tmp->index;
            res[1] = i;
            break;
        } else {
            tmp = malloc(sizeof(unorder_map));
            tmp->val = nums[i];
            tmp->index = i;
            HASH_ADD_INT(map, val, tmp);
        }
    }
    return res;
}
