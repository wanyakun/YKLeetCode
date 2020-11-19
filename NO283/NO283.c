//
//  NO283.c
//  NO283
//
//  Created by wanyakun on 2020/11/19.
//

#include "NO283.h"

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize){
    int left = 0, right = 0;
    while(right < numsSize) {
        if(nums[right]) {
            swap(nums+left, nums+right);
            left++;
        }
        right++;
    }
}
