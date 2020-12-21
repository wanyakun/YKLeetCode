//
//  main.c
//  NO48
//
//  Created by wanyakun on 2020/12/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO48.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int** matrix = malloc(3*sizeof(int*));
    matrix[0] = malloc(3*sizeof(int));
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    
    matrix[1] = malloc(3*sizeof(int));
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    
    matrix[2] = malloc(3*sizeof(int));
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    int matrixColSize[3] = {3,3,3};
    
    rotate(matrix, 3, matrixColSize);
    
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("] \n");
    }
    
    return 0;
}
