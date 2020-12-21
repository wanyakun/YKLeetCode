//
//  NO746.c
//  NO746
//
//  Created by wanyakun on 2020/12/21.
//

#include "NO746.h"
#include <stdlib.h>
#include <math.h>

int minCostClimbingStairs(int* cost, int costSize){

    // dp[i] 表示爬上第i个阶梯花费最小的体力值
    // 状态转移 dp[i] = fmin(dp[i-1], dp[i-2]) + cost[i]; 通过一步或者两步到达
    // base case dp[0] = cost[0]
    // dp[1] = cost[1];

     int* dp = malloc(costSize*sizeof(int));
     dp[0] = cost[0];
     dp[1] = cost[1];
     for(int i = 2; i < costSize; i++) {
         dp[i] = fmin(dp[i-1], dp[i-2]) + cost[i];
     }
     return fmin(dp[costSize-2], dp[costSize-1]);
}

int minCostClimbingStairs1(int* cost, int costSize){
    // 状态压缩
    int dp_i_1 = cost[1], dp_i_2 = cost[0];
    for(int i = 2; i < costSize; i++) {
        int tmp = fmin(dp_i_1, dp_i_2) + cost[i];
        dp_i_2 = dp_i_1;
        dp_i_1 = tmp;
    }
    return fmin(dp_i_1, dp_i_2);
}
