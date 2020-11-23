//
//  NO63.c
//  NO63
//
//  Created by wanyakun on 2020/11/23.
//

#include "NO63.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    // base case
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    if(m <= 0 || n <= 0 || obstacleGrid[0][0] == 1) return 0;
    // 状态
    int dp[m][n];
    // 初始化
    dp[0][0] = 1;
    for(int i = 1; i < m; i++) {
        // 当前是障碍物，或者前面遇到过障碍物，都为0
        if(obstacleGrid[i][0] == 1 || dp[i-1][0] == 0) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = 1;
        }
    }
    for(int i = 1; i < n; i++) {
        // 当前是障碍物，或者前面遇到过障碍物，都为0
        if(obstacleGrid[0][i] == 1 || dp[0][i-1] == 0) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = 1;
        }
    }
    // 选择
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
