//
//  NO493.c
//  NO493
//
//  Created by wanyakun on 2020/11/28.
//

#include "NO493.h"

// int reversePairs(int* nums, int numsSize){
//     // base case
//     if(numsSize <= 1) return 0;
//     int res = 0;
//     for(int i = 0; i < numsSize -1; i++) {
//         for(int j =i+1; j < numsSize; j++) {
//             if((long long)nums[i] > 2*(long long)nums[j]) {
//                 res++;
//             }
//         }
//     }
//     return res;
// }
int mergeSort(int* nums, int left, int right) {
    if(left == right) return 0;
    int mid = (left + right) / 2;
    int n1 = mergeSort(nums, left, mid);
    int n2 = mergeSort(nums, mid+1, right);
    int ret = n1 + n2;
    // 计算下标对个数
    int i = left;
    int j = mid+1;
    while(i <= mid && j <= right) {
        if((long long)nums[i] > 2*(long long)nums[j]) {
            ret += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }
    // 合并两个排序数组
    int tmp[right - left + 1];
    i = left;
    j = mid + 1;
    int index = 0;
    while(i <= mid && j <= right) {
        if(nums[i] < nums[j]) {
            tmp[index++] = nums[i++];
        } else {
            tmp[index++] = nums[j++];
        }
    }
    // 合并左侧剩余或者右侧剩余
    while(i <= mid) {
        tmp[index++] = nums[i++];
    }
    while(j <= right) {
        tmp[index++] = nums[j++];
    }
    // 对nums进行原地翻转
    for(int i = 0; i < right-left+1; i++) {
        nums[left+i] = tmp[i];
    }

    return ret;
}

int reversePairs(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    return mergeSort(nums, 0, numsSize-1);
}
