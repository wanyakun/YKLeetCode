//
//  NO416.c
//  NO416
//
//  Created by wanyakun on 2020/11/26.
//

#include "NO416.h"
#include <stdlib.h>
#include <string.h>

bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    // 非偶数，无法划分
    if (sum%2 != 0) {
        return  false;
    }
    sum = sum/2;
    bool** dp = malloc((numsSize+1)*sizeof(bool*));
    // base case
    for (int i = 0; i <= numsSize; i++) {
        dp[i] = malloc((sum+1)*sizeof(bool));
        memset(dp[i], false, (sum+1)*sizeof(bool));
        dp[i][0] = true;
    }
    // 状态和选择
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= sum; j++) {
            if ((j - nums[i-1]) < 0) {
                // 背包装不下
                dp[i][j] = dp[i-1][j];
            } else {
                // 装或者不装
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[numsSize][sum];
}

bool canPartition1(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    // 非偶数，无法划分
    if (sum%2 != 0) {
        return  false;
    }
    sum = sum/2;
    bool* dp = malloc((sum+1)*sizeof(bool));
    memset(dp, false, (sum+1)*sizeof(bool));
    // base case
    dp[0] = true;
    // 状态和选择
    for (int i = 0; i < numsSize; i++) {
        // j需要反向遍历，因为数字只能用一次，一面影响之前的结果
        for (int j = sum; j >=0; j--) {
            if ((j - nums[i]) >= 0) {
                // 装或者不装
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
    }
    return dp[sum];
}
