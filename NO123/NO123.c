//
//  NO123.c
//  NO123
//
//  Created by wanyakun on 2020/11/14.
//

#include "NO123.h"
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    int k = 2;
    int dp_0[k+1], dp_1[k+1];
    memset(dp_0, 0, (k+1)*sizeof(0));
    memset(dp_1, 0, (k+1)*sizeof(0));
    for(int i = 0; i < pricesSize; i++) {
        for(int j = k; j >= 1; j--) {
            //base case
            if(i-1 == -1) {
                dp_0[j] = 0;
                dp_1[j] = -prices[i];
            }
            dp_0[j] = max(dp_0[j], dp_1[j]+prices[i]);
            dp_1[j] = max(dp_1[j], dp_0[j-1]-prices[i]);
        }
    }
    return dp_0[k];
}

 int maxProfit1(int* prices, int pricesSize){
     // 穷尽k=2的次数
     // dp[i][2][0] = max(dp[i][2][0], dp[i][2][1]+prices[i]);
     // dp[i][2][1] = max(dp[i][2][1], dp[i][1][0]-prices[i]);
     // dp[i][1][0] = max(dp[i][1][0], dp[i][1][1]+prices[i]);
     // dp[i][1][1] = max(dp[i][1][1], -prices[i]);
     int dp_i_10 = 0, dp_i_11 = -INT_MAX;
     int dp_i_20 = 0, dp_i_21 = -INT_MAX;
     for(int i = 0; i < pricesSize; i++) {
         dp_i_20 = max(dp_i_20, dp_i_21+prices[i]);
         dp_i_21 = max(dp_i_21, dp_i_10-prices[i]);
         dp_i_10 = max(dp_i_10, dp_i_11+prices[i]);
         dp_i_11 = max(dp_i_11, -prices[i]);
     }
     return dp_i_20;
 }
