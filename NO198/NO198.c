//
//  NO198.c
//  NO198
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO198.h"
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

//方案四，
int rob4(int* nums, int numsSize){
    int dp_i = 0, dp_i_1 = 0, dp_i_2 = 0;// 分别记录dp[i] dp[i+1], dp[i+2]
    for(int i = numsSize-1; i >= 0; i--) {
        dp_i = max(dp_i_1, nums[i]+dp_i_2);
        // 向前移动
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }
    return dp_i;
}
 // 方案三，自底向上迭代方式
 int rob3(int* nums, int numsSize){
     if(numsSize <= 0) return 0;
     int* dp = malloc((numsSize+2)*sizeof(int));
     dp[numsSize] = 0;
     dp[numsSize+1] = 0;
     for (int i = numsSize -1; i >=0; i--) {
         dp[i] = max(dp[i+1], nums[i]+ dp[i+2]);
     }
     return dp[0];
 }

// 方案二，记录重复子问题，避免重复计算
 int* memo;
 int dp2(int* nums, int start, int numsSize) {
     if(start >= numsSize) {
         return 0;
     }
     if (memo[start] != -1) {
         return memo[start];
     }
     int res = max(dp2(nums, start+1, numsSize), nums[start]+dp2(nums, start+2, numsSize));
     memo[start] = res;
     return res;
 }

 int rob2(int* nums, int numsSize){
     memo = malloc(numsSize*sizeof(int));
     memset(memo, -1, numsSize*sizeof(int));
     return dp2(nums, 0, numsSize);
 }

// 方案一 超出时间限制。。。
 int dp(int* nums, int start, int numsSize) {
     if(start >= numsSize) {
         return 0;
     }
     int res = max(dp(nums, start+1, numsSize), nums[start]+dp(nums, start+2, numsSize));
     return res;
 }

 int rob(int* nums, int numsSize){
     return dp(nums, 0, numsSize);
 }
