//
//  NO121.c
//  NO121
//
//  Created by wanyakun on 2020/11/14.
//

#include "NO121.h"
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}
// 方案2
int maxProfit(int* prices, int pricesSize){
    int dp_i_0 = 0;
    int dp_i_1 = -INT_MAX;
    for(int i =0; i < pricesSize; i++) {
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, -prices[i]);
    }
    return dp_i_0;
}
// 方案1
 int maxProfit1(int* prices, int pricesSize){
     if(pricesSize < 1) return 0;
     int** dp = malloc(pricesSize*sizeof(int*));
     for(int i = 0; i < pricesSize; i++) {
         dp[i] = malloc(2*sizeof(int));
         if(i-1 == -1) {
             dp[i][0] = 0;
             dp[i][1] = -prices[i];
             continue;
         }
         dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
         dp[i][1] = max(dp[i-1][1], -prices[i]);
     }
     return dp[pricesSize-1][0];
 }
