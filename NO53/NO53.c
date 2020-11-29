//
//  NO53.c
//  NO53
//
//  Created by wanyakun on 2020/11/29.
//

#include "NO53.h"
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}
// 动态规划+状态压缩
int maxSubArray(int* nums, int numsSize){
    // base case
    if(numsSize == 0) return 0;
    // 第一个元素前没有子数组
    int dp_0 = nums[0];
    int dp_1 = 0;
    int res = dp_0;
    for(int i = 1; i < numsSize; i++) {
        dp_1 = max(nums[i], nums[i]+dp_0);
        dp_0 = dp_1;
        // 顺便计算最大值
        res = max(res, dp_1);
    }
    return res;
}

// 动态规划
 int maxSubArray1(int* nums, int numsSize){
     // base case
     if(numsSize == 0) return 0;
     int* dp = malloc(numsSize*sizeof(int));
     // 第一个元素前没有子数组
     dp[0] = nums[0];
     for(int i = 1; i < numsSize; i++) {
         dp[i] = max(nums[i], nums[i]+dp[i-1]);
     }
     int res = INT_MIN;
     for(int i = 0; i < numsSize; i++) {
         res = max(res, dp[i]);
     }
     return res;
 }
