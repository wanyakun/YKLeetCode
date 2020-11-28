//
//  NO516.c
//  NO516
//
//  Created by wanyakun on 2020/11/28.
//

#include "NO516.h"
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

// 状态压缩
int longestPalindromeSubseq(char * s){
    int n = strlen(s);
    int* dp = malloc(n*sizeof(int));
    // memset(dp, 1, n*sizeof(int));
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    for(int i = n-2; i >= 0; i--) {
        int pre = 0;
        for(int j = i+1; j < n; j++) {
            int tmp = dp[j];
            if(s[i] == s[j]) {
                dp[j] = pre+2;
            } else {
                dp[j] = max(dp[j-1], dp[j]);
            }
            pre = tmp;
        }
    }
    return dp[n-1];
}


 int longestPalindromeSubseq1(char * s){
     int n = strlen(s);
     int** dp = malloc(n*sizeof(int*));
     // base case
     for(int i = 0; i < n; i++) {
         dp[i] = malloc(n*sizeof(int));
         memset(dp[i], 0, n*sizeof(int));
         dp[i][i] = 1;
     }
     for(int i = n-1; i >= 0; i--) {
         for(int j = i+1; j < n; j++) {
             if(s[i] == s[j]) {
                 dp[i][j] = dp[i+1][j-1]+2;
             } else {
                 dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
             }
         }
     }
     return dp[0][n-1];
 }
