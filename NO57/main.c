//
//  main.c
//  NO57
//
//  Created by wanyakun on 2020/11/4.
//

#include <stdio.h>
#include "NO57.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int** intervals = malloc(2*sizeof(int*));
    intervals[0] = malloc(2*sizeof(int));
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    
    intervals[1] = malloc(2*sizeof(int));
    intervals[1][0] = 3;
    intervals[1][1] = 5;
    
    intervals[2] = malloc(2*sizeof(int));
    intervals[2][0] = 6;
    intervals[2][1] = 7;
    
    intervals[3] = malloc(2*sizeof(int));
    intervals[3][0] = 8;
    intervals[3][1] = 10;
    
    intervals[4] = malloc(2*sizeof(int));
    intervals[4][0] = 12;
    intervals[4][1] = 16;
    
    int* intervalsColSize = malloc(5*sizeof(int));
    intervalsColSize[0] = 2;
    intervalsColSize[1] = 2;
    intervalsColSize[2] = 2;
    intervalsColSize[3] = 2;
    intervalsColSize[4] = 2;

    
    int* newIntervals = malloc(2*sizeof(int));
    newIntervals[0] = 4;
    newIntervals[1] = 8;
    
    int returnSize = 0;
    int* returnColumnSizes;

    
    int** res = insert(intervals, 5, intervalsColSize, newIntervals, 2, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for(int j = 0; j < returnColumnSizes[i]; j++) {
            int num = res[i][j];
            printf("%d ", num);
        }
        printf("] \n");
    }
    
    return 0;
}
