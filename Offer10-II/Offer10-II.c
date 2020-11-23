//
//  Offer10-II.c
//  Offer10-II
//
//  Created by wanyakun on 2020/11/23.
//

#include "Offer10-II.h"
#include <stdlib.h>
#include <string.h>

int numWays(int n){
    if(n <= 1) return 1;
    // 存储历史结果
    int* dp = malloc((n+1)*sizeof(int));
    memset(dp, 0, (n+1));
    // base case
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }
    // 返回最终结果
    return dp[n];
}
