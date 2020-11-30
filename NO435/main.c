//
//  main.c
//  NO435
//
//  Created by wanyakun on 2020/11/30.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO435.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int** intervals = malloc(4*sizeof(int*));
    intervals[0] = malloc(2*sizeof(int));
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1] = malloc(2*sizeof(int));
    intervals[1][0] = 2;
    intervals[1][1] = 3;
    intervals[2] = malloc(2*sizeof(int));
    intervals[2][0] = 3;
    intervals[2][1] = 4;
    intervals[3] = malloc(2*sizeof(int));
    intervals[3][0] = 1;
    intervals[3][1] = 3;
    
    int intervalsColSize[4] = {2,2,2,2};
    int res = eraseOverlapIntervals(intervals, 4, intervalsColSize);
    printf("%d \n", res);
    return 0;
}
