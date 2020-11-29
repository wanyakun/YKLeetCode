//
//  NO712.c
//  NO712
//
//  Created by wanyakun on 2020/11/30.
//

#include "NO712.h"
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int minimumDeleteSum(char * s1, char * s2){
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[m+1][n+1];
    // base case
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++) {
        dp[i][0] = s1[i-1]+dp[i-1][0];
    }
    for(int j = 1; j <= n; j++) {
        dp[0][j] = s2[j-1]+dp[0][j-1];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
    }
    return dp[m][n];
}
