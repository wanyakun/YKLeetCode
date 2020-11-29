//
//  NO583.c
//  NO583
//
//  Created by wanyakun on 2020/11/30.
//

#include "NO583.h"
#include <stdlib.h>
#include <string.h>

// 动态规划+状态压缩，总长度-2*公共子序列
int max(int a, int b) {
    return a > b ? a : b;
}
int minDistance(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= m; i++) {
        int pre = 0;
        for(int j =1; j <= n; j++) {
            int tmp = dp[j];
            if(word1[i-1] == word2[j-1]) {
                dp[j] = 1 + pre;
            } else {
                dp[j] = max(dp[j], dp[j-1]);
            }
            pre = tmp;
        }
    }
    return m + n - 2*dp[n];
}
// 动态规划
 int min(int a, int b) {
     return a > b ? b : a;
 }
 int minDistance1(char * word1, char * word2){
     // word1[0..i-1], word2[0..j-1] 相同的最小步数dp[i][j]
     // base case dp[i][0] = i, dp[0][j] = j;
     int m = strlen(word1);
     int n = strlen(word2);
     int dp[m+1][n+1];
     for(int i = 0; i <= m; i++) {
         dp[i][0] = i;
     }
     for (int j = 0; j <= n; j++) {
         dp[0][j] = j;
     }
     for(int i = 1; i <= m; i++) {
         for(int j = 1; j <= n; j++) {
             if(word1[i-1] == word2[j-1]) {
                 // 什么都不需要做
                 dp[i][j] = dp[i-1][j-1];
             } else {
                 // 其中一个删除
                 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
             }
         }
     }
     return dp[m][n];
 }
