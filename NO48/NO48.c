//
//  NO48.c
//  NO48
//
//  Created by wanyakun on 2020/12/21.
//

#include "NO48.h"

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    // 交互图象的1/4，防止重复交换
    for(int i = 0; i < matrixSize/2; i++) {
        for(int j = 0; j < (matrixSize+1)/2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize-j-1][i];
            matrix[matrixSize-j-1][i] = matrix[matrixSize-i-1][matrixSize-j-1];
            matrix[matrixSize-i-1][matrixSize-j-1] = matrix[j][matrixSize-i-1];
            matrix[j][matrixSize-i-1] = tmp;
        }
    }
}

#pragma mark - 方案二
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate1(int** matrix, int matrixSize, int* matrixColSize){
    // 水平翻转
    for(int i = 0; i < matrixSize/2; i++) {
        for(int j = 0; j < matrixSize; j++) {
            swap(&matrix[i][j], &matrix[matrixSize-i-1][j]);
        }
    }
    // 主对角线翻转
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}
