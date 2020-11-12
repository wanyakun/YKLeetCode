//
//  NO34.c
//  NO34
//
//  Created by wanyakun on 2020/11/12.
//

#include "NO34.h"
#include <stdlib.h>
#include <string.h>

int leftBound(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize -1;
    while(left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 锁定左边界
            right = mid - 1;
        }
    }
    // 判断左边界是否越界
    if (left >= numsSize || nums[left] != target) {
        return -1;
    }
    return left;
}

int rightBound(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize -1;
    while(left <= right) {
        int mid = left + (right - left)/2;
        if(nums[mid] < target) {
            left = mid + 1;
        } else if(nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 锁定右边界
            left = mid + 1;
        }
    }
    // 判断右边界是否越界
    if(right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(2*sizeof(int));
    memset(res, -1, 2*sizeof(int));
    *returnSize = 2;
    // base case
    if(nums == NULL || numsSize < 1) {
        return res;
    }

    int left = leftBound(nums, numsSize, target);
    if(left == -1) {
        return res;
    }
    res[0] = left;
    res[1] = rightBound(nums, numsSize, target);
    return res;
}
