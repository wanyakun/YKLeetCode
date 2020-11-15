//
//  NO213.c
//  NO213
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO213.h"

int max(int a, int b) {
    return a > b ? a : b;
}
// 计算闭区间[start, end]
int robRange(int* nums, int start, int end) {
    int dp_i = 0, dp_i_1 = 0, dp_i_2 = 0;
    for(int i = end; i >= start; i--) {
        dp_i = max(dp_i_1, nums[i]+dp_i_2);
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }
    return dp_i;
}

int rob(int* nums, int numsSize){
    if(numsSize == 1) return nums[0];
    return max(robRange(nums, 0, numsSize-2), robRange(nums, 1, numsSize-1));
}
