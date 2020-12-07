//
//  NO861.c
//  NO861
//
//  Created by wanyakun on 2020/12/7.
//

#include "NO861.h"
#include <math.h>

int matrixScore(int** A, int ASize, int* AColSize){
    int m = ASize, n = AColSize[0]; // m行，n列
    int res = m*(1<<(n-1)); // 所有行首列都翻转成1；
    // 从第1列开始计算每列的内容
    for(int j =1; j < n; j++) {
        int nOnes = 0; // 代表当前列1的个数
        for(int i = 0; i < m; i++) {
            //  如果当前行第一列为1，说明此行没翻转，否则说明翻转过
            if(A[i][0] == 1) {
                nOnes += A[i][j];
            } else {
                nOnes += (1-A[i][j]);
            }
        }
        // 根据1的个数决定当前列是否要翻转
        int k = fmax(nOnes, m-nOnes);
        res += k * (1<<(n-j-1));
    }
    return res;

}
