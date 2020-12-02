//
//  NO321.c
//  NO321
//
//  Created by wanyakun on 2020/12/2.
//

#include "NO321.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // 从指定位置开始比较两个序列大小
 int compare(int* subseq1, int subseq1Size, int index1, int* subseq2, int subseq2Size, int index2) {
     while(index1 < subseq1Size && index2 < subseq2Size) {
         int difference = subseq1[index1] - subseq2[index2];
         if(difference != 0) {
             return difference;
         } else {
             index1++;
             index2++;
         }
     }
     return (subseq1Size - index1) - (subseq2Size -index2);
 }
 // 寻找位数为k的最大子序列
int* maxSubSequence(int* nums, int numsSize, int k) {
    int* stack = malloc(k*sizeof(int));
    memset(stack, 0, k*sizeof(int));
    int top = -1;
    // stack可以弹出的次数
    int remain = numsSize - k;
    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while(top >= 0 && stack[top] < num && remain > 0) {
            top--;
            remain--;
        }
        if(top < k - 1) {
            stack[++top] = num;
        } else {
            remain--;
        }
    }
    return stack;
}
// 合并子序列
int* merge(int* subseq1, int subseq1Size, int* subseq2, int subseq2Size) {
    if(subseq1Size == 0) return subseq2;
    if(subseq2Size == 0) return subseq1;
    int mergeLength = subseq1Size + subseq2Size;
    int* merged = malloc(mergeLength*sizeof(int));
    int index1 = 0, index2 = 0;
    for(int i = 0; i < mergeLength; i++) {
        if(compare(subseq1, subseq1Size, index1, subseq2, subseq2Size, index2) > 0) {
            merged[i] = subseq1[index1++];
        } else {
            merged[i] = subseq2[index2++];
        }
    }
    return merged;
}
// 交互序列
void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b;
    *b = tmp;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize){
    //1. 求num1中i位数字的最大子序列， num2中k-i位数字的最大子序列
    //2. 合并 步骤1中的两个子序列, 得到当前合并后的最大子序列current
    //3，res 表示最大子序列，步骤二比较，更新res
    //4. 重复1、2、3
    //5. 最后返回res
    int* res = malloc(sizeof(int)*k);
    memset(res, 0, sizeof(int)*k);
    *returnSize = k;
    int start = fmax(0, k - nums2Size), end = fmin(k, nums1Size);
    for(int i = start; i <= end; i++) {
        int* subseq1 = maxSubSequence(nums1, nums1Size, i);
        int* subseq2 = maxSubSequence(nums2, nums2Size, k - i);
        int* current = merge(subseq1, i, subseq2, k-i);
        if(compare(current, k, 0, res, k, 0) > 0) {
            swap(&current, &res);
        }
    }
    return res;
}
