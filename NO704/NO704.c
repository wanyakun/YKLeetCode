//
//  NO704.c
//  NO704
//
//  Created by wanyakun on 2020/11/10.
//

#include "NO704.h"

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else if(nums[mid] > target) {
            right = mid -1;
        }
    }
    return -1;
}
