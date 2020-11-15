//
//  main.c
//  NO1288
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO1288.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int** intervals = malloc(3*sizeof(int*));
    intervals[0] = malloc(2*sizeof(int));
    intervals[0][0] = 1;
    intervals[0][1] = 4;
    intervals[1] = malloc(2*sizeof(int));
    intervals[1][0] = 3;
    intervals[1][1] = 6;
    intervals[2] = malloc(2*sizeof(int));
    intervals[2][0] = 2;
    intervals[2][1] = 8;
    int intervalsColSize[3] = {2,2,2};
    int res = removeCoveredIntervals(intervals, 3, intervalsColSize);
    printf("%d \n", res);
    return 0;
}
