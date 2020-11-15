//
//  NO1288.c
//  NO1288
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO1288.h"
#include <stdlib.h>

int cmp(const void* _a, const void* _b) {
    int* a = *(int**)_a;
    int* b = *(int**)_b;
    return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int left = intervals[0][0];
    int right = intervals[0][1];
    int res = 0;
    for(int i = 1; i < intervalsSize; i++) {
        // 区间覆盖
        if(left <= intervals[i][0] && right >= intervals[i][1]) {
            res++;
        }
        // 区间相交，合并区间
        if(right >= intervals[i][0] && right <= intervals[i][1]) {
            right = intervals[i][1];
        }
        // 区间无交集，更新left和right
        if(right < intervals[i][0]) {
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    return intervalsSize - res;

}
