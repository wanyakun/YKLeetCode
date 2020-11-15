//
//  main.c
//  NO56
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include "NO56.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int** intervals = malloc(3*sizeof(int*));
    intervals[0] = malloc(2*sizeof(int));
    intervals[0][0] = 1;
    intervals[0][1] = 3;
    intervals[1] = malloc(2*sizeof(int));
    intervals[1][0] = 2;
    intervals[1][1] = 6;
    intervals[2] = malloc(2*sizeof(int));
    intervals[2][0] = 8;
    intervals[2][1] = 10;
    intervals[3] = malloc(2*sizeof(int));
    intervals[3][0] = 15;
    intervals[3][1] = 18;
    
    int intervalsColSize[4] = {2,2,2,2};
    int returnSize;
    int *returnColumnSize;
    int** res = merge(intervals, 4, intervalsColSize, &returnSize, &returnColumnSize);
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
