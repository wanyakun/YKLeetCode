//
//  NO18.c
//  NO18
//
//  Created by wanyakun on 2020/11/16.
//

#include "NO18.h"
#include <stdlib.h>

// 方案超出时间限制，我也无语
int cmp(const void* _a, const void* _b) {
    return *(int*)_a - *(int*)_b;
}

int** nSumTarget(int* nums, int numsSize, int n, int start, int target, int* returnSize) {
    int** res = (int**)calloc(numsSize*numsSize, sizeof(int*));
    (*returnSize) = 0;
    // 至少是2Sum, 且数组大小不应该小于n
    if (n < 2 || numsSize < n) {
        return  res;
    }
    // 2sum 为base case
    if (n == 2) {
        // 双指针
        int lo = start, hi = numsSize - 1;
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
    } else {
        // n > 2时，递归计算（n-1）sum的结果
        for (int i = start; i < numsSize; i++) {
            int subSize;
            int** sub = nSumTarget(nums, numsSize, n-1, i+1, target-nums[i], &subSize);
            for(int j = 0; j < subSize; j++) {
                res[(*returnSize)] = malloc(n*sizeof(int));
                //  memcpy(res[*returnSize], tuples[j], 2*sizeof(int));
                res[(*returnSize)][0] = nums[i];
                for (int k = 0; k < n; k++) {
                    res[(*returnSize)][k+1] = sub[j][k];
                }
                (*returnSize)++;
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            while(i < numsSize - 1 && nums[i] == nums[i+1]) i++;
        }
    }
    return res;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    int** res = nSumTarget(nums, numsSize, 4, 0, target, returnSize);
    (*returnColumnSizes) = malloc((*returnSize)*sizeof(int));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return res;
}
