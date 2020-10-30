//
//  NO463.c
//  NO463
//
//  Created by wanyakun on 2020/10/30.
//

#include "NO463.h"

// 陆地格子的边为边界或者相邻的为水的时候需要加一

// 用于取当前格子左、上、右下格子使用
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int rowSize = gridSize;
    int columSize = gridColSize[0];
    int result = 0;
    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < columSize; j++) {
            if (grid[i][j]) {
                // 计算四条边
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    // 边界或者相邻为水的边需要被计算周长
                    if (tx < 0 || tx >= rowSize || ty < 0 || ty >= columSize || !grid[tx][ty]) {
                        result++;
                    }
                }
            }
        }
    }
    return result;
}


// 递归方案
int dfs(int i, int j, int** grid, int rowSize, int columSize) {
    if (i < 0 || i >= rowSize || j < 0 || j >= columSize || grid[i][j] == 0) {
        return 1;
    };
    if (grid[i][j] == -1) {
        return 0;
    }
    grid[i][j] = -1;
    int res = 0;
    for (int k = 0; k < 4; k++) {
        int tx = i + dx[k];
        int ty = j + dy[k];
        res += dfs(tx, ty, grid, rowSize, columSize);
    }
    return res;
}

int islandPerimeter1(int** grid, int gridSize, int* gridColSize){
    int rowSize = gridSize;
    int columSize = gridColSize[0];
    int result = 0;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < columSize; j++) {
            if (grid[i][j] == 1) {
                result += dfs(i, j, grid, rowSize, columSize);
            }
        }
    }
    return result;
}
