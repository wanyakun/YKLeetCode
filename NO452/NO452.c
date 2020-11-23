//
//  NO452.c
//  NO452
//
//  Created by wanyakun on 2020/11/23.
//

#include "NO452.h"
#include <stdlib.h>

int cmp(const void *_a, const void *_b) {
    int* a = *(int**)_a;
    int* b = *(int**)_b;
    return a[1] < b[1] ? -1 : 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    // base case
    if(pointsSize == 0) return 0;
    qsort(points, pointsSize, sizeof(int*), cmp);
    int pos = points[0][1];
    int res = 1;
    for(int i = 0; i < pointsSize; i++) {
        if(points[i][0] > pos) {
            pos = points[i][1];
            res++;
        }
    }
    return res;
}
