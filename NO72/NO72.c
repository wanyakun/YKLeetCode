//
//  NO72.c
//  NO72
//
//  Created by wanyakun on 2020/11/23.
//

#include "NO72.h"
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int minDistance(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);

    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++) {
        dp[i][0] = dp[i-1][0] + 1;
    }
    for(int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i-1] + 1;
    }
    for(int i = 1; i <=m; i++) {
        for(int j = 1; j <= n; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                // dp[i-1][j-1] + 1 替换
                // dp[i-1][j] + 1 删除
                // dp[i][j-1] + 1 插入
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
            }
        }
    }

    return dp[m][n];
}
