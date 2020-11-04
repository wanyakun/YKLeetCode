//
//  NO57.c
//  NO57
//
//  Created by wanyakun on 2020/11/4.
//

#include "NO57.h"
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void add(int** res, int* returnColumnSizes, int* returnSize, int left, int right) {
    int n = ++(*returnSize);
    returnColumnSizes[n-1] = 2;
    res[n-1] = malloc(2*sizeof(int));
    res[n-1][0] = left;
    res[n-1][1] = right;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    // base case
    if (intervals == NULL && newInterval == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    // 存储返回结果
    int** res = malloc((intervalsSize+1)*sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = malloc((intervalsSize+1)*sizeof(int));
    bool isAdd = false;
    for(int i = 0; i < intervalsSize; i++) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        if(right < newInterval[0]) {
            // 区间在新区间左侧，直接加入到结果
            add(res, *returnColumnSizes, returnSize, left, right);
        } else if (left > newInterval[1]) {
            // 区间在新区间右侧，插入新区间，然后插入
            if(isAdd == false) {
                add(res, *returnColumnSizes, returnSize, newInterval[0], newInterval[1]);
                isAdd = true;
            }
            add(res, *returnColumnSizes, returnSize, left, right);
        } else {
            // 区间与新区间有交集，合并为新区间
            newInterval[0] = min(left, newInterval[0]);
            newInterval[1] = max(right, newInterval[1]);
        }
    }
    // 循环完也没添加，最后添加新区间
    if (!isAdd) {
        add(res, *returnColumnSizes, returnSize, newInterval[0], newInterval[1]);
    }
    return res;
}
