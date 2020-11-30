//
//  NO435.c
//  NO435
//
//  Created by wanyakun on 2020/11/30.
//

#include "NO435.h"
#include <stdlib.h>

int cmp(const void * _a, const void * _b) {
    int* a = *(int **)_a;
    int* b = *(int **)_b;
    return a[1] - b[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize <= 1) return 0;
    int res = 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int end = intervals[0][1];
    for(int i = 1; i < intervalsSize; i++) {
        int* interval = intervals[i];
        if(interval[0] >= end) {
            end = interval[1];
        } else {
            res++;
        }
    }
    return res;
}
