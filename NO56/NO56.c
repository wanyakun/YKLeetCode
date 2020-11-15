//
//  NO56.c
//  NO56
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO56.h"
#include <stdlib.h>

int cmp(const void* _a, const void* _b) {
     int* a = *(int**)_a;
     int* b = *(int**)_b;
     return a[0] - b[0];
 }
 int max(int a, int b) {
     return a > b ? a : b;
 }
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if(intervalsSize == 0) return intervals;
    *returnSize = 1;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int** res = malloc(intervalsSize*sizeof(int*));
    (*returnColumnSizes) = malloc(intervalsSize*sizeof(int));
    res[0] = intervals[0];
    (*returnColumnSizes)[0] = 2;
    for(int i = 1; i < intervalsSize; i++) {
        int* last = res[(*returnSize)-1];
        int* curr = intervals[i];
        if(curr[0] <= last[1]) {
            last[1] = max(curr[1], last[1]);
        } else {
            (*returnSize)++;
            res[(*returnSize)-1] = curr;
            (*returnColumnSizes)[(*returnSize)-1] = 2;

        }
    }
    return res;
}
