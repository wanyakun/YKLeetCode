//
//  NO518.c
//  NO518
//
//  Created by wanyakun on 2020/11/26.
//

#include "NO518.h"
#include <stdlib.h>
#include <string.h>

// dp二维数组
 int change(int amount, int* coins, int coinsSize){
     int** dp = malloc((coinsSize+1)*sizeof(int*));
     // base case
     for(int i = 0; i <= coinsSize; i++) {
         dp[i] = malloc((amount+1)*sizeof(int));
         memset(dp[i], 0, (amount+1)*sizeof(int));
         dp[i][0] = 1;
     }
     for(int i = 1; i <= coinsSize; i++) {
         for(int j = 1; j <= amount; j++) {
             if(j - coins[i-1] >= 0) {
                 dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
             } else {
                 dp[i][j] = dp[i-1][j];
             }
         }
     }
     return dp[coinsSize][amount];
 }

// dp状态压缩
int change1(int amount, int* coins, int coinsSize){
    int* dp = malloc((amount+1)*sizeof(int));
    memset(dp, 0, (amount+1)*sizeof(int));
    dp[0] = 1;
    for(int i = 1; i <= coinsSize; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j - coins[i-1] >= 0) {
                dp[j] = dp[j] + dp[j-coins[i-1]];
            }
        }
    }
    return dp[amount];
}
