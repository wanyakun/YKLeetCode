//
//  Tencent0002.c
//  Tencent0002
//
//  Created by wanyakun on 2020/12/11.
//

#include "Tencent0002.h"
#include <string.h>

bool checkConflict(int** arr, int arrSize, int* arrColSize) {
    if (arrSize <= 0) {
        return false;
    }
    int len = arrColSize[0];
    // 计算每行
    for (int i = 0; i < arrSize; i++) {
        int currRowSum = 0;
        for (int j = 0; j < len; j++) {
            currRowSum += arr[i][j];
        }
        if (currRowSum > 1) {
            return true;
        }
    }
    // 计算每列
    for (int j = 0; j < len; j++) {
        int currColSum = 0;
        for (int i = 0; i < arrSize; i++) {
            currColSum += arr[i][j];
        }
        if (currColSum > 1) {
            return true;
        }
    }
    
    return false;
}

//bool checkConflict1(int** arr, int arrSize, int* arrColSize) {
//    if (arrSize <= 0) {
//        return false;
//    }
//    int m = arrSize;
//    int n = arrColSize[0];
//    int dp[m][n];
//    memset(dp, 0, sizeof(dp));
//    //base case
//    for (int i =0; i < m; i++) {
//        dp[i][0] += arr[i][0];
//    }
//    for (int j = 0; j < n; j++) {
//        dp[0][j] += arr[0][j];
//    }
//    for (int i = 1; i < m; i++) {
//        for (int j = 1; j < n; j++) {
//            dp[i][j] = dp[i-1][j] + dp[i][j-1];
//        }
//    }
//
//    return dp[m-1][m-1] > 1;
//}
