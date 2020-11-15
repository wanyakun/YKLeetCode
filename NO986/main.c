//
//  main.c
//  NO986
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO986.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int** A = malloc(4*sizeof(int*));
    A[0] = malloc(2*sizeof(int));
    A[0][0] = 0;
    A[0][1] = 2;
    A[1] = malloc(2*sizeof(int));
    A[1][0] = 5;
    A[1][1] = 10;
    A[2] = malloc(2*sizeof(int));
    A[2][0] = 13;
    A[2][1] = 23;
    A[3] = malloc(2*sizeof(int));
    A[3][0] = 24;
    A[3][1] = 25;
    int AColSize[4] = {2,2,2,2};
    
    int** B = malloc(4*sizeof(int*));
    B[0] = malloc(2*sizeof(int));
    B[0][0] = 1;
    B[0][1] = 5;
    B[1] = malloc(2*sizeof(int));
    B[1][0] = 8;
    B[1][1] = 12;
    B[2] = malloc(2*sizeof(int));
    B[2][0] = 15;
    B[2][1] = 24;
    B[3] = malloc(2*sizeof(int));
    B[3][0] = 25;
    B[3][1] = 26;
    int BColSize[4] = {2,2,2,2};

    int returnSize;
    int *returnColumnSize;
    int** res = intervalIntersection(A, 4, AColSize, B, 4, BColSize, &returnSize, &returnColumnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSize[i]; j++) {
            int num = res[i][j];
            printf("%d, ", num);
        }
        printf("]");
    }
    printf("] \n");
    
    return 0;
}
