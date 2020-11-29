//
//  NO1143.c
//  NO1143
//
//  Created by wanyakun on 2020/11/29.
//

#include "NO1143.h"
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}
// 动态规划+状态压缩
int longestCommonSubsequence(char * text1, char * text2){
    int m = strlen(text1);
    int n = strlen(text2);
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= m; i++) {
        int pre = 0;
        for(int j = 1; j <= n; j++) {
            // 下标从0开始，所以需要减一
            int tmp = dp[j];
            if(text1[i-1] == text2[j-1]) {
                // text1[i-1] 和 text2[j-1] 在lcs中
                dp[j] = 1 + pre;//dp[j-1];
            } else {
                // text1[i-1] 和text2[j-1]至少一个不在lcs中
                dp[j] = max(dp[j], dp[j-1]);
            }
            pre = tmp;
        }
    }
    return dp[n];

}
// 动态规划
 int longestCommonSubsequence1(char * text1, char * text2){
     // lcs为公共子序列
     // 定义text1[0...i-1], text2[0..j-1]的lcs为dp[i][j]
     // 目标text1[0...m-1], text2[0..n-1]的lcs为dp[m][n]
     // base case dp[0][..] = dp[..][0] = 0
     int m = strlen(text1);
     int n = strlen(text2);
     int dp[m+1][n+1];
     memset(dp, 0, sizeof(dp));
     for(int i = 1; i <= m; i++) {
         for(int j = 1; j <= n; j++) {
             // 下标从0开始，所以需要减一
             if(text1[i-1] == text2[j-1]) {
                 // text1[i-1] 和 text2[j-1] 在lcs中
                 dp[i][j] = 1 + dp[i-1][j-1];
             } else {
                 // text1[i-1] 和text2[j-1]至少一个不在lcs中
                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
         }
     }
     return dp[m][n];
 }
