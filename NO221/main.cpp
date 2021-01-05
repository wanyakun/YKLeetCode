//
//  main.cpp
//  NO221
//
//  Created by wanyakun on 2021/1/5.
//
/**
 221. 最大正方形
 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

  

 示例 1：


 输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 输出：4
 示例 2：


 输入：matrix = [["0","1"],["1","0"]]
 输出：1
 示例 3：

 输入：matrix = [["0"]]
 输出：0
  

 提示：

 m == matrix.length
 n == matrix[i].length
 1 <= m, n <= 300
 matrix[i][j] 为 '0' 或 '1'

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        // dp[i][j] 标示以点i,j位右下角的正方形最大边长
        int maxSide = 0;
        int rows= matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        // base case
        dp[0][0] = 0;
        // 状态转移
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
                
            }
        }
        int maxSquare = maxSide*maxSide;
        return maxSquare;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
