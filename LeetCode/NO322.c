//
//  NO322.c
//  LeetCode
//
//  Created by wanyakun on 2020/10/27.
//

#include "NO322.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a > b ? b : a;
}

#pragma mark - 方案一 暴力递归
// 暴力
int coinChange(int* coins, int coinsSize, int amount){
    // base case
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int res = INT_MAX;
    for (int i = 0; i < coinsSize; i++) {
     int coin = coins[i];
     int sub = coinChange(coins, coinsSize, amount-coin);
     if(sub == -1) continue;
     res = min(res, 1+sub);
    }
    return res != INT_MAX ? res : -1;
}

#pragma mark - 方案二 带备忘录递归
int dp(int* coins, int coinsSize, int amount, int* memo){
    // 备忘录取值
    if (memo[amount] != 0) return memo[amount];
    // base case
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int res = INT_MAX;
    for (int i = 0; i < coinsSize; i++) {
        int sub = dp(coins, coinsSize, amount-coins[i], memo);
        if(sub == -1) continue;
        res = min(res, 1+sub);
    }
    // 备忘录设置值
    memo[amount] = (res != INT_MAX ? res : -1);
    return memo[amount];
}

int coinChange1(int* coins, int coinsSize, int amount){
    int* memo = malloc((amount+1)*sizeof(int));
    memset(memo, 0, (amount+1)*sizeof(int));
    return dp(coins, coinsSize, amount, memo);
}

#pragma mark - 方案三 dp数组迭代
int coinChange2(int* coins, int coinsSize, int amount){
    
}
