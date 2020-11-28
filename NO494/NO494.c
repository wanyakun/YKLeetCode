//
//  NO494.c
//  NO494
//
//  Created by wanyakun on 2020/11/29.
//

#include "NO494.h"
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

// 转为背包问题，动态规划
// sum[A]-sum[B] = target
// sum[A] = target + sum[B]
// sum[A] + sum[A] = target + sum[B] + sum[A] = target + sum[nums]
// sum[A] = (target+sum[sums])/2;
// 变为nums存在几个子集A，使A中元素之和为(target+sum[sums])/2
// 动态规划+状态压缩
int subsets(int* nums, int numsSize, int sum) {
    int* dp = malloc((sum+1)*sizeof(int));
    memset(dp, 0, (sum+1)*sizeof(int));
    // base case
    dp[0] = 1;
    // 状态转换
    for(int i = 1; i <= numsSize; i++) {
        for(int j = sum; j >= 0; j--) {
            if(j - nums[i-1] >= 0) {
                // 两种选择结果之和
                dp[j] = dp[j] + dp[j-nums[i-1]];
            }
        }
    }
    return dp[sum];
}

int findTargetSumWays(int* nums, int numsSize, int S){
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    // 这两种情况不可能存在合法子集
    if(sum < S || (sum+S)%2 == 1) return 0;
    return subsets(nums, numsSize, (sum+S)/2);
}



// 动态规划
 int subsets1(int* nums, int numsSize, int sum) {
     // int dp[numsSize+1][sum+1];
     int** dp = malloc((numsSize+1)*sizeof(int*));
     // base case
     for(int i = 0; i <= numsSize; i++) {
         dp[i] = malloc((sum+1)*sizeof(int));
         memset(dp[i], 0, (sum+1)*sizeof(int));
         dp[i][0] = 1;
     }
     // 状态转换
     for(int i = 1; i <= numsSize; i++) {
         for(int j = 0; j <= sum; j++) {
             if(j - nums[i-1] < 0) {
                 // 空间不足，不可以选择
                 dp[i][j] = dp[i-1][j];
             } else {
                 // 两种选择结果之和
                 dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
             }
         }
     }
     return dp[numsSize][sum];
 }

 int findTargetSumWays1(int* nums, int numsSize, int S){
     int sum = 0;
     for(int i = 0; i < numsSize; i++) {
         sum += nums[i];
     }
     // 这两种情况不可能存在合法子集
     if(sum < S || (sum+S)%2 == 1) return 0;
     return subsets1(nums, numsSize, (sum+S)/2);
 }



// 回溯+备忘录, 居然超出时间限制
 typedef struct {
     char* key;
     int val;
     UT_hash_handle hh;
 } HashMap;
 HashMap* memo = NULL;
 int dp(int* nums, int numsSize, int target, int i, int sum) {
     // base case
     if(i == numsSize) {
         if(sum == target) {
             return 1;
         }
         return 0;
     }
     // 转化key
     char* key = malloc(8*sizeof(char));
     sprintf(key, "%d,%d", i, sum);
     // 避免重复结算
     HashMap* tmp = NULL;
     HASH_FIND_STR(memo, key, tmp);
     if(tmp) {
         return tmp->val;
     }
     // 穷举
     int result = dp(nums, numsSize, target, i+1, sum+nums[i]) + dp(nums, numsSize, target, i+1, sum-nums[i]);
     // 计入备忘录
     tmp = malloc(sizeof(HashMap));
     tmp->key = key;
     tmp->val = result;
     HASH_ADD_STR(memo, key, tmp);
     return result;
 }

 int findTargetSumWays2(int* nums, int numsSize, int S){
     // base case
     if(numsSize == 0) return 0;
     return dp(nums, numsSize, S, 0, 0);
 }


// 回溯方法
 int result;
 void backtrack(int* nums, int numsSize, int tareget, int i, int sum) {
     // base case, 遍历到num的最后一个位置
     if(i == numsSize) {
         // 说明刚好凑出target
         if(sum == tareget) {
             result++;
         }
         return;
     }
     // 做选择
     // 选择用+符号
     sum += nums[i];
     // 穷举i+1
     backtrack(nums, numsSize, tareget, i+1, sum);
     // 撤销选择
     sum -= nums[i];

     // 选择用-符号
     sum -= nums[i];
     // 穷举i+1
     backtrack(nums, numsSize, tareget, i+1, sum);
     // 撤销选择
     sum += nums[i];
 }

 int findTargetSumWays3(int* nums, int numsSize, int S){
     // base case
     if(numsSize == 0) return 0;
     result = 0;
     backtrack(nums, numsSize, S, 0, 0);
     return result;
 }
