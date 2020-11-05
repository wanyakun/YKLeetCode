//
//  NO51.c
//  NO51
//
//  Created by wanyakun on 2020/11/5.
//

#include "NO51.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char** board, int row, int col, int n) {
    // 检查列是否有皇后
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') return false;
    }
    // 检查右上方是否有皇后
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }
    // 检查左上方是否有皇后
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }
    return true;
}

void backtrack(char*** res, int *returnSize, char** board, int n, int row) {
    // 触发结束条件
    if (row == n) {
        res = realloc(res, (++(*returnSize))*sizeof(char**));
//        char** tmp = malloc(n*sizeof(char*));
//        memcpy(tmp, board, n*n*sizeof(char));
        res[(*returnSize) - 1] = board;
        return;
    }
    for (int col = 0; col < n; col++) {
        // 排除不合理选择
        if(!isValid(board, row, col, n)) continue;
        // 做选择
        board[row][col] = 'Q';
        // 进入下一行决策
        backtrack(res, returnSize, board, n, row+1);
        // 撤销选择
        board[row][col] = '.';
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char*** res = malloc(0);
    *returnSize = 0;

    char** board = malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++) {
        board[i] = malloc(n*sizeof(char));
        memset(board[i], '.', n*sizeof(char));
    }
    backtrack(res, returnSize, board, n, 0);
    *returnColumnSizes = malloc((*returnSize)*sizeof(int));
    memset((*returnColumnSizes), n , (*returnSize)*sizeof(n));
    return res;
}
