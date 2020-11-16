//
//  NO15.c
//  NO15
//
//  Created by wanyakun on 2020/11/16.
//

#include "NO15.h"
#include <stdlib.h>

// 方案超出时间限制，我也无语
int cmp(const void* _a, const void* _b) {
    return *(int*)_a - *(int*)_b;
}

int** towSum(int* nums, int numsSize, int start, int target, int* returnSize) {
    int lo = start, hi = numsSize - 1;
    int** res = (int**)calloc(numsSize*numsSize, sizeof(int*));
    (*returnSize) = 0;
    while(lo < hi) {
        int left = nums[lo], right = nums[hi], sum = left + right;
        if(sum < target) {
            while(lo < hi && nums[lo] == left) lo++;
        } else if(sum > target) {
            while(lo < hi && nums[hi] == right) hi--;
        } else {
            int* tmp = malloc(2*sizeof(int));
            tmp[0] = left;
            tmp[1] = right;
            res[(*returnSize)++] = tmp;
            while(lo < hi && nums[lo] == left) lo++;
            while(lo < hi && nums[hi] == right) hi--;
        }
    }
    return res;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    int** res = (int**)calloc(numsSize*numsSize, sizeof(int*));
    (*returnSize) = 0;
    (*returnColumnSizes) = malloc(numsSize*numsSize*sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        int tuplesSize;
        int** tuples = towSum(nums, numsSize, i+1, -nums[i], &tuplesSize);
        for(int j = 0; j < tuplesSize; j++) {
            res[(*returnSize)] = malloc(3*sizeof(int));
            //  memcpy(res[*returnSize], tuples[j], 2*sizeof(int));
            res[(*returnSize)][0] = nums[i];
            res[(*returnSize)][1] = tuples[j][0];
            res[(*returnSize)][2] = tuples[j][1];
            (*returnColumnSizes)[(*returnSize)] = 3;
            (*returnSize)++;
        }
        while(i < numsSize - 1 && nums[i] == nums[i+1]) i++;
    }
    return res;
}
