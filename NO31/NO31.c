//
//  NO31.c
//  NO31
//
//  Created by wanyakun on 2020/11/10.
//

#include "NO31.h"

void swap(int *a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void revers(int* nums, int left, int right) {
    while(left < right) {
        swap(nums+left, nums+right);
        left++;
        right--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int i = numsSize - 2;
    while(i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }
    if(i >= 0) {
        int j = numsSize-1;
        while(j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums+i, nums+j);
    }
    revers(nums, i+1, numsSize-1);
}
